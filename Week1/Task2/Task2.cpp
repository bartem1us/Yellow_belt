#include "Task2.h"
#include <cstdint>

std::tuple<int,std::vector<int>> Task2::Find_avg() {
    int64_t sum = 0;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        sum += temperatures[i];
    }
    int K = sum/static_cast<int>(N);
    std::vector<int> more_avg;
    size_t index = 0 ;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        if(temperatures[i]>K)
        {
            ++index;
            more_avg.push_back(i);
        }
    }
    return {index,more_avg};
}
