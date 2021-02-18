/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Pair.hpp
*/
#ifndef INC_201YAMS_2018_PAIR_HPP
# define INC_201YAMS_2018_PAIR_HPP

# include <string>
# include "ICombination.hpp"

class Pair : public ICombination {
public:
    ~Pair() = default;
    Pair(int);

    void compute(int *dies);
    void dump() const;

private:
    int _value;

    int _total;
    int _success;
};

#endif /* INC_201YAMS_2018_PAIR_HPP */
