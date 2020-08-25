#include "CTimer.h"
#include <iostream>
#include <chrono>

int main()
{
    Timer::CPUTimer time;
    time.Start();
    for (int i=0; i< 1000; ++i)
    {
        std::cout << i << std::endl;
    }
    float elaps = time.MilliSeconds();
    std::cout <<"耗时1： " << elaps << "ms" << std::endl; 

    time.Start();
    for (int i = 0; i < 1000; ++i)
    {
        std::cout << i << std::endl;
    }
    elaps = time.MilliSeconds();
    std::cout << "耗时2： " << elaps << "ms" << std::endl;
    return 0;
}