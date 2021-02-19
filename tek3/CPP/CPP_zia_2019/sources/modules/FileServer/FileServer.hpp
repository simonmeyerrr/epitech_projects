#ifndef CPP_ZIA_2019_FILESERVER_HPP
#define CPP_ZIA_2019_FILESERVER_HPP

#include "../../api/sources/module/AHttp.hpp"
#include "../../api/sources/Types.hpp"
#include <ModuleLoggable.hpp>

class FileServer : public api::module::AHttp, public ModuleLoggable {
public:
    // Constructors
    ~FileServer() override = default;
    FileServer() = default;
    FileServer(const FileServer &) = delete;
    FileServer &operator=(const FileServer &) = delete;

    // Getters & Setters
    api::String getName() const override {return "FileServer";}
    void setLogger(api::module::ALogger *) override;
    void setConfig(const api::JsonObject &) override;

    // Methods
    bool handle(Connection &) override final;

private:
    api::String _url = ".";
    api::module::ALogger *_logger = nullptr;
    api::JsonObject _config;
};

#endif /* CPP_ZIA_2019_FILESERVER_HPP */
