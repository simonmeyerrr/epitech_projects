/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** BF_Translator.cpp
*/

#include "BF_Translator.hpp"

static void print_tabs(std::ofstream &output, int tabs)
{
    for (int i = 0; i < tabs; i++)
        output << TAB;
}

static int switch_code(std::ofstream &output, char c, int &tab)
{
    switch (c) {
    case '+':
        print_tabs(output, tab);
        output << "tab[i]++;" << ENDL;
        return (0);
    case '-':
        print_tabs(output, tab);
        output << "tab[i]--;" << ENDL;
        return (0);
    case '>':
        print_tabs(output, tab);
        output << "i++;" << ENDL;
        return (0);
    case '<':
        print_tabs(output, tab);
        output << "i--;" << ENDL;
        return (0);
    case '.':
        print_tabs(output, tab);
        output << "write(1, &(tab[i]), 1);" << ENDL;
        return (0);
    case ',':
        print_tabs(output, tab);
        output << "read(0, &(tab[i]), 1);" << ENDL;
        return (0);
    case '[':
        print_tabs(output, tab);
        output << "while(tab[i]) {" << ENDL;
        tab++;
        return (0);
    case ']':
        tab--;
        print_tabs(output, tab);
        output << "}" << ENDL;
        return (0);
    case '\n':
    case '\r':
    case '\t':
    case ' ':
        return (0);
    default:
        return (1);
    }
}

static int do_code(const std::string &in, std::ofstream &output)
{
    int tab = 1;
    int error = 0;

    for (unsigned int i = 0; i < in.size() && !error; i++)
        error = switch_code(output, in[i], tab);
    return (error);
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::ifstream input(in);
    std::ofstream output(out);
    std::string bf;

    if (!input.is_open())
        return (1);

    char c = input.get();
    while (input.good()) {
        bf += c;
        c = input.get();
    }
    if (!output.is_open())
        return (1);
    output << "#include <stdlib.h>" << ENDL;
    output << "#include <unistd.h>" << ENDL;
    output << "#include <string.h>" << ENDL;
    output << ENDL << "int main(void)" << ENDL << "{" << ENDL;
    output << TAB << "int i = 0;" << ENDL;
    output << TAB << "char *tab = malloc(sizeof(char) * 60000);" << ENDL;
    output << ENDL << TAB << "if (!tab)" << ENDL;
    output << TAB << TAB << "return (1);" << ENDL;
    output << TAB << "memset(tab, 0, 60000);" << ENDL;
    if (do_code(bf, output))
        return (1);
    output << TAB << "free(tab);" << ENDL;
    output << TAB << "return (0);" << ENDL;
    output << "}" << ENDL;
    return (0);
}
