//
//  Day2.cpp
//  Advent of code 2021
//
//  Created by Sanjin Grahovar Sadiković on 02.12.2021..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>

class Day2{
private:    
    std::vector<std::pair<std::string, int>> listValues;
    
public:
    
    Day2(){
        
    }
    
    void loadInput(std::string inputFile){
        std::vector<std::string> inputList;
        
        std::ifstream file(inputFile);
        std::string str;
        
        std::string delimiter = " ";
        
        while(std::getline(file, str)){
            std::string token = str.substr(0, str.find(delimiter));
            std::string number = str.substr(token.length() + 1);
            
            listValues.push_back(std::pair<std::string, int>(token, stoi(number)));
        }
    }
    
    int solveFirst(){
        int horizontal = 0, depth = 0;
        
        loadInput("Day2/first.txt");
                
        for (auto itr = listValues.begin(); itr != listValues.end(); ++itr) {
            // std::cout << itr->first << '\t' << itr->second << '\n';
            if(itr->first == "forward") horizontal += itr->second;
            else if(itr->first == "down") depth += itr->second;
            else if(itr->first == "up") depth -= itr->second;
        }
        
        return horizontal * depth;
    }
    
    int solveSecond(){
        int horizontal = 0, depth = 0, aim = 0;
        
        loadInput("Day2/first.txt");
                
        for (auto itr = listValues.begin(); itr != listValues.end(); ++itr) {
            if(itr->first == "forward") {
                horizontal += itr->second;
                if (aim != 0) depth = depth + (aim * itr->second);
            }
            
            else if(itr->first == "down"){
                aim += itr->second;
            }
            
            else if(itr->first == "up"){
                aim -= itr->second;
            }
        }
        
        return horizontal * depth;
    }
    
};
