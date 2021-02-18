/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** ICombination.hpp
*/
#ifndef INC_201YAMS_2018_ICOMBINATION_HPP
# define INC_201YAMS_2018_ICOMBINATION_HPP

class ICombination {
public:
    virtual ~ICombination() = default;

    virtual void compute(int *dies) = 0;
    virtual void dump() const = 0;
};

int getCases(int *count);

#endif /* INC_201YAMS_2018_ICOMBINATION_HPP */
