//
// Created by bartem1us on 25.03.2022.
//

#ifndef TEMPLATE_TASK2_H
#define TEMPLATE_TASK2_H
#include <vector>
#include <tuple>
class Task2 {
private:
    unsigned int N ;
    std::vector<int>temperatures;
public:
    Task2(unsigned int n , std::vector<int>temperature):N(n),temperatures(temperature){};

    std::tuple<int,std::vector<int>> Find_avg();
};


#endif //TEMPLATE_TASK2_H
