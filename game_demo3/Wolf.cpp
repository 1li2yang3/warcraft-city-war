#include "Wolf.h"
#include <iostream>
using namespace std;
Wolf::Wolf(int Dlife,int atk) {
    setHP(Dlife);
    setATK(atk);
}
int Wolf::getTypeName() {
    return 5;
}
string Wolf::getType() {
    return "wolf";
}