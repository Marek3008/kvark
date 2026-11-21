#include "Process.h"

#include <iostream>
#include <sstream>
#include <map>

Process::Process(std::string input) {
    std::istringstream iss(input);
    int helperInt;

    while (iss >> helperInt) {
        this->body.push_back(helperInt);
    }
}

std::pair<int, int> Process::FindMostNumerousPair() const {
    int n = (int)body.size();
    std::map<std::pair<int, int>, int> counts;

    for (int i = 0; i + 1 < n; ++i) {
        counts[{body[i], body[i + 1]}]++;
    }

    std::pair<int, int> mostNumerousPair = {-1, -1};
    int highestCount = 1;

    for (const auto entry : counts) {
        if (entry.second > highestCount) {
            highestCount = entry.second;
            mostNumerousPair = entry.first;
        }
    }

    return mostNumerousPair;
}

int Process::FindHighestOpcodeValue() const {
    int highest = 0;

    for (auto opcode : body) {
        if (opcode > highest) highest = opcode;
    }

    return highest;
}

void Process::Simplify() {
    if (body.size() < 2) return;

    int nextOpcode = FindHighestOpcodeValue() + 1;

    while (true) {
        std::pair<int, int> toReplace = FindMostNumerousPair();

        if (toReplace.first == -1 && toReplace.second == -1) break;

        Macro macro = {
            nextOpcode,
            toReplace.first,
            toReplace.second
        };

        std::vector<int> nextBody;
        nextBody.reserve(body.size());

        int n = (int)body.size();

        for (int i = 0; i < n;) {
            if (i + 1 < n && body[i] == toReplace.first && body[i + 1] == toReplace.second) {
                nextBody.push_back(macro.newOpcode);
                i += 2;
            } 
            else {
                nextBody.push_back(body[i]);
                i++;
            }
        }

        body = std::move(nextBody);
        macros.push_back(macro);
        nextOpcode++;
    }
}

void Process::PrintBody() const {
    std::cout << "Program: " << std::endl;

    for (auto num : this->body) std::cout << num << " ";

    std::cout << std::endl;
}

void Process::PrintMostNumerousPair() const {
    std::pair<int, int> pair = FindMostNumerousPair();
    
    std::cout << pair.first << " " << pair.second << std::endl;
}

void Process::PrintMacros() const {
    std::cout << "Makroinštrukcie:" << std::endl;

    for (const auto& macro : macros) {
        std::cout << macro.newOpcode << " -> " << macro.oldFirst << " " << macro.oldSecond << std::endl;
    }
}

void Process::Run() {
    Simplify();
    PrintMacros();
    PrintBody();
}