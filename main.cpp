#include <iostream>
#include <string>
#include <time.h>


// note Nov 17 2022 | 02:01 AM : all there is to do is to:
// - create the turns structure and logic
// - create enemy attack logic
// - display all health at all times


using namespace std;

class player{
private:
    int HP;
    string playerName;
    int weaponModifier {1};
    int potionCount {1};
public:
    player(int theHP);
    int playerWeaponAttack();
    void setHP(int);
    int getHP();
    void heal();
    int increaseWpnModifier();
    int getWpnModifier();
};

class enemy{
private:
    int enemyHP;
public:
    enemy(int theHP);
    int enemyAttack();
    int getEnemyHP();
    void setEnemyHP(int);
};

player myPlayer(150);
enemy enemy(300);

player::player(int theHP){
    HP = theHP;
}

void player::heal() {
    if (myPlayer.potionCount > 0) {
        int theHP;
        int newHp;
        theHP = myPlayer.getHP();
        newHp = theHP + 25;
        if (newHp > 200){
            newHp = 200;
            cout << "Your HP is maxed! You have 200 HP!" << endl;
        }
        cout << "You drank a potion!"
                "\nYour new HP is " << newHp << endl;
        myPlayer.setHP(newHp);
        myPlayer.potionCount -= 1;
    }else {
        cout << "You dont have any potions!" << endl;
    }
}

int player::increaseWpnModifier(){
    weaponModifier += 1;
    return weaponModifier;
}

int player::getWpnModifier() {
    return weaponModifier;
}

 void player::setHP(int theHP) {
     HP = theHP;
 }

 int player::getHP() {
     return HP;
 }

 int player::playerWeaponAttack() {
     int upper = 10;
     int lower = 5;
     int weaponAttackValue = (rand()%(upper - lower + 1) + lower);
     weaponAttackValue = weaponAttackValue * weaponModifier;
     return weaponAttackValue;
 }



enemy::enemy(int theHP) {
    enemyHP = theHP;
}

int enemy::getEnemyHP() {
    return enemyHP;
}

int enemy::enemyAttack() {
    int upper = 20;
    int lower = 10;
    int enemyAttackValue = (rand()%(upper - lower + 1) + lower);

    if (enemyAttackValue == 13 || 17){
        enemyAttackValue = 0;
    }

    return enemyAttackValue;
}

int randomAction(){
    int a = 1+ (rand()%4) ;
    if (a == 1 || a == 4){
        cout << "Nothing Happened!?" << endl;
    } else if (a == 2){
        myPlayer.heal();
    }else if (a == 3){
        myPlayer.increaseWpnModifier();
        cout << "your new weapon deals x" << myPlayer.getWpnModifier() << " damage!" << endl;
    }
}

void enemy::setEnemyHP(int theHP) {
    enemyHP = theHP;
}

int weaponAttack(){
    int playerDamage;
    int enemyHP;
    playerDamage = myPlayer.playerWeaponAttack();
    enemyHP = enemy.getEnemyHP();
    enemyHP -= playerDamage;
    enemy.setEnemyHP(enemyHP);

    cout << "You dealt "<< playerDamage << " points of damage! Your enemy now has " << enemyHP <<" HP.";
}


int game(){
    int userTurnInput;

    while (enemy.getEnemyHP() > 0 || myPlayer.getHP() > 0){
        cout << "Choose your action!\n"
                "1) Random Action\n"
                "2) Weapon Attack"<<endl;
        cin >> userTurnInput;

        if (userTurnInput == 1 ){
            randomAction();
        } else if (userTurnInput == 2) {
            weaponAttack();
        }
    }

};

int menu (){
    int userMenuInput;
    cout << "welcome to the game!"
            "\n 1) Play"
            "\n 2) Exit" << endl;

    cin >> userMenuInput;

    if (userMenuInput == 1){
        game();
    }else if (userMenuInput == 2){
        return 0;
    }
}

int main(){
    srand (time(NULL));
    menu();

}