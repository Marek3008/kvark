#pragma once

#include <vector>
#include <string>

class Process {
    private:
        std::vector<int> body;

    public:
        Process(std::string input);

        std::pair<int, int> FindMostNumerousPair() const;

        void PrintBody() const;
        void PrintMostNumerousPair() const;
};