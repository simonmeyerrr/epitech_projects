#ifndef CPP_ZIA_2019_SECURENETWORK_HPP
#define CPP_ZIA_2019_SECURENETWORK_HPP

#include <atomic>
#include <mutex>
#include <thread>
#include <deque>
#include <module/ANetwork.hpp>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <ModuleLoggable.hpp>
#include "Thread.hpp"
#include "../../socket/SocketTCP.hpp"
#include "../../socket/SecureSocket.hpp"

class SecureNetwork : public api::module::ANetwork, public ModuleLoggable {
public:
    ~SecureNetwork() override;
    SecureNetwork();
    SecureNetwork(const SecureNetwork &) = delete;
    SecureNetwork &operator=(const SecureNetwork &) = delete;

    api::String getName() const override {return "SecureNetwork";}

    bool startServing() override;
    void stopServing() override;
    bool isRunning() const override {return _running;}

    void setModules(const std::vector<api::module::AHttp *> &modules) override;
    void setLogger(api::module::ALogger *logger) override;
    void setConfig(const api::JsonObject &config) override;

private:
    void loopServing(std::shared_ptr<SocketTCP>, SSL_CTX *);
    void acceptConnection(std::pair<SOCKET, api::IpV4>, SSL_CTX *ctx);
    void loopRequest(std::shared_ptr<SecureSocket>);

    std::atomic<bool> _running;
    std::unique_ptr<Thread<>> _thread;

    std::vector<api::module::AHttp *> _modules;
    api::module::ALogger *_logger;
    api::JsonObject _config;

    std::deque<std::pair<std::shared_ptr<api::http::ISocket>, std::unique_ptr<Thread<>>>> _pool;
};


#endif /* CPP_ZIA_2019_SECURENETWORK_HPP */
