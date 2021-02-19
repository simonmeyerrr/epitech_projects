#include <string>
#include <regex>
#include <functional>
#include <iostream>
#include "HttpReceiver.hpp"

MODULE_EXPORTER(HttpReceiver)


std::function<bool(std::string const &, std::string const &)> _cmp = [](std::string const &f, std::string const &s) {
    return std::equal(f.cbegin(), f.cend(), s.cbegin(), s.cend(),
                      [](char const f, char const s) { return tolower(f) == tolower(s); });
};
std::function<std::string(std::string const &)> _low = [](std::string const &f) {
    std::string s = f;
    std::for_each(s.begin(), s.end(), [](char &s) { s = tolower(s); });
    return s;
};

std::function<std::string(std::string const &)> _up = [](std::string const &f) {
    std::string s = f;
    std::for_each(s.begin(), s.end(), [](char &s) { s = toupper(s); });
    return s;
};


HttpReceiver::HttpReceiver() : _method{{"GET",      0},
                                       {"POST",     1},
                                       {"PUT",      2},
                                       {"PATCH",    3},
                                       {"DELETE",   4},
                                       {"COPY",     5},
                                       {"HEAD",     6},
                                       {"OPTIONS",  7},
                                       {"LINK",     8},
                                       {"UNLINK",   9},
                                       {"PURGE",    10},
                                       {"LOCK",     11},
                                       {"UNLOCK",   12},
                                       {"PROPFIND", 13},
                                       {"VIEW",     14}}
{
}

bool HttpReceiver::parseHeader(const std::string &str, Connection &connection)
{
    std::regex header("(\\w+)\\s+(.*?)\\s+(.*)");
    std::regex http("([a-zA-Z]+)\\/(-?\\d).(-?\\d)");
    std::smatch m;
    std::string p;
    int major;
    int minor;

    if (std::regex_search(str, m, header)) {
        if (m.size() != 4)
            return false;
        if (_method.find(_up(m.str(1))) == _method.end())
            return false;
        else {
            p = m.str(1);
            connection.req->setMethod(p);
        }
        p = m.str(2);
        connection.req->setUri(p);
        if (std::regex_search(str, m, http)) {
            if (_cmp(m.str(1), "http") == 0)
                return false; // je parse le HTTP/1.1 et je check si http(case sensitive)
            p = m.str(2);
            major = std::stoi(p);
            p = m.str(3);
            minor = std::stoi(p);
            if (major < 0 || minor < 0 || (major == 0 && minor == 0) || (major == 1 && minor != 1) ||
                (major != 1 && minor == 1)) {
                std::string body = "Unsupported http version";
                connection.res->setBody({body.begin(), body.end()});
                return false;
            } else
                connection.res->setVersion(major, minor);
        }
    }
    return true;
}

// need to check les lignes une par une et envoier un msg d'errer avant de tout parser
bool HttpReceiver::parseData(const std::string &str, Connection &connection)
{
    std::regex data("([\\w-]+): (.*)");
    std::smatch m;
    std::string p;
    int major;
    int minor;

    if (std::regex_search(str, m, data)) {
        for (size_t i = 0;
             i < m.size(); ++i);                     // que dans m.str(1) = Host: m.str(2) = localhost
    }
    std::string key = m.str(1);
    std::string content = m.str(2);
    if (key == "" || content == "") {
        std::string body = "Invalid header";
        connection.res->setBody({body.begin(), body.end()});
        return false;
    }
    connection.req->getHeaders()[key] = content;
    return true;
}


void HttpReceiver::fillRequest(api::Buffer string, Connection &connection, unsigned int first_line)
{
    std::string str(string.begin(), string.end());
    if (first_line == 0) {
        if (!parseHeader(str, connection)) {
            connection.res->setStatus(400);
            connection.res->getHeaders()["Connection"] = "close";
        }
    } else {
        if (!parseData(str, connection)) {
            connection.res->setStatus(400);
            connection.res->getHeaders()["Connection"] = "close";
        }
    }
}

bool HttpReceiver::handle(Connection &connection)
{
    api::Buffer content;
    unsigned int first_line = 0;
    while (connection.socket->isOpen() && connection.res->getStatus() == 200) {
        content = connection.socket->recvPacket();
        if (content.size() == 2)
            break;
        else {
            fillRequest(content, connection, first_line);
            first_line++;
        }
    }

    if (connection.req->getHeaders().find("Content-Length") != connection.req->getHeaders().end()) {
        unsigned int len = std::stoi(connection.req->getHeaders()["Content-Length"]);
        connection.req->setBody(connection.socket->recvPacket(len));
    }
    log("Received request " + connection.req->getMethod() + " " + connection.req->getUri());
    return true;
}

void HttpReceiver::setLogger(api::module::ALogger *logger)
{
    updateLogger(logger);
}

void HttpReceiver::setConfig(const api::JsonObject &config)
{}
