/*
** EPITECH PROJECT, 2018
** cpp_d08_2018
** File description:
** DroidMemory.hpp
*/

#ifndef CPP_D08_2018_DROIDMEMORY_HPP_
# define CPP_D08_2018_DROIDMEMORY_HPP_

class DroidMemory {
public:
    // Ctor and Dtor
    DroidMemory();
    DroidMemory(const DroidMemory &);
    ~DroidMemory();

    // Member functions
    size_t getFingerPrint() const;
    size_t getExp() const;

    void setFingerPrint(size_t);
    void setExp(size_t);

    DroidMemory &operator<<(const DroidMemory &);
    DroidMemory &operator>>(DroidMemory &) const;
    DroidMemory &operator+=(const size_t &);
    DroidMemory &operator+=(const DroidMemory &);
    DroidMemory &operator+(const size_t &) const;
    DroidMemory &operator+(const DroidMemory &) const;
    DroidMemory &operator=(const DroidMemory &droid);

    bool operator==(const DroidMemory &) const;
    bool operator!=(const DroidMemory &) const;
    bool operator<(const DroidMemory &) const;
    bool operator>(const DroidMemory &) const;
    bool operator<=(const DroidMemory &) const;
    bool operator>=(const DroidMemory &) const;

    bool operator==(const size_t &) const;
    bool operator!=(const size_t &) const;
    bool operator<(const size_t &) const;
    bool operator>(const size_t &) const;
    bool operator<=(const size_t &) const;
    bool operator>=(const size_t &) const;

private:
    // Properties
    size_t _id;
    size_t _exp;
};

std::ostream &operator<<(std::ostream &, const DroidMemory &);

#endif /* CPP_D08_2018_DROIDMEMORY_HPP_ */
