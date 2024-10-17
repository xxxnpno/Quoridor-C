#include "settings.h"
#include "../../src/base/base.h"
#include "../../src/game/init/newGame.h"

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

char options()
{
    char choice;
    system("cls");

    do
    {
        printf("\t\t   /$$$$$$                                /$$       /$$                    \n");
        printf("\t\t  /$$__  $$                              |__/      | $$                    \n");
        printf("\t\t | $$  \\ $$ /$$   /$$  /$$$$$$   /$$$$$$  /$$  /$$$$$$$  /$$$$$$   /$$$$$$ \n");
        printf("\t\t | $$  | $$| $$  | $$ /$$__  $$ /$$__  $$| $$ /$$__  $$ /$$__  $$ /$$__  $$\n");
        printf("\t\t | $$  | $$| $$  | $$| $$  \\ $$| $$  \\__/| $$| $$  | $$| $$  \\ $$| $$  \\__/\n");
        printf("\t\t | $$/$$ $$| $$  | $$| $$  | $$| $$      | $$| $$  | $$| $$  | $$| $$      \n");
        printf("\t\t |  $$$$$$/|  $$$$$$/|  $$$$$$/| $$      | $$|  $$$$$$$|  $$$$$$/| $$      \n");
        printf("\t\t  \\____ $$$ \\______/  \\______/ |__/      |__/ \\_______/ \\______/ |__/      \n");
        printf("\t\t       \\__/                                                                \n");

        printf("\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   | [1] New Game           |\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   | [2] Continue Last Game |\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   | [3] Rules              |\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   | [4] Scores             |\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   ==========================\n");
        printf("\t\t\t\t\t   | [5] Exit               |\n");
        printf("\t\t\t\t\t   ==========================\n");

        choice = _getch();
        system("cls");

    } while (choice < '1' || choice > '5');

    return choice;
}

void printRules()
{
    system("cls");

    printf("Welcome to Quoridor!\n\n");

    printf("Objective:\n");
    printf("The goal of Quoridor is to be the first player to move their pawn from one side of the board to the opposite side.\n\n");

    printf("Setup:\n");
    printf("1. The game is played on a 9x9 board.\n");
    printf("2. Each player starts with a pawn in the center of the first row on their side of the board.\n");
    printf("3. Each player is given 10 walls (or fences) to use during the game.\n\n");

    printf("Gameplay:\n");
    printf("1. Players take turns, either moving their pawn or placing a wall.\n");
    printf("2. Pawns move one space at a time, horizontally or vertically, but cannot move through walls.\n");
    printf("3. Walls are placed between two squares to block an opponent’s movement but cannot completely block a player's path to the opposite side.\n");
    printf("4. If two pawns face each other, the player can jump over the opponent's pawn to the adjacent square.\n");
    printf("5. If there is a wall behind the opponent’s pawn, the player must move to one of the adjacent side squares.\n\n");

    printf("Winning the Game:\n");
    printf("The first player to reach any square on the opposite side of the board wins!\n");

    printf("\nPress any key to exit rules");

    _getch();

    system("cls");
    Init();
}

void start(char choice)
{
    switch (choice)
    {
    case '1':
        newGame();
        break;
    case '2':
        break;
    case '3':
        printRules();
        break;
    case '4':
        break;
    case '5':
        system("exit");
        break;
    default:
        break;
    }
}
