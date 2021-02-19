#ifndef CPP_ZIA_2019_HTTPSENDER_HPP
#define CPP_ZIA_2019_HTTPSENDER_HPP

#include <ModuleLoggable.hpp>
#include <module/AHttp.hpp>
#include <Atomic.hpp>

class HttpSender : public api::module::AHttp, public ModuleLoggable {
public:
    ~HttpSender() override = default;
    HttpSender() = default;

    api::String getName() const override {return "HttpSender";}

    bool handle(Connection &connection) override;

    void setLogger(api::module::ALogger *logger) override;
    void setConfig(const api::JsonObject &config) override;

private:
    static std::string getStatusMessage(int);
    Atomic<bool> _alive = true;
};


#endif /* CPP_ZIA_2019_HTTPSENDER_HPP */
