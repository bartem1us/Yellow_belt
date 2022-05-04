//
// Created by bartem1us on 26.03.2022.
//

#ifndef TEMPLATE_TASK3_H
#define TEMPLATE_TASK3_H
#include <cstdint>
#include <vector>
struct block{
    unsigned int W;
    unsigned int H;
    unsigned int D;

};

class Task3 {
private:
    unsigned int N;
    unsigned int R;
    std::vector<block> blocks;
public:
    Task3(unsigned int n, uint8_t r, std::vector<block> &blocks_) : N(n), R(r),  blocks(blocks_){};

    uint64_t Sum_weight();

};

#endif //TEMPLATE_TASK3_H
