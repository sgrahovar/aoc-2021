//
//  Day1.cpp
//  Advent of code 2021
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2021..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <filesystem>
namespace fs = std::__fs::filesystem;

class Day1{
private:
    std::vector<int> input1;
    std::vector<int> input2;
    
public:
    
    Day1(){
        
    }
    
    std::vector<int> loadInput(std::string inputFile){
        std::vector<int> inputList;
        
        std::ifstream file(inputFile);
        std::string str;

        while(std::getline(file, str)){
            inputList.push_back(std::stoi(str));
        }
        
        return inputList;
    }
    
    int solveFirst(){
        int increased = 0;
        this->input1 = loadInput("Day1/first.txt");
        
        for(int i = 1; i < input1.size(); i++){
            if(input1[i] > input1[i-1]) increased++;
        }
        
        return increased;
        
    }
    
    int solveSecond(){
        int increased = 0;
        std::vector<int> results;
        
        this->input2 = loadInput("Day1/first.txt");
        
        for(int i = 0; i < input2.size() - 2; i++){
            int result = input2[i] + input2[i+1] + input2[i+2];
            results.push_back(result);
            
            if(i != 0 && result > results[i-1]) increased++;
            
        }
        return increased;
    }
    
};
