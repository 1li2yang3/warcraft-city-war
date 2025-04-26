#include "Headquarter.h"
Headquarter::Headquarter(int totalLife,string str) {
    this->name=str; //指挥部名字
    this->totalLife=totalLife; //生命元数量
    numberOfWarrior=0;
    numberOfDragon=0;
    numberOfNinja=0;
    numberOfIceman=0;
    numberOfLion=0;
    numberOfWolf=0;
}
Headquarter::~Headquarter() {}
void Headquarter::decreaseTotalLife(int Dlife) {
    totalLife-=Dlife; //创建士兵的时候，减少生命元
}
int Headquarter::getTotalLife() {
    return totalLife;
}
void Headquarter::increaseWarrior() {
    numberOfWarrior++;
}
void Headquarter::increaseDragon() {
    numberOfDragon++;
}
void Headquarter::increaseNinja() {
    numberOfNinja++;
}
void Headquarter::increaseIceman() {
    numberOfIceman++;
}
void Headquarter::increaseLion() {
    numberOfLion++;
}
void Headquarter::increaseWolf() {
    numberOfWolf++;
}
int Headquarter::getNumberOfDragon() {
    return numberOfDragon;
}
int Headquarter::getNumberOfLion() {
    return numberOfLion;
}
int Headquarter::getNumberOfNinja() {
    return numberOfNinja;
}
int Headquarter::getNumberOfIceman() {
    return numberOfIceman;
}
int Headquarter::getNumberOfWolf() {
    return numberOfWolf;
}
int Headquarter::getNumberOfWarrior() {
    return numberOfWarrior;
}
string Headquarter::getName(){
    return name;
}
string Headquarter::getWeaponName(int n) {
    if(n==0){
        return "sword";
    }else if(n==1){
        return "bomb";
    }else if(n==2){
        return "arrow";
    }else{
        return NULL;
    }
}
void Headquarter::createWarrior(int type,int hp,int atk) {
    switch (type) {
        case 1: {
            Dragon *p = new Dragon(hp,atk); //创建武士
            //warrior[numberOfWarrior] = p;
            warrior.push_back(p);  //武士储存
            dragon.push_back(p);
            decreaseTotalLife(hp);  //扣除生命元
            increaseDragon(); //数量增加
            increaseWarrior();  //数量增加
            p->setWeaponType(numberOfWarrior%3); //设置武器
            p->setMorale(1.0*getTotalLife()/hp);  //设置士气值
            p->setNum(getNumberOfWarrior());  //设置编号
            p->setAtCity(0);  //设置城市位置
            cout << " " << getName() << " dragon " << getNumberOfWarrior() << " born" << endl;
            break;
        }
        case 2: { //后面同理
            Ninja *p = new Ninja(hp,atk);
            //warrior[numberOfWarrior] = p;
            warrior.push_back(p);
            decreaseTotalLife(hp);
            increaseNinja();
            increaseWarrior();
            p->setWeaponType1(numberOfWarrior%3);
            p->setWeaponType2((numberOfWarrior+1)%3);
            p->setNum(getNumberOfWarrior());
            p->setAtCity(0);
            cout << " " << getName() << " ninja " << getNumberOfWarrior() << " born" << endl;
            break;
        }
        case 3: {
            Iceman *p = new Iceman(hp,atk);
            //warrior[numberOfWarrior] = p;
            warrior.push_back(p);
            iceman.push_back(p);
            decreaseTotalLife(hp);
            increaseIceman();
            increaseWarrior();
            p->setWeaponType(numberOfWarrior%3);
            p->setNum(getNumberOfWarrior());
            p->setAtCity(0);
            cout << " " << getName() << " iceman " << getNumberOfWarrior() << " born" << endl;
            break;
        }
        case 4: {
            Lion *p = new Lion(hp,atk);
            //warrior[numberOfWarrior] = p;
            warrior.push_back(p);
            lion.push_back(p);
            decreaseTotalLife(hp);
            increaseLion();
            increaseWarrior();
            p->setWeaponType(numberOfWarrior%3);
            p->setLoyalty(getTotalLife());
            p->setNum(getNumberOfWarrior());
            p->setAtCity(0);
            cout << " " << getName() << " lion " << getNumberOfWarrior() << " born" << endl;
            cout<<"Its loyalty is "<<p->getLoyalty()<<endl;
            break;
        }
        case 5: {
            Wolf *p = new Wolf(hp,atk);
            //warrior[numberOfWarrior] = p;
            warrior.push_back(p);
            wolf.push_back(p);
            decreaseTotalLife(hp);
            increaseWolf();
            increaseWarrior();
            p->setNum(getNumberOfWarrior());
            p->setAtCity(0);
            cout << " " << getName() << " wolf " << getNumberOfWarrior() << " born" << endl;
            break;
        }
    }
}
void Headquarter::checkLion(int hour,int minutes,Headquarter &headquarter,int n) {//检查lion是否逃跑
    for(int t=0;t<n;t++){//遍历城市
        for(int i=0;i<lion.size();i++){//red的lion
            Lion* p=dynamic_cast<Lion*>(lion[i]);
            if(p->getAtCity()==t+1){//如果在目标城市
                if(p->getLoyalty()<=0){//如果忠诚度小于等于0
                    cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                    cout<<" "<<getName()<<" lion "<<p->getNum()<<" ran away"<<endl;
                    lion.erase(lion.begin()+i);//删除lion

                    i--;//遍历目标递减
                    numberOfWarrior--;//数量减少
                    numberOfLion--;
                    for(int j=0;j<warrior.size();j++){
                        Warrior* q=warrior[j];
                        if(q->getNum()==p->getNum()) { //在warrior中找到对应的lion
                            warrior.erase(warrior.begin() + j);//删除warrior的lion
                            //delete q;
                            break;
                        }
                    }
                    //delete p;
                }
                break;
            }
        }
        //另一个指挥部也是如此
        for(int i=0;i<headquarter.lion.size();i++){
            Lion* p=dynamic_cast<Lion*>(headquarter.lion[i]);
            if(p->getAtCity()==t+1){
                if(p->getLoyalty()<=0){
                    cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                    cout<<" "<<headquarter.getName()<<" lion "<<p->getNum()<<" ran away"<<endl;
                    headquarter.lion.erase(headquarter.lion.begin()+i);
                    i--;
                    headquarter.numberOfWarrior--;
                    headquarter.numberOfLion--;
                    for(int j=0;j<headquarter.warrior.size();j++){
                        Lion* q=dynamic_cast<Lion*>(headquarter.warrior[j]);
                        if(q->getNum()==p->getNum()) {
                            headquarter.warrior.erase(headquarter.warrior.begin() + j);
                            //delete q;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}
void Headquarter::goNextCity(int n,int k) {//去下一个城市
    for(int i=0;i<warrior.size();i++){
        Warrior* p=warrior[i];
        if(p->getAtCity()==0){//如果是0，设置初始位置
            if(this->name=="red"){
                p->setAtCity(1);
            }else if(this->name=="blue"){
                p->setAtCity(n);
            }
        }else if(this->name=="red" && p->getAtCity()==n){//如果到蓝色指挥中心，设置成n+1
            p->nextCity();
        }else if(this->name=="blue" && p->getAtCity()==1){//如果到红色指挥中心，设置成-1
            p->beforeCity();
            p->beforeCity();
        }else{
            if(this->name=="red"){
                p->nextCity();
            }else if(this->name=="blue"){
                p->beforeCity();
            }
        }
    }
    for(int j=0;j<lion.size();j++){
        Lion* q=lion[j];
        q->setLoyalty(q->getLoyalty()-k);//lion的忠诚度扣除
    }
    for(int j=0;j<iceman.size();j++){
        Iceman* q=iceman[j];
        q->setHP(q->getHP()-int(q->getHP()*0.1));//iceman的生命值扣除
    }
}

void Headquarter::reportCity(int hour, int minutes, Headquarter &headquarter, int n,int* isEnd) {
    int u=0;
    for(int i=0;i<headquarter.warrior.size();i++){//蓝色士兵是否到红色指挥中心，因为红色指挥部在最左边
        if(headquarter.warrior[i]->getAtCity()==-1){
            Warrior* p=headquarter.warrior[i];
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
            cout<<" "<<headquarter.getName()<<" ";
            cout<<p->getType()<<" "<<p->getNum();
            cout<<" reached red headquarter";
            cout<<" with "<<p->getHP()<<" elements and force "<<p->getATK()<<endl;
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" red headquarter was taken"<<endl;
            *isEnd=-1; //蓝方胜利是-1
            u++;
            break;
        }
    }
    for(int t=0;t<n;t++){ //遍历城市，从小到达
        for(int i=0;i<warrior.size();i++){
            Warrior* p=warrior[i];
            if(p->getAtCity()==t+1){ //从所有的士兵中找到有没有这个城市的，先是红色，后面的是蓝色的同理
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                cout<<" "<<this->getName()<<" ";
                cout<<p->getType()<<" "<<p->getNum();
                cout<<" marched to city "<<p->getAtCity();
                cout<<" with "<<p->getHP()<<" elements and force "<<p->getATK()<<endl;
            }
        }
        for(int i=0;i<headquarter.warrior.size();i++){
            Warrior* p=headquarter.warrior[i];
            if(p->getAtCity()==t+1){
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                cout<<" "<<headquarter.getName()<<" ";
                cout<<p->getType()<<" "<<p->getNum();
                cout<<" marched to city "<<p->getAtCity();
                cout<<" with "<<p->getHP()<<" elements and force "<<p->getATK()<<endl;
            }
        }
    }
    for(int i=0;i<warrior.size();i++){
        if(warrior[i]->getAtCity()==n+1){
            Warrior* p=warrior[i];
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
            cout<<" "<<this->getName()<<" ";
            cout<<p->getType()<<" "<<p->getNum();
            cout<<" reached blue headquarter";
            cout<<" with "<<p->getHP()<<" elements and force "<<p->getATK()<<endl;
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" blue headquarter was taken"<<endl;
            *isEnd=1; //红方胜利是1
            u++;
            break;
        }
    }
    if(u==2){ //如果两边同时都到了对方的指挥部，为2
        *isEnd=2;
    }
}

void Headquarter::fightForWeapon(int hour, int minutes,Headquarter &headquarter,int n) {
    for(int t=0;t<n;t++){//从城市小的开始遍历
        for(int i=0;i<wolf.size();i++){
            Wolf* p=wolf[i];
            if(p->getAtCity()==t+1){//看Wolf是不是在对应的城市中
                for(int j=0;j<headquarter.warrior.size();j++){ //看对方的士兵
                    Warrior* q=dynamic_cast<Warrior*>(headquarter.warrior[j]);
                    if(p->getAtCity()==q->getAtCity()){ //对方的士兵在不在这个城市中
                        if(q->getTypeName()==5) //如果也是狼，就放弃
                            break;
                        else if(q->getTypeName()==4||q->getTypeName()==3 ||q->getTypeName()==2 || q->getTypeName()==1){
                            int number=0;
                            if(q->weaponNumber()<=0) //获取武器的数量
                                break; //如果对面没有武器，就直接放弃
                            int type=q->minWeapon(); //获取对面编号最小的武器
                            if(type==3) //没有3这个武器，进一步保证安全性
                                continue;//其实break是一样的，因为一个城市最多只能有俩士兵
                            if(type==0 || type==1){ //如果不是2号武器
                                int get=q->numberOfThisWeapon(type); //对面的武器减少
                                int beforeHave=p->weaponNumber(); //先获取我方拥有的武器数量
                                if(10-beforeHave>=get){  //如果还能装备的武器数量比抢来的多
                                    number=get; //就直接抢完所有的
                                    if(type==0){ //如果是0
                                        for(int w=0;w<get;w++){
                                            q->deleteAWeapon(type);
                                            p->addWeapon(0,99999); //可以无限次使用
                                        }

                                    }else if(type==1){
                                        for(int w=0;w<get;w++) {
                                            q->deleteAWeapon(type);
                                            p->addWeapon(1, 1);  //只能使用一次
                                        }
                                    }
                                }else{  //如果能装备的数量比抢到的要少
                                    number=10-beforeHave;  //看能抢到多少
                                    if(type==0){
                                        for(int w=beforeHave;w<10;w++) {
                                            q->deleteAWeapon(type);
                                            p->addWeapon(0, 99999);
                                        }
                                    }else if(type==1){
                                        for(int w=beforeHave;w<10;w++){
                                            q->deleteAWeapon(type);
                                            p->addWeapon(1,1);
                                        }
                                    }
                                }
                            }
                            else if(type==2){
                                int newArrow=q->newArrow(); //获取没有用过的数量
                                int oldArrow=q->oldArrow(); //获取用过一次的数量
                                int beforeHave=p->weaponNumber(); //看看还能装备多少
                                if(10-beforeHave>=newArrow+oldArrow){ //如果还能装备的比新的加旧的还多，就直接装备
                                    number=newArrow+oldArrow;
                                    for(int w=0;w<newArrow+oldArrow;w++){
                                        int remain=q->deleteArrow(); //删除对方的武器，并且获得剩余的使用次数
                                        p->addWeapon(2,remain);
                                    }
                                }
                                else if(10-beforeHave<=newArrow){ //如果剩余装备的比新的还少，只用新的装满就可以
                                    number=10-beforeHave;
                                    for(int w=0;w<10-beforeHave;w++){
                                        q->deleteNewArrow();
                                        p->addWeapon(2,2);
                                    }
                                }
                                else if(10-beforeHave>newArrow && 10-beforeHave<newArrow+oldArrow){ //如果在这两者之间
                                    number=10-beforeHave;
                                    for(int w=0;w<newArrow;i++){ //先让新的装满
                                        q->deleteNewArrow();
                                        p->addWeapon(2,2);
                                    }
                                    for(int w=0;w<10-p->weaponNumber();w++){ //剩下的用旧的装
                                        q->deleteOldArrow();
                                        p->addWeapon(2,1);
                                    }
                                }
                            }
                            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                            cout<<" "<<this->getName()<<" ";
                            cout<<"wolf "<<p->getNum()<<" took "<<number<<" ";
                            if(type==0)
                                cout<<"sword";
                            else if(type==1)
                                cout<<"bomb";
                            else if(type==2)
                                cout<<"arrow";
                            cout<<" from "<<headquarter.getName()<<" "<<q->getType()<<" "<<q->getNum()<<" in city "<<p->getAtCity()<<endl;
                        }
                        break;
                    }
                }
            }

        }

        for(int i=0;i<headquarter.wolf.size();i++){
            Wolf* p=headquarter.wolf[i];
            if(p->getAtCity()==t+1){
                for(int j=0;j<warrior.size();j++){
                    Warrior* q=dynamic_cast<Warrior*>(warrior[j]);
                    if(p->getAtCity()==q->getAtCity()){
                        if(q->getTypeName()==5)
                            break;
                        else if(q->getTypeName()==4||q->getTypeName()==3 ||q->getTypeName()==2 || q->getTypeName()==1){
                            int number=0;
                            int type=q->minWeapon();
                            if(type==3)
                                continue;//其实break是一样的，因为一个城市最多只能有俩士兵
                            if(type==0 || type==1){
                                int get=q->numberOfThisWeapon(type); //对面的武器减少
                                int beforeHave=p->weaponNumber(); //先获取我方拥有的武器数量
                                if(10-beforeHave>=get){  //如果还能装备的武器数量比抢来的多
                                    number=get; //就直接抢完所有的
                                    if(type==0){ //如果是0
                                        for(int w=0;w<get;w++){
                                            q->deleteAWeapon(type);
                                            p->addWeapon(0,99999); //可以无限次使用
                                        }
                                    }else if(type==1){
                                        for(int w=0;w<get;w++) {
                                            q->deleteAWeapon(type);
                                            p->addWeapon(1, 1);  //只能使用一次
                                        }
                                    }
                                }else{
                                    number=10-beforeHave;
                                    if(type==0){
                                        for(int w=beforeHave;w<10;w++) {
                                            q->deleteAWeapon(type);
                                            p->addWeapon(0, 99999);
                                        }
                                    }else if(type==1){
                                        for(int w=beforeHave;w<10;w++){
                                            q->deleteAWeapon(type);
                                            p->addWeapon(1,1);
                                        }
                                    }
                                }
                            }
                            else if(type==2){
                                int newArrow=q->newArrow();
                                int oldArrow=q->oldArrow();
                                int beforeHave=p->weaponNumber();
                                if(10-beforeHave>=newArrow+oldArrow){
                                    number=newArrow+oldArrow;
                                    for(int w=0;w<newArrow+oldArrow;w++){
                                        int remain=q->deleteArrow();
                                        p->addWeapon(2,remain);
                                    }
                                }
                                else if(10-beforeHave<=newArrow){
                                    number=10-beforeHave;
                                    for(int w=0;w<10-beforeHave;w++){
                                        q->deleteNewArrow();
                                        p->addWeapon(2,2);
                                    }
                                }
                                else if(10-beforeHave>newArrow && 10-beforeHave<newArrow+oldArrow){
                                    number=10-beforeHave;
                                    for(int w=0;w<newArrow;i++){
                                        q->deleteNewArrow();
                                        p->addWeapon(2,2);
                                    }
                                    for(int w=0;w<10-p->weaponNumber();w++){
                                        q->deleteOldArrow();
                                        p->addWeapon(2,1);
                                    }
                                }
                            }
                            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                            cout<<" "<<headquarter.getName()<<" ";
                            cout<<"wolf "<<p->getNum()<<" took "<<number<<" ";
                            if(type==0)
                                cout<<"sword";
                            else if(type==1)
                                cout<<"bomb";
                            else if(type==2)
                                cout<<"arrow";
                            cout<<" from "<<this->getName()<<" "<<q->getType()<<" "<<q->getNum()<<" in city "<<p->getAtCity()<<endl;
                        }
                        break;
                    }
                }
            }

        }
    }
}
void Headquarter::reportWeapon(int hour, int minutes,Headquarter &headquarter,int n) {
    for(int t=0;t<n;t++){ //从城市开始遍历
        for(int i=0;i<warrior.size();i++){
            if(warrior[i]->getAtCity()==t+1){
                Warrior* p=warrior[i];
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                cout<<" "<<this->getName()<<" "<<p->getType()<<" "<<p->getNum()<<" has "<<p->numberOfSword()<<" sword "<<p->numberOfBomb()<<" bomb "
                    <<p->numberOfArrow()<<" arrow and "<<p->getHP()<<" elements"<<endl;
                break;
            }
        }
        for(int i=0;i<headquarter.warrior.size();i++){
            if(headquarter.warrior[i]->getAtCity()==t+1){
                Warrior* p=headquarter.warrior[i];
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                cout<<" "<<headquarter.getName()<<" "<<p->getType()<<" "<<p->getNum()<<" has "<<p->numberOfSword()<<" sword "<<p->numberOfBomb()<<" bomb "
                    <<p->numberOfArrow()<<" arrow and "<<p->getHP()<<" elements"<<endl;
                break;
            }
        }
    }
}
void Headquarter::warriorYell(int hour, int minutes,Headquarter &headquarter,int n) {
    for(int t=0;t<n;t++){
        for(int i=0;i<dragon.size();i++){
            Dragon* p=dragon[i];
            for(int j=0;j<headquarter.warrior.size();j++){
                Warrior* q=headquarter.warrior[j];
                if(p->getAtCity()==t+1 && q->getAtCity()==t+1 && p->getHP()>0){ //我方生命值大于0，地方生命值小于0
                    cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                    cout<<" "<<this->getName()<<" "<<p->getType()<<" "<<p->getNum()<<" yelled in city "<<p->getAtCity()<<endl;
                    break;
                }
            }
        }
        for(int i=0;i<headquarter.dragon.size();i++){
            Dragon* p=headquarter.dragon[i];
            for(int j=0;j<warrior.size();j++){
                Warrior* q=warrior[j];
                if(p->getAtCity()==t+1 && q->getAtCity()==t+1 && p->getHP()>0){
                    cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                    cout<<" "<<headquarter.getName()<<" "<<p->getType()<<" "<<p->getNum()<<" yelled in city "<<p->getAtCity()<<endl;
                    break;
                }
            }
        }
    }

}
void Headquarter::adjustWeapon() {
    for(int i=0;i<warrior.size();i++){
        Warrior* p=warrior[i];
        p->adjustWeapon();
    }
}
void Headquarter::fight(Headquarter &headquarter){
    for(int i=0;i<warrior.size();i++){
        Warrior* p=warrior[i];
        for(int j=0;j<headquarter.warrior.size();j++){
            Warrior* q=headquarter.warrior[j];
            if(p->getAtCity()==q->getAtCity()){  //如果双方的城市相同，则开展
                if(q->getAtCity()%2==1) { //如果是奇数，红方先攻
                    int RWeaponNumber = p->numberOfArrow() + p->numberOfBomb() + p->numberOfSword();//获取武器数量
                    int RNowWeapon = 0;
                    int BWeaponNumber = q->numberOfArrow() + q->numberOfBomb() + q->numberOfSword();
                    int BNowWeapon = 0;
                    int RReAtk=1; //获取反噬的攻击力，就是敌方的攻击力
                    int BReAtk=1;
                    if(p->getTypeName()==2){  //如果是Ninja无反噬攻击力
                        RReAtk=0;
                    }
                    if(q->getTypeName()==2){
                        BReAtk=0;
                    }
                    int redHP=p->getHP();
                    int blueHP=q->getHP();
                    int same=0; //判断双方生命值不变的轮数，如果超过一定的轮数（最大的武器数量），认定为平
                    while (1) {//循环攻击
                        if(RWeaponNumber>0)//红方武器数量不为0
                            q->setHP(q->getHP() - p->fight(&RNowWeapon, &RWeaponNumber, RReAtk,&same));//红方攻击
                        if (q->getHP() <= 0)//蓝方是否死亡
                            break;
                        if (p->getHP() <= 0)//红方是否死亡
                            break;
                        if(BWeaponNumber>0)//蓝方武器数量不为0
                            p->setHP(p->getHP() - q->fight(&BNowWeapon, &BWeaponNumber, BReAtk,&same));//蓝方攻击
                        if (p->getHP() <= 0)//红方是否死亡
                            break;
                        if (q->getHP() <= 0)//蓝方是否死亡
                            break;
                        RNowWeapon++;//下一个武器
                        BNowWeapon++;//下一个武器
                        RWeaponNumber = p->numberOfArrow() + p->numberOfBomb() + p->numberOfSword();
                        BWeaponNumber = q->numberOfArrow() + q->numberOfBomb() + q->numberOfSword();
                        if (RNowWeapon >= RWeaponNumber)//武器是否重置
                            RNowWeapon = 0;
                        if (BNowWeapon >= BWeaponNumber)//武器是否重置
                            BNowWeapon = 0;
                        if(redHP==p->getHP() && blueHP==q->getHP()){
                            same++;
                        }else{
                            redHP=p->getHP();
                            blueHP=q->getHP();
                            same=0;
                        }
                        if(same>RWeaponNumber&&same>BWeaponNumber){
                            break;
                        }
                    }
                }
                //攻击顺序相反
                if(q->getAtCity()%2==0) {
                    int RWeaponNumber = p->numberOfArrow() + p->numberOfBomb() + p->numberOfSword();
                    int RNowWeapon = 0;
                    int BWeaponNumber = q->numberOfArrow() + q->numberOfBomb() + q->numberOfSword();
                    int BNowWeapon = 0;
                    int RReAtk=1;
                    int BReAtk=1;
                    if(p->getTypeName()==2){
                        RReAtk=0;
                    }
                    if(q->getTypeName()==2){
                        BReAtk=0;
                    }
                    int redHP=p->getHP();
                    int blueHP=q->getHP();
                    int same=0;
                    while (1) {
                        if(BWeaponNumber>0)//蓝方武器数量不为0
                            p->setHP(p->getHP() - q->fight(&BNowWeapon, &BWeaponNumber, BReAtk,&same));//蓝方攻击
                        if (p->getHP() <= 0)//红方是否死亡
                            break;
                        if (q->getHP() <= 0)//蓝方是否死亡
                            break;
                        if(RWeaponNumber>0)//红方武器数量不为0
                            q->setHP(q->getHP() - p->fight(&RNowWeapon, &RWeaponNumber, RReAtk,&same));//红方攻击
                        if (q->getHP() <= 0)//蓝方是否死亡
                            break;
                        if (p->getHP() <= 0)//红方是否死亡
                            break;
                        RNowWeapon++;//下一个武器
                        BNowWeapon++;//下一个武器
                        RWeaponNumber = p->numberOfArrow() + p->numberOfBomb() + p->numberOfSword();
                        BWeaponNumber = q->numberOfArrow() + q->numberOfBomb() + q->numberOfSword();
                        if (RNowWeapon >= RWeaponNumber)//武器是否重置
                            RNowWeapon = 0;
                        if (BNowWeapon >= BWeaponNumber)//武器是否重置
                            BNowWeapon = 0;
                        if(redHP==p->getHP() && blueHP==q->getHP()){
                            same++; //如果生命值保持不变
                        }else{
                            redHP=p->getHP();
                            blueHP=q->getHP();
                            same=0;
                        }
                        if(same>RWeaponNumber&&same>BWeaponNumber){
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}
void Headquarter::reportAlive(int hour,int minutes,Headquarter &headquarter,int n) {
    for(int t=1;t<=n;t++) {
        for (int i = 0; i < warrior.size(); i++) {
            Warrior *p = warrior[i];
            for (int j = 0; j < headquarter.warrior.size(); j++) {
                Warrior *q = headquarter.warrior[j];
                if (p->getAtCity() == q->getAtCity() && t==p->getAtCity()) {
                    cout << setw(3) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes;
                    if (p->getHP() > 0 && q->getHP() > 0) {
                        cout << " both " << getName() << " " << p->getType() << " " << p->getNum() << " and ";
                        cout << headquarter.getName() << " " << q->getType() << " " << q->getNum()
                             << " were alive in city " << p->getAtCity() << endl;
                    } else if (p->getHP() <= 0 && q->getHP() <= 0) {
                        cout << " both " << getName() << " " << p->getType() << " " << p->getNum() << " and ";
                        cout << headquarter.getName() << " " << q->getType() << " " << q->getNum()
                             << " died in city " << p->getAtCity() << endl;
                    } else if (p->getHP() > 0 && q->getHP() <= 0) {
                        cout << " " << getName() << " " << p->getType() << " " << p->getNum() << " killed ";
                        cout << headquarter.getName() << " " << q->getType() << " " << q->getNum() << " in city "
                             << p->getAtCity();
                        cout << " remaining " << p->getHP() << " elements" << endl;
                    } else if (p->getHP() <= 0 && q->getHP() > 0) {
                        cout << " " << headquarter.getName() << " " << q->getType() << " " << q->getNum() << " killed ";
                        cout << getName() << " " << p->getType() << " " << p->getNum() << " in city "
                             << p->getAtCity();
                        cout << " remaining " << q->getHP() << " elements" << endl;
                    }
                    if(p->getTypeName()==1 && p->getHP()>0){
                        cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                        cout<<" "<<this->getName()<<" "<<p->getType()<<" "<<p->getNum()<<" yelled in city "<<p->getAtCity()<<endl;
                    }
                    if(q->getTypeName()==1 && q->getHP()>0){
                        cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                        cout<<" "<<headquarter.getName()<<" "<<q->getType()<<" "<<q->getNum()<<" yelled in city "<<q->getAtCity()<<endl;
                    }
                }
            }
        }
    }
}
void Headquarter::getWeapon(Headquarter &headquarter) {
    for(int i=0;i<warrior.size();i++){
        Warrior* p=warrior[i];
        if(p->getHP()>0){
            for(int j=0;j<headquarter.warrior.size();j++){
                Warrior *q=headquarter.warrior[j];
                if(q->getAtCity()==p->getAtCity()){
                    if(q->getHP()<=0){
                        int num=p->weaponNumber();//因为战斗后的武器一定是经过排序的了，所以就不需要再排序了，直接获取就行
                        while(num<=10 && q->weaponNumber()>0){
                            if(q->firstWeapon()!=2 ){
                                p->addWeapon(q->firstWeapon(),q->firstRemain());
                                q->deleteAWeapon(q->firstWeapon());
                            }else{
                                p->addWeapon(q->lastWeapon(),q->lastRemain());//因为先抢没用过的，没用过的在后买你
                                if(q->lastRemain()==2)
                                    q->deleteNewArrow();
                                else
                                    q->deleteOldArrow();
                            }
                            num++;
                        }
                    }
                    break;
                }
            }
        }
    }
}
void Headquarter::clearDied() {
    for(int i=0;i<warrior.size();i++){
        if(warrior[i]->getHP()<=0){ //如果士兵生命值为负数，清理删除
            Warrior *p=warrior[i];
            warrior.erase(warrior.begin()+i);
            i--;
        }
    }
    for(int i=0;i<dragon.size();i++){
        if(dragon[i]->getHP()<=0){
            Dragon *p=dragon[i];
            dragon.erase(dragon.begin()+i);
            i--;
        }
    }
    for(int i=0;i<lion.size();i++){
        if(lion[i]->getHP()<=0){
            Lion *p=lion[i];
            lion.erase(lion.begin()+i);
            i--;
        }
    }
    for(int i=0;i<wolf.size();i++){
        if(wolf[i]->getHP()<=0){
            Wolf *p=wolf[i];
            wolf.erase(wolf.begin()+i);
            i--;
        }
    }
    for(int i=0;i<iceman.size();i++){
        if(iceman[i]->getHP()<=0){
            Iceman *p=iceman[i];
            iceman.erase(iceman.begin()+i);
            i--;
        }
    }
}