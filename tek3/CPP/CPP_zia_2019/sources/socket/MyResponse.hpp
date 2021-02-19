#ifndef CPP_ZIA_2019_MYRESPONSE_HPP
#define CPP_ZIA_2019_MYRESPONSE_HPP


#include <http/IResponse.hpp>

class MyResponse : public api::http::IResponse {
public:
    ~MyResponse() override = default;
    MyResponse() = default;

    api::Headers &getHeaders() override {return _headers;}
    const api::Headers &getHeaders() const override {return _headers;}

    api::Buffer &getBody() override {return _body;}
    const api::Buffer &getBody() const override {return _body;}
    void setBody(const api::Buffer &buffer) override {_body = buffer;}

    std::string getVersion() const override {return std::string("HTTP/") + std::to_string((unsigned int)_major) + "." + std::to_string((unsigned int)_minor);}
    void setVersion(unsigned char major, unsigned char minor) override {_major = major; _minor = minor;}

    int getStatus() const override {return _status;}
    void setStatus(int status) override {_status = status;}

    void clear() override {
        _headers.clear();
        _body.clear();
        _major = 1;
        _minor = 1;
        _status = 200;
    }

private:
    api::Headers _headers;
    api::Buffer _body;
    unsigned char _major = 1;
    unsigned char _minor = 1;
    int _status = 200;
};


#endif /* CPP_ZIA_2019_MYRESPONSE_HPP */
