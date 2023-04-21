#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
void randomDice(int dice[]);
void drawDice(int dice[]);
int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice[3] = { 0,0,0 };
    int winnumber = 0;
    char choice;
    srand(time(0)); 
    cout << "\n\t\t========WELCOME TO CASINO ARENA=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        do
        {
            cout << "Hey, " << playerName << ", enter amount to bet : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                << "\nRe-enter balance\n ";
        } while (bettingAmount > balance);
        do
        {
            cout << "Guess any betting number between 1 & 6 :";
            cin >> guess;
            if (guess <= 0 || guess > 6)
                cout << "\nNumber should be between 1 to 6\n"
                << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 6);
        randomDice(dice);
        winnumber = 0;
        for (int i = 0; i < 3; i++) {
            if (guess == dice[i])
                winnumber++;
        }
        if (winnumber==1) {
            cout << "\n\nYou are in luck!! You have won " << bettingAmount  << "$.";
            balance = balance + bettingAmount ;
        }
        else if (winnumber == 2) {
            cout << "\n \n Wow, now is your day!! You have won " << bettingAmount * 2 << "$.";
            balance = balance + bettingAmount * 2;
        }
        else if (winnumber == 3) {
            cout << "\n \n Did you create this game??? You have won " << bettingAmount * 3 << "$.";
                balance = balance + bettingAmount * 3;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice[0] << ","<<dice[1]<<" and "<<dice[2]<<".";
        drawDice(dice);
        cout << "\n" << playerName << ", You have balance of $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
void rules() {
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 6\n";
    cout << "\t2. Winner gets 2 or more times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
void randomDice(int dice[]) {
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        dice[i] = rand() % 6 + 1;
    }
}
void drawDice(int dice[]) {
    cout << "\n RESULT: " << endl;
    cout << " _____     _____     _____ " << endl;
    cout << "|     |   |     |   |     |" << endl;
    cout << "|  " << dice[0] << "  |   |  " << dice[1] << "  |   |  " << dice[2]<<"  |" << endl;
    cout << "|_____|   |_____|   |_____|" << endl;
}