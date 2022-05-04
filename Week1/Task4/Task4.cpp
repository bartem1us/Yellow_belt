#include "Task4.h"

int FindMaxRepetitionCount(const std::vector<Region> &regions) {
    if (regions.size() == 0) {
        return 0;
    }
    int repeat = 1;
    int answer=0;
    for (size_t i = 0; i < regions.size(); ++i) {
        for (size_t j = i + 1; j < regions.size(); ++j) {
            if (regions[i] == regions[j]) {
                ++repeat;
            }
        }
        if(repeat>answer)
        {
            answer = repeat;
        }
        repeat = 1;
    }
    return answer;
}

