#ifndef CPP_RTYPE_2019_UTILS_HPP
#define CPP_RTYPE_2019_UTILS_HPP

#include "ISocket.hpp"

namespace my_socket {

    class Utils {
    public:
        static void sleep(int milli_seconds);
        static std::string ipToStr(IpV4 ip);
        static IpV4 strToIp(const std::string &str);
        static void generateMyIp();
        static IpV4 getMyIp();
    };

}

#endif //CPP_RTYPE_2019_UTILS_HPP
