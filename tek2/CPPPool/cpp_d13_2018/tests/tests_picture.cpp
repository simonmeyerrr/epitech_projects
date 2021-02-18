/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** tests_picture.cpp
*/

#include <criterion/criterion.h>
#include <string>
#include "Toy.hpp"

Test(Picture, without_arg)
{
    Picture pic;

    cr_assert_eq(std::string(""), pic.data);
}

Test(Picture, full_arg)
{
    Picture pic("picture.test");

    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), pic.data);
}

Test(Picture, get_picture)
{
    Picture pic;

    cr_assert_eq(true, pic.getPictureFromFile("picture.test"));
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), pic.data);
    cr_assert_eq(false, pic.getPictureFromFile("picture.test "));
    cr_assert_eq(std::string("ERROR"), pic.data);
}

Test(Picture, copy_constructor)
{
    Picture old_pic("picture.test");
    Picture pic(old_pic);

    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), pic.data);
}

Test(Picture, operator_equal)
{
    Picture old_pic("picture.test");
    Picture pic;

    pic = old_pic;
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), pic.data);
}