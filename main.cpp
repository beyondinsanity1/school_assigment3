#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class player{
private:
    int HP;
    string playerName;
    int weaponModifier;
public:
    player(int theHP);
    int weaponAttack();
    void setHP(int);
    int getHP();
    int heal();
};


player::player(int theHP){
    HP = theHP;
}

 void player::setHP(int theHP) {
     HP = theHP;
 }

 int player::getHP() {
     return HP;
 }

 int player::weaponAttack() {
     int upper = 10;
     int lower = 5;
     int weaponAttackValue = (rand()%(upper - lower + 1) + lower);
     weaponAttackValue = weaponAttackValue * weaponModifier;
     return weaponAttackValue;
 }

class enemy{
private:
    int enemyHP;
public:
    enemy(){};
    void enemyAttack();
};

void enemy::enemyAttack() {
    int upper = 20;
    int lower = 10;
    int enemyAttackValue = (rand()%(upper - lower + 1) + lower);
}

int main(){

    srand(time(NULL));
    player myplayer(200);

    cout << myplayer.getHP() <<endl;
    cout << myplayer.weaponAttack() <<endl;
    cout << enemy <<endl;


}