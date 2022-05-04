#include "Task6.h"
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x: Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto &x: Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }
}
