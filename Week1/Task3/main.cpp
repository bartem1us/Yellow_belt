#include "Task3.h"
#include <iostream>
int main() {
    unsigned int N;
    unsigned int R;
    unsigned int W;
    unsigned int H;
    unsigned int D;
    std::vector<block> blocks;
    std::cin>>N>>R;
    blocks.resize(N);
    for(size_t i = 0 ; i<N;++i)
    {
     std::cin>>W>>H>>D;
     blocks[i].H=H;
     blocks[i].D=D;
     blocks[i].W=W;
    }
    Task3 task3(N,R,blocks);
    uint64_t sum = task3.Sum_weight();
    std::cout<<sum<<std::endl;

}

