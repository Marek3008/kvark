#include "Process/Process.h"

int main(void){
    Process* p = new Process("1 2 3 1 2 3 1 2 4 4 4 4");

    p->Run();

    return 0;
}