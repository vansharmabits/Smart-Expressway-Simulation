#include "../include/Expressway.h"

extern void runCLI(Expressway&);

int main() {
    Expressway e;

    if(!e.loadFromFile("data/expressway.txt")) {
        cout<<"File not found\n";
    }

    runCLI(e);
    return 0;
}