#include "Process.h"

#include <iostream>
#include <sstream>

Process::Process(std::string input) {
    std::istringstream iss(input);
    int helperInt;

    while (iss >> helperInt) {
        this->body.push_back(helperInt);
    }
}

std::pair<int, int> Process::FindMostNumerousPair() const {
    int n = (int)this->body.size();
    std::pair<int, int> mostNumerousPair;
    int highestCount = 0;
    
    for(int i = 0; i < n - 1; i++) {
        std::pair<int, int> current = {this->body[i], this->body[i + 1]};

        int currentCount = 0;

        for(int j = 0; j < n - 1; j++) {
            if (this->body[j] == current.first && this->body[j + 1] == current.second) currentCount++;
            if (currentCount > highestCount) {
                highestCount = currentCount;
                mostNumerousPair = current;
            } 
        }
    }

    return mostNumerousPair;
}

void Process::PrintBody() const {
    for (auto num : this->body) std::cout << num << " ";

    std::cout << std::endl;
}

void Process::PrintMostNumerousPair() const {
    std::pair<int, int> pair = FindMostNumerousPair();
    
    std::cout << pair.first << " " << pair.second << std::endl;
}