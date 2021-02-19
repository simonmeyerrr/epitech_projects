#include <iostream>
#include "HttpSender.hpp"

MODULE_EXPORTER(HttpSender)

bool HttpSender::handle(api::module::AHttp::Connection &conn)
{
    bool alive = _alive;
    auto status = conn.res->getStatus();
    std::string line = conn.res->getVersion() + " " + getStatusMessage(status) + "\r\n";

    if (conn.req->getHeaders().find("Connection") != conn.res->getHeaders().end() && conn.req->getHeaders().at("Connection") != "Keep-Alive" && conn.req->getHeaders().at("Connection") != "keep-alive")
        alive = false;
    if (conn.res->getHeaders().find("Connection") != conn.res->getHeaders().end() && conn.res->getHeaders().at("Connection") == "close")
        alive = false;
    conn.socket->sendPacket(api::Buffer(line.begin(), line.end()));
    if (conn.res->getBody().size() != 0)
        conn.res->getHeaders()["Content-Length"] = std::to_string(conn.res->getBody().size());
    if (!alive)
        conn.res->getHeaders()["Connection"] = "close";
    else
        conn.res->getHeaders()["Connection"] = "keep-alive";
    for (const auto &header: conn.res->getHeaders()) {
        line = header.first + ": " + header.second + "\r\n";
        conn.socket->sendPacket(api::Buffer(line.begin(), line.end()));
    }
    line = "\r\n";
    conn.socket->sendPacket(api::Buffer(line.begin(), line.end()));
    if (conn.res->getBody().size() != 0)
        conn.socket->sendPacket(conn.res->getBody());
    if (!alive)
        conn.socket->closeSocket();
    log("Response " + std::to_string(conn.res->getStatus()));
    return true;
}

void HttpSender::setConfig(const api::JsonObject &config)
{
    try {
        _alive.store(config.at(L"alive").as<api::JsonBool>());
    } catch (...) {
        _alive.store(true);
    }
}

void HttpSender::setLogger(api::module::ALogger *logger)
{
    updateLogger(logger);
}

std::string HttpSender::getStatusMessage(int status)
{
    switch (status) {
        case 100: return "100 Continue";
        case 101: return "101 Switch Protocol";
        case 103: return "103 Processing";
        case 200: return "200 OK";
        case 201: return "201 Created";
        case 202: return "202 Accepted";
        case 203: return "203 Non-Authoritative Information";
        case 204: return "204 No Content";
        case 205: return "205 Reset Content";
        case 206: return "206 Partial Content";
        case 207: return "207 Multi-Status";
        case 208: return "208 Multi-Status";
        case 226: return "226 IM Used";
        case 300: return "300 Multiple Choice";
        case 301: return "301 Moved Permanently";
        case 302: return "302 Found";
        case 303: return "303 See Other";
        case 304: return "304 Not Modified";
        case 305: return "305 Use Proxy";
        case 306: return "306 unused";
        case 307: return "307 Temporary Redirect";
        case 308: return "308 Permanent Redirect";
        case 400: return "400 Bad Request";
        case 401: return "401 Unauthorized";
        case 402: return "402 Payment Required";
        case 403: return "403 Forbidden";
        case 404: return "404 Not Found";
        case 405: return "405 Method Not Allowed";
        case 406: return "406 Not Acceptable";
        case 407: return "407 Proxy Authentication Required";
        case 408: return "408 Request Timeout";
        case 409: return "409 Conflict";
        case 410: return "410 Gone";
        case 411: return "411 Length Required";
        case 412: return "412 Precondition Failed";
        case 413: return "413 Payload Too Large";
        case 414: return "414 URI Too Long";
        case 415: return "415 Unsupported Media Type";
        case 416: return "416 Requested Range Not Satisfiable";
        case 417: return "417 Expectation Failed";
        case 418: return "418 I'm a teapot";
        case 421: return "421 Misdirected Request";
        case 422: return "422 Unprocessable Entity";
        case 423: return "423 Locked";
        case 424: return "424 Failed Dependency";
        case 426: return "426 Upgrade Required";
        case 428: return "428 Precondition Required";
        case 429: return "429 Too Many Requests";
        case 431: return "431 Request Header Fields Too Large";
        case 451: return "451 Unavailable For Legal Reasons";
        case 500: return "500 Internal Server Error";
        case 501: return "501 Not Implemented";
        case 502: return "502 Bad Gateway";
        case 503: return "503 Service Unavailable";
        case 504: return "504 Gateway Timeout";
        case 505: return "505 HTTP Version Not Supported";
        case 506: return "506 Variant Also Negotiates";
        case 507: return "507 Insufficient Storage";
        case 508: return "508 Loop Detected";
        case 510: return "510 Not Extended";
        case 511: return "511 Network Authentication Required";
        default: return "418 I'm a teapot";
    }
}
