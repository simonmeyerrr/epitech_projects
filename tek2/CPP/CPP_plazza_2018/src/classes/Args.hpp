/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Args.hpp
*/

#ifndef CPP_PLAZZA_2018_ARGS_HPP
# define CPP_PLAZZA_2018_ARGS_HPP

class Args {
public:
    Args(int ac, const char **av);

    double getMultiplier() const;
    int getCooks() const;
    int getRespawn() const;
    int checkArgs();

private:
    int usage(int) const;
    bool isNum(const char *) const;

    int _ac;
    const char **_av;
    double _multiplier;
    int _cooks;
    int _respawn;
};

#endif /* CPP_PLAZZA_2018_SERIALIZATION_HPP */
