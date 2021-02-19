#ifndef WIN32

#include "PhpCgi.hpp"
#include <map>
#include <functional>
#include <unistd.h>
#include <sys/wait.h>
#include <filesystem>
#include <iostream>

MODULE_EXPORTER(PhpCgi)

std::function<std::string(std::string const &)> _up = [](std::string const &f){std::string s = f; std::for_each(s.begin(), s.end(), [](char &s){s = toupper(s);}); return s;};

PhpCgi::PhpCgi()
{    
}

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

const char **PhpCgi::setEnv(Connection &connection) {    
    std::map<std::string, std::string> env;    
    const api::Headers &head = connection.req->getHeaders();        
    std::string uri = connection.req->getUri();    

    if (uri.find('?') != std::string::npos) {        
        env["QUERY_STRING"] = uri.substr(uri.find('?') + 1, uri.size());
        uri = uri.substr(0, uri.find('?'));
    }
    env["DOCUMENT_ROOT"] = std::string(_path);
    env["GATEWAY_INTERFACE"] = std::string("CGI/1.1");
    env["PATH"] = std::string(std::string(std::getenv("PATH")));    
    #ifdef WIN32
	    struct in_addr addr;
	    addr.S_un.S_addr = ip;
	    std::string ip(inet_ntoa(connection.socket->getTargetIp()));
        env["REMOTE_ADDR"] = std::string(ip);
    #else
        std::string ip(inet_ntoa({ connection.socket->getTargetIp() }));
        env["REMOTE_ADDR"] = std::string(ip);
    #endif    
    env["REQUEST_METHOD"] = std::string(connection.req->getMethod());
    env["REDIRECT_STATUS"] = std::string("true");
    env["REQUEST_URI"] = std::string(uri);    
    if (uri == "/") {
        env["SCRIPT_FILENAME"] = std::string(_path + "index.php");    
        env["SCRIPT_NAME"] = std::string(_path + "index.php");    
    } else {        
        env["SCRIPT_FILENAME"] = std::string(_path.substr(0, _path.size() - 1) + uri);    
        env["SCRIPT_NAME"] = std::string(uri);
    }
    env["SERVER_PROTOCOL"] = std::string(connection.req->getVersion());
    if (head.find("Host") != head.end())
        env["SERVER_ADDR"] = std::string(head.at("Host"));
    if (head.find("Host") != head.end())
        env["HTTP_HOST"] = std::string(head.at("Host"));
    if (head.find("Host") != head.end())
        env["SERVER_NAME"] = std::string(head.at("Host").substr(0, head.at("Host").find(':')));
    if (head.find("Host") != head.end())
        env["SERVER_PORT"] = std::string(head.at("Host").substr(head.at("Host").find(':') + 1, head.at("Host").size()));        
    if (head.find("Accept-Encoding") != head.end())
        env["HTTP_ACCEPT_ENCODING"] = std::string(head.at("Accept-Encoding"));
    if (head.find("Accept") != head.end())
        env["HTTP_ACCEPT"] = std::string(head.at("Accept"));
    if (head.find("Referer") != head.end())
        env["HTTP_REFERER"] = std::string(head.at("Referer"));
    if (head.find("Connection") != head.end())
        env["HTTP_CONNECTION"] = std::string(head.at("Connection"));
    if (head.find("Sec-Fetch-User") != head.end())
        env["HTTP_SEC_FETCH_USER"] = std::string(head.at("Sec-Fetch-User"));
    if (head.find("Sec-Fetch-Dest") != head.end())
        env["HTTP_SEC_FETCH_DEST"] = std::string(head.at("Sec-Fetch-Dest"));
    if (head.find("Content-Type") != head.end()) {
        env["CONTENT_TYPE"] = std::string(head.at("Content-Type"));
        env["HTTP_CONTENT_TYPE"] = std::string(head.at("Content-Type"));
    }
    if (head.find("Content-Length") != head.end()) {
        env["CONTENT_LENGTH"] = std::string(head.at("Content-Length"));
        env["HTTP_CONTENT_LENGTH"] = std::string(head.at("Content-Length"));
    }        
    if (head.find("User-Agent") != head.end())
        env["HTTP_USER_AGENT"] = std::string(head.at("User-Agent"));
    if (head.find("Cache-Control") != head.end())
        env["HTTP_CACHE_CONTROL"] = std::string(head.at("Cache-Control"));
    if (head.find("Accept-Language") != head.end())
        env["HTTP_ACCEPT_LANGUAGE"] = std::string(head.at("Accept-Language"));
    if (head.find("Upgrade-Insecure-Requests") != head.end())
        env["HTTP_UPGRADE_INSECURE_REQUESTS"] = std::string(head.at("Upgrade-Insecure-Requests"));
    if (head.find("Sec-Fetch-Site") != head.end())
        env["HTTP_SEC_FETCH_SITE"] = std::string(head.at("Sec-Fetch-Site"));
    if (head.find("Origin") != head.end())
        env["HTTP_ORIGIN"] = std::string(head.at("Origin"));
    if (head.find("Sec-Fetch-Mode") != head.end())
        env["HTTP_SEC_FETCH_MODE"] = std::string(head.at("Sec-Fetch-Mode"));
    env["SERVER_SOFTWARE"] = "PHP CGI Development Server";
   
    std::size_t i = 0;

	const char **arr = new const char *[env.size() + 1];
	for (auto j = env.begin(); j != env.end(); ++j) {        
        std::string hdr = j->first + "=" + j->second;
		int size = hdr.size();
		char *str = new char[size + 1];
		hdr.copy(str, size);
		str[size] = '\0';        
		arr[i++] = str;
        std::cout << "PhpCgi - Header Line: " << str << std::endl;
	}
	arr[i] = NULL;
    return arr;
}

