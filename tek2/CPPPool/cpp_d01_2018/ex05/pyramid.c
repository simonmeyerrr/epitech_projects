/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** pyramid.c
*/

static int find_shortest(int size, int height, int pos, const int **map)
{
    int res1 = 0;
    int res2 = 0;

    if (size - 1 == height)
        return map[height][pos];
    res1 = find_shortest(size, height + 1, pos, map);
    res2 = find_shortest(size, height + 1, pos + 1, map);
    if (res1 < res2)
        return (res1 + map[height][pos]);
    else
        return (res2 + map[height][pos]);
}

int pyramid_path(int size, const int **map)
{
    return (find_shortest(size, 0, 0, map));
}