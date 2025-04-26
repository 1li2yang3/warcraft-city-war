#include "Dragon.h"
using namespace std;
Dragon::Dragon(int Dlife,int atk) {
    setHP(Dlife);
    setATK(atk);
}

void Dragon::setWeaponType(int type) {
    WeaponType=type;
    if(type==2)
        addWeapon(type,2);
    else if(type==1)
        addWeapon(type,1);
    else if(type==0)
        addWeapon(type,99999);
}
void Dragon::setMorale(double morale) {
    /*
    int z=(int)(morale*100);
    double x=morale*100-z;
    if(x>=0.5){
        Morale=morale+0.01-(((int)((morale+0.01)*1000))*1.0)/1000;
    }else{
        Morale=morale-(((int)(morale*1000))*1.0)/1000;
    }
     */
    Morale=morale;
}
int Dragon::getWeaponType() {
    return WeaponType;
}
double Dragon::getMorale() {
    return Morale;
}
int Dragon::getTypeName() {
    return 1;
}
string Dragon::getType(){
    return "dragon";
}