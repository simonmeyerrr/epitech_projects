#include "Core.hpp"

#include "JsonParser.hpp"
#include "JsonBuilder.hpp"
#include "JsonPrinter.hpp"
#include "JsonVisitor.hpp"
#include "JsonModifier.hpp"
#include "Thread.hpp"

Core::Core(int const ac, char const **av) noexcept : _core{{"exit",    std::bind(&Core::exit, this)},
                                                           {"print",   std::bind(&Core::print, this)},
                                                           {"load",    std::bind(&Core::load, this)},
                                                           {"reload",  std::bind(&Core::reload, this)},
                                                           {"help",    [&]() { Core::help(*this); }},
                                                           {"save",    std::bind(&Core::save, this)},
                                                           {"modify",  std::bind(&Core::modify, this)},
                                                           {"start",   [&]() { this->_modules->start(); }},
                                                           {"restart", [&]() { this->_modules->restart(); }},
                                                           {"stop",    [&]() { this->_modules->stop(); }}}, _bin{*av}
{
    srand(static_cast<unsigned int>(time(nullptr) ^ (std::size_t)this));
    _modules = std::make_unique<ModulesManager>();
    bool first = true;
    std::string tmp;
    while (*++av) {
        if (first)
            _paramsCmd = true;
        first = false;
        tmp = *av;
        if (_cmp("--noexit", tmp) || _cmp("noexit", tmp) || _cmp("-n", tmp))
            _paramsCmd = false;
        else if (_cmp("--help", tmp) || _cmp("help", tmp) || _cmp("-h", tmp))
            _commands.push("help");
        else
            _commands.push(_low(tmp));
    }
    if (_paramsCmd)
        _commands.push("exit");
}

void Core::reader() noexcept
{
    std::size_t lockerSze;
    std::string command;
    while (!_exit) {
        do {
            {
                RLocker cmdsLck{_cmdsMtx};
                lockerSze = _commands.size();
            }
            wait(100);
        } while (lockerSze && !_exit);
        if (_exit)
            return;
        std::cout << "> ";
        command = getWord();
        {
            RLocker coreLck{_coreMtx};
//            if (_core.cend() == _core.find(command))
//                std::cerr << "Bad command > " << command << std::endl;
//            else {
            WLocker cmdsLck{_cmdsMtx};
            _commands.push(_low(command));
//            }
        }
    }
}

void Core::run()
{
    Thread<> readerThread{&Core::reader, this};
    std::string command;
    std::size_t lockerSze;
    while (!_exit) {
        {
            RLocker cmdsLck{_cmdsMtx};
            lockerSze = _commands.size();
        }
        if (lockerSze) {
            {
                WLocker cmdsLck{_cmdsMtx};
                command = _commands.front();
                _commands.pop();
            }
            {
                RLocker coreLck{_coreMtx};
                if (_core.cend() == _core.find(command))
                    std::cerr << "Bad command > " << command << std::endl;
                else
                    _core[command]();
            }
        } else
            wait(100);
    }
    readerThread.join();
}

std::string Core::getWord() noexcept
{
    std::string wrd;
    if (std::cin >> wrd)
        return wrd;
    else {
        std::cout << "exit" << std::endl;
        return "exit";
    }
}

