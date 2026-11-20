#include "Process/Process.h"

int main(void){
    Process* p = new Process("2 1 2 1 2 1 0 3 20 20 20 20 20 2 1 2 1");

    p->PrintMostNumerousPair();

    return 0;
}