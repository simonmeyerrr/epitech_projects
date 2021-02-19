#ifndef CPP_ZIA_2019_PHPCGI_HPP
#define CPP_ZIA_2019_PHPCGI_HPP

#ifndef WIN32

#include <ModuleLoggable.hpp>
#include "module/AHttp.hpp"
#include <string>
#include <vector>
#include "../../socket/SocketTCP.hpp"

class PhpCgi : public api::module::AHttp, public ModuleLoggable {
public:
    ~PhpCgi() override = default;
    PhpCgi();

    bool handle(Connection &connection) override final;

    void setConfig(const api::JsonObject &config) override;
    void setLogger(api::module::ALogger *logger) override;

    api::String getName() const override {return "PhpCgi";}

private:
    const char **setEnv(Connection &);    

    int exec(const char *path, char *const argv[], char *const envp[]);            
    int setResponse(Connection &connection, SOCKET sock);
    bool isPhpFile(std::string uri);


    std::string _bin;
    std::string _path;
    std::vector<std::string> _interpreted;

};

#endif

#endif /* CPP_ZIA_2019_PHPCGI_HPP */
