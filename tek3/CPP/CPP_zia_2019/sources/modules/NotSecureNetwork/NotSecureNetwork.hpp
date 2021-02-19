#ifndef CPP_ZIA_2019_NOTSECURENETWORK_HPP
#define CPP_ZIA_2019_NOTSECURENETWORK_HPP

#include <deque>
#include <module/ANetwork.hpp>
#include <ModuleLoggable.hpp>
#include "../../socket/SocketTCP.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "Atomic.hpp"

class NotSecureNetwork : public api::module::ANetwork, public ModuleLoggable {
public:
    ~NotSecureNetwork() override;
    NotSecureNetwork();
    NotSecureNetwork(const NotSecureNetwork &) = delete;
    NotSecureNetwork &operator=(const NotSecureNetwork &) = delete;

    api::String getName() const override {return "NotSecureNetwork";}

    bool startServing() override;
    void stopServing() override;
    bool isRunning() const override {return _running;}

    void setModules(const std::vector<api::module::AHttp *> &modules) override;
    void setLogger(api::module::ALogger *logger) override;
    void setConfig(const api::JsonObject &config) override;

private:
    void loopServing(std::shared_ptr<SocketTCP>);
    void acceptConnection(std::pair<SOCKET, api::IpV4>);
    void loopRequest(std::shared_ptr<api::http::ISocket>);

    Atomic<bool> _running;
    std::unique_ptr<Thread<>> _thread;

    std::vector<api::module::AHttp *> _modules;
    api::module::ALogger *_logger;
    api::JsonObject _config;

    std::deque<std::pair<std::shared_ptr<api::http::ISocket>, std::unique_ptr<Thread<>>>> _pool;
};


#endif /* CPP_ZIA_2019_NOTSECURENETWORK_HPP */