void Core::wait(std::size_t const t) noexcept
{
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void Core::exit()
{
    _exit.store(true);
}

void Core::print()
{
    if ("__NONE__" == _oldCfg)
        std::cerr << "Cannot print > no loaded config " << _oldCfg << std::endl;
    else {
        RLocker lock{_cfgMtx};
        visitJson<JsonPrinter>(_cfg);
    }
}

void Core::load()
{
    std::size_t lockerSze;
    std::string what;
    {
        RLocker cmdsLck{_cmdsMtx};
        lockerSze = _commands.size();
    }
    if (lockerSze) {
        {
            WLocker cmdsLck{_cmdsMtx};
            what = _commands.front();
            _commands.pop();
        }
    } else
        what = getWord();
    try {
        WLocker lock{_cfgMtx};
        _cfg = parseJson<JsonBuilder>(what);
        _oldCfg = what;
        std::cout << "Config file loaded from " << _oldCfg << std::endl;
        _modules->load(_cfg.as<api::JsonObject>());
    } catch (std::string const &e) {
        std::cerr << "Parser error reported > " << e << std::endl;
        std::cerr << "Bad config file > cannot load > " << what << std::endl;
    }
}

void Core::reload()
{
    if ("__NONE__" == _oldCfg)
        std::cerr << "Cannot reload > no loaded config " << _oldCfg << std::endl;
    else {
        WLocker lock{_cfgMtx};
        _cfg = parseJson<JsonBuilder>(_oldCfg);
        std::cout << "Config file reload from " << _oldCfg << std::endl;
        _modules->load(_cfg.as<api::JsonObject>());
    }
}

void Core::save()
{
    if ("__NONE__" == _oldCfg)
        std::cerr << "Cannot save > no loaded config " << _oldCfg << std::endl;
    else {
        RLocker lock{_cfgMtx};
        std::wofstream os{_oldCfg};
        if (!os.good())
            std::cerr << "Cannot save to > " << _oldCfg << std::endl;
        else {
            visitJson(_cfg, JsonPrinter{os, false});
            os.close();
            std::cout << "Config file saved into " << _oldCfg << std::endl;
        }
    }
}

void Core::modify()
{
    std::size_t lockerSze;
    std::string what;
    if ("__NONE__" == _oldCfg)
        std::cerr << "Cannot modify > no loaded config " << _oldCfg << std::endl;
    else {
        std::string key, value;
        {
            RLocker cmdsLck{_cmdsMtx};
            lockerSze = _commands.size();
        }
        if (lockerSze) {
            {
                WLocker cmdsLck{_cmdsMtx};
                key = _commands.front();
                _commands.pop();
            }
        } else
            key = getWord();
        {
            RLocker cmdsLck{_cmdsMtx};
            lockerSze = _commands.size();
        }
        if (lockerSze) {
            {
                WLocker cmdsLck{_cmdsMtx};
                value = _commands.front();
                _commands.pop();
            }
        } else
            value = getWord();
        WLocker lock{_cfgMtx};
        _cfg = visitJson(_cfg, JsonModifier{key, value});
        std::cout << "Changed every  " << key << " into " << value << std::endl;
        _modules->load(_cfg.as<api::JsonObject>());
    }
}

void Core::help(Core &core) noexcept
{
    std::cout << core._bin << " help message:\n"
              << "\n==== Utility section ====\n"
              << "This binary is a shell used to run, load and manage web server modules.\n"
              << "You can launch it and then type commands, or simply run a list of commands in the binary parametters.\n"
              << "The server will close after executing all the commands given as parameter, use [--noexit | noexit | -n] in the commands to avoid that.\n"
              << "[--help | help | -h] will display this help message.\n"
              << "Note that no '-' is allowed in shell mod, but it is in parametters.\n"
              << "\n==== Config section ====\n"
              << "The server is basing itself on a config file. Here is how to manipulate the config from the shell:\n"
              << "load {PATH} -> loading a config from a json file.\n"
              << "reload -> reloading the current config from the original file.\n"
              << "save -> saving the current config to the original file.\n"
              << "modify {KEY} {VALUE} -> changing all key values by the specified value. Keeping the original type if matching.\n"
              << "print -> printing the current config to the standard output.\n"
              << "start -> launch network module.\n"
              << "stop -> stop network module.\n"
              << "restart -> restart network module.\n"
              << "Here is a short example you can try safely at home:\n"
              << core._bin << " load config.json print modify debug "
              << (rand() % 2 ? "true" : "false")
              << " print save reload start --noexit"
              << std::endl;
}


std::function<bool(std::string const &, std::string const &)> Core::_cmp = [](std::string const &f,
                                                                              std::string const &s) {
    return std::equal(f.cbegin(), f.cend(), s.cbegin(), s.cend(),
                      [](char const f, char const s) { return tolower(f) == tolower(s); });
};
std::function<std::string(std::string const &)> Core::_low = [](std::string const &f) {
    std::string s = f;
    std::for_each(s.begin(), s.end(), [](char &s) { s = tolower(s); });
    return s;
};

std::function<std::string(std::string const &)> Core::_up = [](std::string const &f) {
    std::string s = f;
    std::for_each(s.begin(), s.end(), [](char &s) { s = toupper(s); });
    return s;
};

