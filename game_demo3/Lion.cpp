#include "Lion.h"
#include <iostream>
using namespace std;
Lion::Lion(int Dlife,int atk) {
    setHP(Dlife);
    setATK(atk);
}
void Lion::setWeaponType(int type) {
    WeaponType=type;
    if(type==2)
        addWeapon(type,2);
    else if(type==1)
        addWeapon(type,1);
    else if(type==0)
        addWeapon(type,99999);
}
int Lion::getWeaponType() {
    return WeaponType;
}
void Lion::setLoyalty(int loyalty) {
    Loyalty=loyalty;
}
int Lion::getLoyalty() {
    return Loyalty;
}
int Lion::getTypeName() {
    return 4;
}
string Lion::getType(){
    return "lion";
}