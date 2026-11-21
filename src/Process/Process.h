#pragma once

#include <vector>
#include <string>

class Process {
    private:
        struct Macro {
            int newOpcode;
            int oldFirst;
            int oldSecond;
        };
    
        std::vector<int> body;
        std::vector<Macro> macros;

        std::pair<int, int> FindMostNumerousPair() const;
        int FindHighestOpcodeValue() const;
        void Simplify();

        void PrintBody() const;
        void PrintMostNumerousPair() const;
        void PrintMacros() const;

    public:
        Process(std::string input);

        void Run();
};