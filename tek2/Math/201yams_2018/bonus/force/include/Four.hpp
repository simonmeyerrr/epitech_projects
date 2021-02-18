/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Four.hpp
*/
#ifndef INC_201YAMS_2018_FOUR_HPP
# define INC_201YAMS_2018_FOUR_HPP

# include <string>
# include "ICombination.hpp"

class Four : public ICombination {
public:
    ~Four() = default;
    Four(int);

    void compute(int *dies);
    void dump() const;

private:
    int _value;

    int _total;
    int _success;
};

#endif /* INC_201YAMS_2018_FOUR_HPP */