bool PhpCgi::isPhpFile(std::string uri) {
    if (!uri.empty() && uri.size() > 4) {
        if (uri.find('?') != std::string::npos)
            uri = uri.substr(0, uri.find('?'));
        std::string ext = uri.substr(uri.size() - 4, uri.size());
        for (auto const& authorized : _interpreted)            
            if (ext == authorized)
                return true;        
    } else if (uri.size() == 1 && uri == "/")
        return true;
    return false;
}

int PhpCgi::exec(const char *path, char *const argv[], char *const envp[]) {
    return execve(path, argv, envp);
}

int PhpCgi::setResponse(Connection &connection, SOCKET sock) {
    SocketTCP socket(sock, 0);    
    int status = 200;
    api::Buffer buff = socket.recvPacket();
    std::string line = std::string(buff.begin(), buff.end());
    
    while (socket.isOpen() && line != "\r\n") {           
        if (line.find("Status:") != std::string::npos) {
            status = std::stoi(line.substr(8, 3));
        }            
        // Gerer la ligne de header
        buff = socket.recvPacket();
        line = std::string(buff.begin(), buff.end());
    }
    api::Buffer body;
    while (socket.isOpen() && !buff.empty()) {
        buff = socket.recvPacket(1);
        if (buff.size() == 1)
            body.emplace_back(buff[0]);
    }
    connection.res->setBody(body);
    return status;
}

bool PhpCgi::handle(Connection &connection) {
    if (connection.res->getStatus() == 400)
        return true;
    if (!this->isPhpFile(connection.req->getUri()))
        return true;
    int fildes[2];    
    pipe(fildes);
    pid_t pid = fork();    

    if (pid < 0) {
        connection.res->setStatus(500);
        close(fildes[0]);
        close(fildes[1]);
        return true;
    } else if (pid == 0) {
        const char *av[] = {_bin.c_str(), NULL};        
        const char **env = this->setEnv(connection);                
        dup2(fildes[0], 0);
        close(fildes[0]);
        dup2(fildes[1], 1);
        close(fildes[1]);
        int exe = 0;
        std::cout << "PhpCgi - Start child process" << std::endl;
        exe = this->exec(_bin.c_str(), const_cast<char * const *> (av),  const_cast<char * const *> (env));                                
        for (std::size_t i = 0; env[i] != NULL; ++i)
            delete(env[i]);
        delete(env);
        exit(exe);
    } else {
        int status;        
        api::Buffer bdy = connection.req->getBody();        
        std::string body(bdy.begin(), bdy.end());
        write(fildes[1], body.c_str(), body.size());
        close(fildes[1]);
        std::cout << "PhpCgi - Wait child process .." << std::endl;
        waitpid(pid, &status, 0);        
        if (status < 0 || status == 65280) {
            connection.res->setStatus(500);
        } else {
            connection.res->setStatus(setResponse(connection, fildes[0]));
        }
    }
    return true;
}

void PhpCgi::setConfig(const api::JsonObject &config) {
    _bin = "/usr/bin/php-cgi";
    _path = "/var/www/website";
    _interpreted = {".php"};
    try {
        std::wstring bin = config.at(L"bin").as<api::JsonString>();        
        _bin = std::string(bin.begin(), bin.end());        
    } catch (...) {}
    try {
        std::wstring path = config.at(L"files").as<api::JsonString>();
        std::filesystem::path p = std::filesystem::path(std::string(path.begin(), path.end()));
        _path = std::string(std::filesystem::absolute(p));        
    } catch(...) {}
    try {
        api::JsonArray interpreted = config.at(L"interpreted").as<api::JsonArray>();
        for (auto const &in : interpreted) {
            auto tmp = in.as<api::JsonString>();            
            _interpreted.push_back(std::string(tmp.begin(), tmp.end()));
        }
    } catch(...) {}
    std::cout << "PhpCgi - Bin: " << _bin << std::endl;
    std::cout << "PhpCgi - Path: " << _path << std::endl;
}

void PhpCgi::setLogger(api::module::ALogger *logger) {
    updateLogger(logger);
}

#endif