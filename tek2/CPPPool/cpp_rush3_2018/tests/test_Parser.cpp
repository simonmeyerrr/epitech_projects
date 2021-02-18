/*
** EPITECH PROJECT, 2019
** C++Pool
** File description:
** Test Parser
*/

#include <criterion/criterion.h>
#include "../src/Parser/Parser.hpp"

Test(Parser, no_args)
{
    int ac = 1;
    const char *av[] = {"./a.out"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::UNKNOWN);
    auto mods = parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);

    Parser new_parser(parser);
    cr_assert_eq(new_parser.getMode(), Types::UNKNOWN);
    mods = new_parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);

    parser = new_parser;
    cr_assert_eq(parser.getMode(), Types::UNKNOWN);
    mods = parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);
}

Test(Parser, display)
{
    int ac = 1;
    const char *av[] = {"./a.out"};
    Parser parser(ac, av);
    parser.printUsage();

    Parser empty(0, nullptr);
    empty.printUsage();
}

Test(Parser, one_arg_sfml)
{
    int ac = 2;
    const char *av[] = {"./a.out", "sfml"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::SFML);
    auto mods = parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);
}

Test(Parser, one_arg_ncurse)
{
    int ac = 2;
    const char *av[] = {"./a.out", "ncurse"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::NCURSE);
    auto mods = parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);
}

Test(Parser, one_arg_bad)
{
    int ac = 2;
    const char *av[] = {"./a.out", "hello"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::UNKNOWN);
    auto mods = parser.getModules();
    for (int i = 0; i < 4; i++)
        cr_assert_eq(mods[i], Types::NONE);
}

Test(Parser, modules_1)
{
    int ac = 6;
    const char *av[] = {"./a.out", "sfml", "info", "cpu", "memory", "network"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::SFML);
    auto mods = parser.getModules();
    cr_assert_eq(mods[0], Types::INFO);
    cr_assert_eq(mods[1], Types::CPU);
    cr_assert_eq(mods[2], Types::MEMORY);
    cr_assert_eq(mods[3], Types::NETWORK);
}

Test(Parser, modules_2)
{
    int ac = 6;
    const char *av[] = {"./a.out", "sfml", "reports", "dan", "none", "blabla"};
    Parser parser(ac, av);

    cr_assert_eq(parser.getMode(), Types::SFML);
    auto mods = parser.getModules();
    cr_assert_eq(mods[0], Types::REPORTS);
    cr_assert_eq(mods[1], Types::DAN);
    cr_assert_eq(mods[2], Types::NONE);
    cr_assert_eq(mods[3], Types::NONE);
}