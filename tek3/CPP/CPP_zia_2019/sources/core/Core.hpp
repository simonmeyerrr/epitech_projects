#ifndef CPP_ZIA_2019_CORE_HPP
#define CPP_ZIA_2019_CORE_HPP

#include <queue>

#include "SharedMutex.hpp"
#include "Atomic.hpp"
#include "Types.hpp"
#include "ModulesManager.hpp"

class Core {
public:
    ~Core() = default;
    Core(int const, char const **) noexcept;
    Core(const Core &) = delete;
    Core &operator=(const Core &) = delete;

    void reader() noexcept;
    void run();
    static std::string getWord() noexcept;
    static void wait(std::size_t const) noexcept;

    static std::function<bool(std::string const &, std::string const &)> _cmp;
    static std::function<std::string(std::string const &)> _low, _up;

private:
    void exit();
    void print();
    void load();
    void reload();
    void save();
    void modify();
    void start();
    void stop();
    void restart();

    static void help(Core &) noexcept;

    SharedMutex _cfgMtx, _cmdsMtx, _coreMtx;
    api::module::ALogger *_loggerModule;
    api::module::ANetwork *_networkModule;
    std::vector<api::module::AHttp *> _httpModules;
    Atomic<bool> _exit = false;
    std::unordered_map<std::string, std::function<void(void)>> _core;
    api::JsonType _cfg;
    std::string _oldCfg = "__NONE__", _bin;
    std::queue<std::string> _commands;
    bool _paramsCmd = false;
    std::unique_ptr<ModulesManager> _modules;
};

#endif /* CPP_ZIA_2019_CORE_HPP */
