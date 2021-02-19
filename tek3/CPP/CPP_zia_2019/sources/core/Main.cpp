#include <string>
#include <iostream>
#include <memory>

#include "Core.hpp"
#include "IError.hpp"

int main(int const ac, char const **av, char const *const *env)
{
    std::unique_ptr<Core> core = nullptr;

    try {
        core = std::make_unique<Core>(ac, av);
        core->run();
    } catch (IError const &error) {
        std::cerr << error.what() << std::endl;
        return error.ErrorCode();
    } catch (std::exception const &error) {
        std::cerr << "Error :: Standard exception :: " << error.what() << std::endl;
        return 125;
    } catch (std::string const &error) {
        std::cerr << "Error :: std::string :: " << error << std::endl;
        return 125;
    } catch (char const *const error) {
        std::cerr << "Error :: C-style string :: " << error << std::endl;
        return 125;
    } catch (...) {
        std::cerr << "Error :: Unknown savage error" << std::endl;
        return 125;
    }
    return 0;
}

