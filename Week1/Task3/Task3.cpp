#include "Task3.h"

uint64_t Task3::Sum_weight() {
    uint64_t sum=0;
    for(size_t i=0 ; i<N ;++i)
    {
        sum += blocks[i].W*blocks[i].D*blocks[i].H*R;
    }
    return sum;
}
