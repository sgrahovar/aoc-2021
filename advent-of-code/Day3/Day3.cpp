//
//  Day3.cpp
//  Advent of code 2021
//
//  Created by Sanjin Grahovar Sadiković on 03.12.2021..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <bitset>


class Day3{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    
    Day3(){
        
    }
    
    std::vector<std::string> loadInput(std::string inputFile){
        std::vector<std::string> inputList;
        
        std::ifstream file(inputFile);
        std::string str;

        while(std::getline(file, str)){
            inputList.push_back(str);
        }
        
        return inputList;
    }
    
    unsigned long solveFirst(){
        this->input1 = loadInput("Day3/first.txt");
        
        unsigned long len = input1[0].size();
        std::string result;
        
        for(int i = 0; i < len; i++){
            int zero = 0, one = 0;
            for(int j = 0; j < input1.size(); j++){
                // std::cout << input1[j][i] << std::endl;
                if(input1[j][i] == '0'){
                    zero++;
                } else{
                    one++;
                }
            }
            if(zero > one){
                result.append("0");
            } else{
                result.append("1");
            }
        }
        
        return calculateDecimal(result) * calculateDecimal(reverseBinary(result));
    }
    
    unsigned long solveSecond(){
        this->input2 = loadInput("Day3/first.txt");

        std::string result1 = getOxygenGeneratorRating(input2);
        std::string result2 = getCO2ScrubberRating(input2);
                        
        return calculateDecimal(result1) * calculateDecimal(result2);
    }
    
    unsigned long calculateDecimal(std::string input){
        unsigned long long value = std::bitset<64>(input).to_ullong();
        return value;
    }
    
    std::string reverseBinary(std::string input){
        std::string newString;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '0') newString.append("1");
            else newString.append("0");
        }
        return newString;
    }
    
    std::string getOxygenGeneratorRating(std::vector<std::string> input){
        unsigned long len = input[0].size();
        std::string result;
        
        std::cout << std::endl;
        
        for(int i = 0; i < len; i++){
            int zero = 0, one = 0;
            char leadingBit;
            for(int j = 0; j < input.size(); j++){
                if(input[j][i] == '0'){
                    zero++;
                } else{
                    one++;
                }
            }
                        
            if(one > zero || one == zero) leadingBit = '1';
            else leadingBit = '0';
                                    
            auto it = input.begin();
            while(it != input.end()){
                if((*it)[i] != leadingBit){
                    it = input.erase(it);
                }
                else{
                    ++it;
                }
            }
            
            if(input.size() <= 1){
                result = input[0];
                break;
            }
        }
        
        return result;
    }
    
    std::string getCO2ScrubberRating(std::vector<std::string> input){
        unsigned long len = input[0].size();
        std::string result;
        
        std::cout << std::endl;
        
        for(int i = 0; i < len; i++){
            int zero = 0, one = 0;
            char leadingBit;
            for(int j = 0; j < input.size(); j++){
                if(input[j][i] == '0'){
                    zero++;
                } else{
                    one++;
                }
            }
                                    
            if(one > zero || one == zero) leadingBit = '0';
            else leadingBit = '1';
                        
            auto it = input.begin();
            while(it != input.end()){
                if((*it)[i] != leadingBit){
                    it = input.erase(it);
                }
                else{
                    ++it;
                }
            }
            
            if(input.size() <= 1){
                result = input[0];
                break;
            }
        }
        
        return result;
    }
};
