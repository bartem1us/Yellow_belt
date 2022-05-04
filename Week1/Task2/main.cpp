#include "Task2.h"
#include <iostream>
int main() {
    unsigned int N ;
    std::vector<int> temperatures;
    std::cin>>N;
    temperatures.resize(N);
    for(size_t i = 0 ; i<temperatures.size() ; ++i)
    {
        std::cout<<std::endl<<"Enter your "<<i+1<<" temperature"<<std::endl;
        std::cin>>temperatures[i];
    }

    Task2 example(N,temperatures);
    auto[K_number, avg] = example.Find_avg();
    std::cout<<K_number<<std::endl;
    for(size_t i = 0 ; i<avg.size();++i)
    {
        std::cout<<avg[i]<<" ";
    }
}

