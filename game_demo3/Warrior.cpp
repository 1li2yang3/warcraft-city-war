#include "Warrior.h"
Warrior::Warrior() {

}
Warrior::~Warrior() {}
int Warrior::getHP() {
    return HP;
}
int Warrior::getATK() {
    return ATK;
}
void Warrior::setHP(int hp) {
    HP=hp;
}
void Warrior::setATK(int atk) {
    ATK=atk;
}
void Warrior::addWeapon(int type,int remain) {
    Weapon.push_back(type);
    this->remain.push_back(remain);
}
void Warrior::setAtCity(int AtCity) {
    this->AtCity=AtCity;
}
int Warrior::getAtCity() {
    return AtCity;
}
void Warrior::nextCity() {
    AtCity++;
}
void Warrior::beforeCity() {
    AtCity--;
}
/*
void Warrior::setType(int t) {
    type=t;
}
int Warrior::getType() {
    return type;
}
*/
int Warrior::minWeapon() {
    int min=3;
    for(int i=0;i<Weapon.size();i++){
        if(min>Weapon[i])
            min=Weapon[i];
    }
    return min;
}
int Warrior::firstWeapon() {
    return Weapon[0];
}
int Warrior::firstRemain() {
    return remain[0];
}
int Warrior::lastWeapon() {
    return Weapon[Weapon.size()-1];
}
int Warrior::lastRemain() {
    return remain[remain.size()-1];
}
int Warrior::deleteWeapon(int type) {
    int n=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==type){
            n++;
            Weapon.erase(Weapon.begin()+i);
            remain.erase(remain.begin()+i);
            i--;
        }
    }
    return n;
}
int Warrior::deleteAWeapon(int type){
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==type){
            int w=remain[i];
            Weapon.erase(Weapon.begin()+i);
            remain.erase(remain.begin()+i);
            i--;
            return w;
        }
    }
}
int Warrior::numberOfThisWeapon(int type){
    int n=0;
    for(int i : Weapon){
        if(i==type)
            n++;
    }
    return n;
}
int Warrior::weaponNumber() {
    return Weapon.size();
}
int Warrior::newArrow() {
    int num=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2 && remain[i]==2){
            num++;
        }
    }
    return num;
}
int Warrior::oldArrow() {
    int num=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2 && remain[i]==1){
            num++;
        }
    }
    return num;
}
int Warrior::deleteArrow() {
    int n=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2){
            n=remain[i];
            Weapon.erase(Weapon.begin()+i);
            remain.erase(remain.begin()+i);
            return n;
        }
    }
}
void Warrior::deleteNewArrow() {
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2&&remain[i]==2){
            Weapon.erase(Weapon.begin()+i);
            remain.erase(remain.begin()+i);
            return;
        }
    }
}
void Warrior::deleteOldArrow() {
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2&&remain[i]==1){
            Weapon.erase(Weapon.begin()+i);
            remain.erase(remain.begin()+i);
            return;
        }
    }
}
int Warrior::numberOfSword() {
    int num=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==0)
            num++;
    }
    return num;
}
int Warrior::numberOfBomb() {
    int num=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==1)
            num++;
    }
    return num;
}
int Warrior::numberOfArrow() {
    int num=0;
    for(int i=0;i<Weapon.size();i++){
        if(Weapon[i]==2)
            num++;
    }
    return num;
}
void Warrior::adjustWeapon() {
    for(int i=0;i<Weapon.size();i++){
        for(int j=0;j<Weapon.size()-1;j++){
            if(Weapon[j]>Weapon[j+1]){
                int w=Weapon[j+1];
                int u=remain[j+1];
                Weapon[j+1]=Weapon[j];
                remain[j+1]=remain[j];
                Weapon[j]=w;
                remain[j]=u;
            }
        }
    }
    int m=numberOfArrow();
    int n=Weapon.size();
    for(int i=n-m;i<n;i++){
        for(int j=n-m;i<n-1;i++){
            if(remain[j]>remain[j+1]){
                int w=Weapon[j+1];
                int u=remain[j+1];
                Weapon[j+1]=Weapon[j];
                remain[j+1]=remain[j];
                Weapon[j]=w;
                remain[j]=u;
            }
        }
    }
}
int Warrior::fight(int *n,int *number,int atk,int* same) {
    int type=Weapon[*n];
    if(type==0){
        return int(ATK*0.2);
    }else if(type==1){
        remain[*n]--;
        remain.erase(remain.begin()+*n);
        Weapon.erase(Weapon.begin()+*n);
        (*number)--;
        (*n)--;
        this->HP-=int(atk*int(ATK*0.4)*0.5); //反噬的生命值
        *same=-1;
        return int(ATK*0.4);
    }else if(type==2){
        remain[*n]--;
        if(remain[*n]==0){
            remain.erase(remain.begin()+*n);
            Weapon.erase(Weapon.begin()+*n);
            (*number)--;
            (*n)--;
        }
        *same=-1;
        return int(ATK*0.3);
    }
}