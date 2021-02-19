#ifndef CPP_ZIA_2019_HTTPRECEIVER_HPP
#define CPP_ZIA_2019_HTTPRECEIVER_HPP

#include <ostream>
#include <unordered_map>
#include <ModuleLoggable.hpp>
#include "../../api/sources/module/AHttp.hpp"

class HttpReceiver : public api::module::AHttp, public ModuleLoggable {
public:
    ~HttpReceiver() override = default;
    HttpReceiver();

    api::String getName() const override {return "HttpReceiver";}

    bool handle(Connection &connection) override final;
    bool parseHeader(const std::string &, Connection &connection);
    bool parseData(const std::string &, Connection &connection);

    void fillRequest(api::Buffer content, Connection &connection, unsigned int first_line);
    void setLogger(api::module::ALogger *logger) override;
    void setConfig(const api::JsonObject &config) override;
private:
    std::unordered_map<std::string, int> _method;
};

#endif /* CPP_ZIA_2019_HTTPRECEIVER_HPP */
