/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** TabGenerator.cpp
*/

#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> createComb(int a, int b, int c, int d, int e)
{
    std::vector<int> comb;

    comb.push_back(a);
    comb.push_back(b);
    comb.push_back(c);
    comb.push_back(d);
    comb.push_back(e);
    std::sort(comb.begin(), comb.end());
    return (comb);
}

int main()
{
    int j;
    std::vector<std::vector<int>> combTab;

    for (int a = 1 ; a < 7 ; a++) {
        for (int b = 1 ; b < 7 ; b++) {
            for (int c = 1 ; c < 7 ; c++) {
                for (int d = 1 ; d < 7 ; d++) {
                    for (int e = 1 ; e < 7 ; e++) {
                        combTab.push_back(createComb(a, b, c, d, e));
                    }
                }
            }
        }
    }
    std::sort(combTab.begin(), combTab.end());
//    combTab.erase(unique(combTab.begin(), combTab.end()), combTab.end());
    for (int i = 0; i < combTab.size(); i++) {
        std::cout << "{ ";
        for (j = 0; j < combTab[i].size() - 1; j++) {
            std::cout << combTab[i][j] << ", ";
        }
        std::cout << combTab[i][j] << " }," << std::endl;
    }
}
