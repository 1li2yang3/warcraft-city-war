#include "Iceman.h"
#include <iostream>
using namespace std;
Iceman::Iceman(int Dlife,int atk) {
    setHP(Dlife);
    setATK(atk);
}
void Iceman::setWeaponType(int type) {
    WeaponType=type;
    if(type==2)
        addWeapon(type,2);
    else if(type==1)
        addWeapon(type,1);
    else if(type==0)
        addWeapon(type,99999);
}
int Iceman::getWeaponType() {
    return WeaponType;
}
int Iceman::getTypeName() {
    return 3;
}
string Iceman::getType(){
    return "iceman";
}