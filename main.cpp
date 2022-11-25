#include <iostream>
#include <string>
#include <ctime>
#include <random>


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
    int weaponAttack();
    void setHP(int);
    int getHP();
    void heal();
    int increaseWpnModifier();
    int getWpnModifier();
    void setPlayerName(string theName);
    basic_string<char, char_traits<char>, allocator<char>> getPlayerName();
};


class enemy{
private:
    int enemyHP;
public:
    enemy(int theHP);
    void enemyAttack();
    int getEnemyHP();
    void setEnemyHP(int);
};


player myPlayer(150);
enemy enemy(300);


player::player(int theHP){
    HP = theHP;
}

void player::setPlayerName(string theName){
    playerName = theName;
}

basic_string<char, char_traits<char>, allocator<char>> player::getPlayerName() {
    return playerName;
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
        cout << "You drank a potion and restored 25HP9!"
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


int player::weaponAttack() {
    int playerDamage;
    int enemyHP;
    int weaponAttackValue = (rand()%(10 - 5 + 1) + 5);
    weaponAttackValue = weaponAttackValue * weaponModifier;
    playerDamage = weaponAttackValue;
    enemyHP = enemy.getEnemyHP();
    enemyHP -= playerDamage;
    enemy.setEnemyHP(enemyHP);

    cout << "You dealt "<< playerDamage << " points of damage to your enemy! Your enemy now has " << enemyHP <<" HP."<<endl;
}



enemy::enemy(int theHP) {
    enemyHP = theHP;
}


int enemy::getEnemyHP() {
    return enemyHP;
}


void enemy::enemyAttack() {
    int enemyAttackValue = (rand()%(20 - 10 + 1) + 10);
    cout << "enemy rolled " << enemyAttackValue <<endl;
    int playerHP {0};
    if (enemyAttackValue == 13 || enemyAttackValue == 17){
        enemyAttackValue = 0;
    }

    playerHP = myPlayer.getHP();
    playerHP  -= enemyAttackValue;
    myPlayer.setHP(playerHP);

    if(enemyAttackValue == 0){
    cout << "Your enemy missed and dealt 0 damage!" << endl;
    }
    cout << "Your enemy dealt you " << enemyAttackValue << " damage! You now have " << playerHP << " HP." << endl;
}


int randomAction(){
    int a = 1+ (rand()%4);
    if (a == 1 || a == 4){
        cout << "Nothing Happened!?" << endl;
    } else if (a == 2){
        myPlayer.heal();
    }else if (a == 3){
        myPlayer.increaseWpnModifier();
        cout << "Your weapon now deals x" << myPlayer.getWpnModifier() << " damage!" << endl;
    }
    return 0;
}

void enemy::setEnemyHP(int theHP) {
    enemyHP = theHP;
}


int game(){
    int userTurnInput;
    bool playerLost {0};
    bool enemyLost {0};
    string name;

    cout << "What's your name?" << endl;
    cin >> name;
    myPlayer.setPlayerName(name);

    while (!playerLost && !enemyLost){
        int playerHP {myPlayer.getHP()};
        int enemyHP {enemy.getEnemyHP()};

        if(playerHP <= 0){
            playerLost = 1;
        }else if (enemyHP <= 0){
            enemyLost = 1;
        }

        if (!playerLost && !enemyLost) {
            cout << myPlayer.getPlayerName() << "'s HP: " << playerHP << "   Enemy's HP: " << enemyHP << endl;
            //PLAYER TURN////////////////////////////
            cout << "YOUR TURN!    ////////////////////////////" << endl;
            cout << "Choose your action!\n"
                    "1) Random Action\n"
                    "2) Weapon Attack" << endl;
            cin >> userTurnInput;

            if (userTurnInput == 1) {
                randomAction();
            } else if (userTurnInput == 2) {
                myPlayer.weaponAttack();
            }

            //ENEMY TURN////////////////////////////
            cout << "ENEMY TURN!    ////////////////////////////" << endl;
            enemy.enemyAttack();

        }else if (playerLost){
            cout << "///////////////////////////////////////\n"
                    "You lost! Get Gud!" <<endl;

//            cout << "Want to play again?" << endl;
//            cout << "1) PLAY AGAIN \n"
//                    "2) EXIT" <<endl;
//            cin >> userTurnInput;
//            if (userTurnInput == 1){
//                playerLost = false;
//                enemyLost = false;
//                game();
//            }else if (userTurnInput){
//                EXIT_SUCCESS;
//            }else{
//                cout << "Unknown input!" << endl;
//            }

        }else if (enemyLost){
            cout << "///////////////////////////////////////\n"
                    "YOU WON!\n"
                    "HERE'S A MEDAL!\n"
                    " _______________\n"
                    "|@@@@|     |####|\n"
                    "|@@@@|     |####|\n"
                    "|@@@@|     |####|\n"
                    "\\@@@@|     |####/\n"
                    " \\@@@|     |###/\n"
                    "  `@@|_____|##'\n"
                    "       (O)\n"
                    "    .-'''''-.\n"
                    "  .'  * * *  `.\n"
                    " :  *       *  :\n"
                    ": ~N O B O D Y~ :\n"
                    ": ~ C A R E S ~ :\n"
                    " :  *       *  :\n"
                    "  `.  * * *  .'\n"
                    "    `-.....-'" << endl;
        }

    }
    return 0;
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
return 0;
}

int main(){
    srand (time(NULL));
    menu();

}
