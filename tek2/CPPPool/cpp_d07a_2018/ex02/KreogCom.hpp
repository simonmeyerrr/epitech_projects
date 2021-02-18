/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** KreogCom.hpp
*/

#ifndef CPP_D07A_2018_KREOGCOM_HPP_
# define CPP_D07A_2018_KREOGCOM_HPP_

class KreogCom {
public:
    KreogCom(int x, int y, int serial, KreogCom * = nullptr);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom() const;

    void ping() const;
    void locateSquad() const;
    void locateSquadTwo() const;

private:
    int _x;
    int _y;
    const int m_serial;
    KreogCom *_link;
    KreogCom *_prev;
};

#endif /* CPP_D07A_2018_KREOGCOM_HPP_ */
