#include <iostream>

#include "Unit.h"
#include "MoveCommand.h"

using namespace std;

int main() {
    Unit unit(0, 10, 10, 10, 10);
    MoveCommand mc(0, 20, 20);
    return 0;
}