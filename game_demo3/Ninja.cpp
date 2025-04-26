#include "Ninja.h"
using namespace std;
Ninja::Ninja(int Dlife,int atk) {
    setHP(Dlife);
    setATK(atk);
}
void Ninja::setWeaponType1(int type) {
    WeaponType1=type;
    if(type==2)
        addWeapon(type,2);
    else if(type==1)
        addWeapon(type,1);
    else if(type==0)
        addWeapon(type,99999);
}
void Ninja::setWeaponType2(int type) {
    WeaponType2=type;
    if(type==2)
        addWeapon(type,2);
    else if(type==1)
        addWeapon(type,1);
    else if(type==0)
        addWeapon(type,99999);
}
int Ninja::getWeaponType1() {
    return WeaponType1;
}
int Ninja::getWeaponType2() {
    return WeaponType2;
}
int Ninja::getTypeName() {
    return 2;
}
string Ninja::getType(){
    return "ninja";
}