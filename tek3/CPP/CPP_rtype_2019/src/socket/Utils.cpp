#include "Utils.hpp"
#include "SocketError.hpp"
#include "socket_c/Includes.hpp"

void my_socket::Utils::sleep(int milli_seconds) {
#ifdef WIN32
    Sleep(milli_seconds);
#else /* not WIN32 */
    usleep(milli_seconds * 1000);
#endif /* WIN32 */
}

std::string my_socket::Utils::ipToStr(IpV4 ip) {
#ifdef WIN32
	struct in_addr addr;
	addr.S_un.S_addr = ip;
	return std::string(inet_ntoa(addr));
#else
	return std::string(inet_ntoa({ ip }));
#endif
}

my_socket::IpV4 my_socket::Utils::strToIp(const std::string &str) {
    IpV4 ip = 0;

    if (inet_pton(AF_INET, str.c_str(), &ip) != 1) {
        throw SocketError(SocketError::BAD_ARGUMENT);
    }
    return ip;
}

static my_socket::IpV4 myIp = DEFAULT_IP;

#ifdef WIN32
void my_socket::Utils::generateMyIp()
{
    std::string ip("127.0.0.1");
    std::string line;
    std::ifstream file;
    std::string search("IPv4 Address. . . . . . . . . . . :");
    system("ipconfig > .tmp_ip.txt");
    file.open(".tmp_ip.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            std::getline(file, line);
            if (line.find(search) != std::string::npos) {
                line.erase(0, 39);
                ip = line;
                break;
            }
        }
        file.close();
    }
    system("rm .tmp_ip.txt");
    try {
        myIp = strToIp(ip);
    } catch (...) {
        myIp = DEFAULT_IP;
    }
}
#else
void my_socket::Utils::generateMyIp()
{
    IpV4 ip = DEFAULT_IP;
    struct ifaddrs *iflist;

    if (getifaddrs(&iflist) < 0) {
        myIp = DEFAULT_IP;
        return;
    }
    for (struct ifaddrs *iface = iflist; iface; iface = iface->ifa_next) {
        std::string interface(iface->ifa_name);
        if (iface->ifa_addr->sa_family == AF_INET &&
            interface.find("docker") == std::string::npos &&
            interface.find("virbr") == std::string::npos &&
            interface != "lo") {
            ip = ((struct sockaddr_in *)iface->ifa_addr)->sin_addr.s_addr;
            break;
        }
    }
    freeifaddrs(iflist);
    myIp = ip;
}
#endif

my_socket::IpV4 my_socket::Utils::getMyIp() {
    static bool first_time = true;

    if (first_time) {
        generateMyIp();
        first_time = false;
    }
    return myIp;
}