// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char field[10];
void singleplayer();
void multiplayer();
void help();
bool checkWin(char);
bool checkFull();
char keyInput(bool x);


void clearConsole() {
    //system("clear");
}

void resetField() {
    for (int i = 0; i < 10; i++) {
        field[i] = ' ';
    }
}

void menu() {
    while (true)
    {
        resetField();
        char inputmenu;
        cout << "\n\n"
            << "MENU\n\n"
            << "1: Singleplayer\n"
            << "2: Multiplayer\n"
            << "3: Help\n"
            << "4: Quit\n\n\n"
            << "Input: ";
        cin >> inputmenu;

        if (inputmenu == '1') singleplayer();
        else if (inputmenu == '2')multiplayer();
        else if (inputmenu == '3')help();
        else if (inputmenu == '4' || inputmenu == 'q')return;
        else { clearConsole(); cout << "\nInvalid Input!";}
    }
}
void drawField() {
    clearConsole();
    cout << "\n\n\n"
        << "     " << field[1] << " |  " << field[2] << "|" << field[3] << endl
        << "    ---|---|---" << endl
        << "     " << field[4] << " |  " << field[5] << "|" << field[6] << endl
        << "    ---|---|---" << endl
        << "     " << field[7] << " |  " << field[8] << "|" << field[9] << endl;
}

void singleplayer() {

}

void multiplayer() {
    char input = ' ';
    bool player1Turn = true;
    while (true)
    {
        drawField();
        if (checkWin('X'))
        {
            cout << "\nPlayer1 won\n\n";
            return;
        }
        else if (checkWin('O'))
        {
            cout << "\nPlayer2 won\n\n";
            return;
        }if (checkFull())
        {
            cout << "Tie\n\n";
        }
        input = keyInput(player1Turn);
        if (input=='q')
        {
            return;
        }
        player1Turn = !player1Turn;
    }
}

void help() {
    clearConsole();
    cout << "\n\n\nHELP\n\nSingleplayer:\nIn Singleplayermode you play against the computer\n\nMultiplayer:\nIn Multiplayerplayermode you play against second player" << endl;
    return;
}


char keyInput(bool x) {
    while (true)
    {
        cout << "\n\nInput: ";
        char input = ' ';
        cin >> input;
        int inputNumber = input - '0';
        if (input > 9 || input < 1)
        {
            if (input == 'q')
                return input;
            else
                cout << "\nInvalid Input!";
        }
        else if (field[inputNumber] != ' ') {
            cout << "\nThis field is already used\n";
        }
        else
        {
            if (x)
                field[inputNumber] = 'X';
            else
                field[inputNumber] = 'O';
            return input;
        }
    }
}
bool checkWin(char sign) {
    if (field[1] == sign && field[2] == sign && field[3] == sign
        || field[4] == sign && field[5] == sign && field[6] == sign
        || field[7] == sign && field[8] == sign && field[9] == sign
        || field[1] == sign && field[5] == sign && field[9] == sign
        || field[3] == sign && field[5] == sign && field[7] == sign
        || field[2] == sign && field[5] == sign && field[8] == sign
        || field[1] == sign && field[4] == sign && field[7] == sign
        || field[3] == sign && field[6] == sign && field[9] == sign
        ) {
        return true;
    }
        return false;
}
bool checkFull() {
    for (int i = 1;  i<= 9; i++)
    {
        if (field[i] == ' ') {
            return false;
        }
        return true;
    }
}
int main()
{
    srand(time(nullptr));
    menu();
    
    return 0;
}

