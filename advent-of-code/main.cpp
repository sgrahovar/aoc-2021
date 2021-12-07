//
//  main.cpp
//  Advent of code 2021
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2021..
//

#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Day1/Day1.cpp"
#include "Day2/Day2.cpp"
#include "Day3/Day3.cpp"


int main(int argc, const char * argv[]) {
    
    auto start = std::chrono::high_resolution_clock::now();
    
    Day1 day1;
    
    // std::cout << "Day 1, challenge 1: " << day1.solveFirst() << std::endl << std::endl;
    // std::cout << "Day 1, challenge 2: " << day1.solveSecond() << std::endl << std::endl;
    
    Day2 day2;
    // std::cout << "Day 2, challenge 1: " << day2.solveFirst() << std::endl << std::endl;
    // std::cout << "Day 2, challenge 1: " << day2.solveSecond() << std::endl << std::endl << std::endl;
    
    Day3 day3;
    // std::cout << "Day 3, challenge 1: " << day3.solveFirst() << std::endl << std::endl;
    std::cout << "Day 3, challenge 1: " << day3.solveSecond() << std::endl << std::endl << std::endl;
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    auto durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Function execution duration: " << durationMicroseconds.count() << " microseconds, " <<
    (float)durationMicroseconds.count()/1000000 << " seconds." << std::endl << std::endl;;
    
    return 0;
}
