/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Parser.hpp
*/

#ifndef CPP_D16_2018_PARSER_HPP_
# define CPP_D16_2018_PARSER_HPP_

# include <stack>
# include <string>

class Parser {
public:
    class Elem {
    public:
        ~Elem() = default;
        Elem(int new_nb, char new_op) : nb(new_nb), op(new_op), next(nullptr) {}
        int nb;
        char op;
        Elem *next;
    };

    ~Parser();
    Parser();

    void feed(const std::string &);
    int result() const;
    void reset();

    void addNumber(int nb);
    void addOp(char op);
    void destack();
    void solveNPI();
    int calcul(int a, int b, char op);
    int getlevel(char op);

private:
    Elem *_first;
    Elem *_second;
    int _result;
};

#endif /* CPP_D16_2018_PARSER_HPP_ */
