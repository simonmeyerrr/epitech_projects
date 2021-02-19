#ifndef CPP_ZIA_2019_MYREQUEST_HPP
#define CPP_ZIA_2019_MYREQUEST_HPP

#include <http/IRequest.hpp>

class MyRequest : public api::http::IRequest{
public:
    ~MyRequest() override = default;
    MyRequest() = default;

    api::Headers &getHeaders() override {return _headers;}
    const api::Headers &getHeaders() const override {return _headers;}

    api::Buffer &getBody() override {return _body;}
    const api::Buffer &getBody() const override {return _body;}
    void setBody(const api::Buffer &buffer) override {_body = buffer;}

    std::string getVersion() const override {return std::string("HTTP/") + std::to_string((unsigned int)_major) + "." + std::to_string((unsigned int)_minor);}
    void setVersion(unsigned char major, unsigned char minor) override {_major = major; _minor = minor;}

    api::String getMethod() const override {return _method;}
    void setMethod(const api::String &method) override {_method = method;}

    api::String getUri() const override {return _uri;}
    void setUri(const api::String &uri) override {_uri = uri;}

    void clear() override {
        _headers.clear();
        _body.clear();
        _major = 1;
        _minor = 1;
        _method = "";
        _uri = "";
    }

private:
    api::Headers _headers;
    api::Buffer _body;
    unsigned char _major = 1;
    unsigned char _minor = 1;
    api::String _method;
    api::String _uri;
};


#endif /* CPP_ZIA_2019_MYREQUEST_HPP */
