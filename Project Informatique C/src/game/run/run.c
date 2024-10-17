#include "run.h"
#include "../../src/utils/coordinates/coords.h"
#include "../../src/utils/qol/timer.h"
#include "../../src/game/player/playerQol.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void goUp(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x - 2, y);
    printf("%c", player);
}
void goDown(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x + 2, y);
    printf("%c", player);
}
void goLeft(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x, y - 4);
    printf("%c", player);
}
void goRight(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x, y + 4);
    printf("%c", player);
}

void goUpBoosted(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x - 4, y);
    printf("%c", player);
}
void goDownBoosted(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x + 4, y);
    printf("%c", player);
}
void goLeftBoosted(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x, y - 8);
    printf("%c", player);
}
void goRightBoosted(int x, int y, char player)
{
    gotoligcol(x, y);
    printf("+");

    gotoligcol(x, y + 8);
    printf("%c", player);
}

int legitCheck(int x1, int y1, int x2, int y2, char movement)
{
    cleanup();
    gotoligcol(20, 0);

    switch (movement)
    {
    case 'r':
        if ((y1 + 4 != y2))
        {
            if (y1 + 4 <= 36)
            {
                if (getCharAtPos(x1, y1 + 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        if (x1 == x2)
        {
            if (y1 + 8 <= 36)
            {
                if (getCharAtPos(x1, y1 + 6) == '#' || getCharAtPos(x1, y1 + 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 2;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        else
        {
            if (y1 + 4 <= 36)
            {
                if (getCharAtPos(x1, y1 + 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
    case 'l':
        if (y1 - 4 != y2)
        {
            if (y1 - 4 >= 4)
            {
                if (getCharAtPos(x1, y1 - 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        if (x1 == x2)
        {
            if (y1 - 8 >= 4)
            {
                if (getCharAtPos(x1, y1 - 6) == '#' || getCharAtPos(x1, y1 - 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 2;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        else
        {
            if (y1 - 4 >= 4)
            {
                if (getCharAtPos(x1, y1 - 2) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
    case 'u':
        if (x1 - 2 != x2)
        {
            if (x1 - 2 >= 2)
            {
                if (getCharAtPos(x1 - 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        if (y1 == y2)
        {
            if (x1 - 4 >= 2)
            {
                if (getCharAtPos(x1 - 3, y1) == '#' || getCharAtPos(x1 - 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 2;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        else
        {
            if (x1 - 2 >= 2)
            {
                if (getCharAtPos(x1 - 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
    case 'd':
        if (x1 + 2 != x2)
        {
            if (x1 + 2 <= 18)
            {
                if (getCharAtPos(x1 + 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        if (y1 == y2)
        {
            if (x1 + 4 <= 18)
            {
                if (getCharAtPos(x1 + 3, y1) == '#' || getCharAtPos(x1 + 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 2;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }
        else
        {
            if (x1 + 2 <= 18)
            {
                if (getCharAtPos(x1 + 1, y1) == '#')
                {
                    gotoligcol(12, 50);
                    printf("There is a wall !");
                    Sleep(2000);
                    gotoligcol(12, 50);
                    printf("                                    ");
                    return 0;
                }
                return 1;
            }
            else
            {
                gotoligcol(12, 50);
                printf("You can't go outside the map !");
                Sleep(2000);
                gotoligcol(12, 50);
                printf("                                    ");
                return 0;
            }
        }

    default:
        return 0;
    }
}

bool winner(bool quoicouVariable, int x1, int x2, char* firstPlayer, char* secondPlayer)
{
    if (quoicouVariable)
    {
        if (x1 == 18)
        {
            cleanup();
            gotoligcol(12, 50);
            printf("You won, %s", firstPlayer);
            return true;
        }
        if (x2 == 2)
        {
            cleanup();
            gotoligcol(12, 50);
            printf("You won, %s", secondPlayer);
            return true;
        }
    }
    else
    {
        if (x1 == 2)
        {
            cleanup();
            gotoligcol(12, 50);
            printf("You won, %s", firstPlayer);
            return true;
        }
        if (x2 == 18)
        {
            cleanup();
            gotoligcol(12, 50);
            printf("You won, %s", secondPlayer);
            return true;
        }
    }
    return false;
}

void setHeader(char* firstPlayer, char* secondPlayer, char firstPlayerChar, char secondPlayerChar)
{
    gotoligcol(4, 50);
    printf("%s", firstPlayer);

    gotoligcol(4, 50 + strlen(firstPlayer));
    printf("(%c) VS (%c)", firstPlayerChar, secondPlayerChar);

    gotoligcol(4, 50 + strlen(firstPlayer) + 11);
    printf("%s", secondPlayer);
}

void setWalls(int x, int y)
{
    gotoligcol(x, y);
    printf("#");
}

void run2players(const short choice, char* player1, char* player2, char character1, char character2)
{
    char firstPlayer[25];
    char secondPlayer[25];

    char firstPlayerChar;
    char secondPlayerChar;

    int firstPlayerWalls = 20;
    int secondPlayerWalls = 20;

    int posFirstPlayer[2] = { 2, 20 };
    int posSecondPlayer[2] = { 18, 20 };

    bool quoicouVariable;

    if (choice == 0)
    {
        strcpy_s(firstPlayer, sizeof(firstPlayer), player1);
        strcpy_s(secondPlayer, sizeof(secondPlayer), player2);
        firstPlayerChar = character1;
        secondPlayerChar = character2;
        posFirstPlayer[0] = 2;
        posFirstPlayer[1] = 20;
        posSecondPlayer[0] = 18;
        posSecondPlayer[1] = 20;
        quoicouVariable = true;
    }
    else
    {
        strcpy_s(firstPlayer, sizeof(firstPlayer), player2);
        strcpy_s(secondPlayer, sizeof(secondPlayer), player1);
        firstPlayerChar = character2;
        secondPlayerChar = character1;
        posFirstPlayer[0] = 18;
        posFirstPlayer[1] = 20;
        posSecondPlayer[0] = 2;
        posSecondPlayer[1] = 20;
        quoicouVariable = false;
    }

    setHeader(firstPlayer, secondPlayer, firstPlayerChar, secondPlayerChar);

    while (!winner(quoicouVariable, posFirstPlayer[0], posSecondPlayer[0], firstPlayer, secondPlayer))
    {
        char buffer, movement;
        int score = 0;

        for (int playerTurn = 0; playerTurn < 2; playerTurn++) 
        {
            char* currentPlayer = (playerTurn == 0) ? firstPlayer : secondPlayer;
            int* currentPlayerPos = (playerTurn == 0) ? posFirstPlayer : posSecondPlayer;
            int* opponentPlayerPos = (playerTurn == 0) ? posSecondPlayer : posFirstPlayer;
            int* currentPlayerWalls = (playerTurn == 0) ? &firstPlayerWalls : &secondPlayerWalls;
            char currentPlayerChar = (playerTurn == 0) ? firstPlayerChar : secondPlayerChar;

            gotoligcol(8, 50);
            printf("Score : %d", score);

            gotoligcol(6, 50);
            printf("                                    ");
            gotoligcol(6, 50);
            printf("Turn: %s", currentPlayer);

            gotoligcol(10, 50);
            printf("                                    ");
            gotoligcol(10, 50);
            printf("Walls left: %d", *currentPlayerWalls);

            do {
                cleanup();
                gotoligcol(20, strlen(currentPlayer) + 37);
                printf("             ");

                gotoligcol(20, 0);
                printf("It's your turn %s", currentPlayer);
                gotoligcol(20, strlen(currentPlayer) + 14);
                printf(" move = m, place = p : ");
                scanf_s("%c", &buffer, 2);
            } while (buffer != 'm' && buffer != 'p');

            if (buffer == 'm') {
                do 
                {
                    cleanup();
                    gotoligcol(20, 0);
                    printf("How do you want to move ?\n");
                    printf("Up : u\n");
                    printf("Down : d\n");
                    printf("Right : r\n");
                    printf("Left : l\n");
                    scanf_s(" %c", &movement, 2);
                } while (legitCheck(currentPlayerPos[0], currentPlayerPos[1], opponentPlayerPos[0], opponentPlayerPos[1], movement) == 0);
                   

                int moveType = legitCheck(currentPlayerPos[0], currentPlayerPos[1], opponentPlayerPos[0], opponentPlayerPos[1], movement);

                if (moveType == 1 || moveType == 2) {
                    int step = (moveType == 1) ? 4 : 8;

                    switch (movement) {
                    case 'r':
                        if (moveType == 1)
                            goRight(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        else
                            goRightBoosted(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        currentPlayerPos[1] += step;
                        break;
                    case 'l':
                        if (moveType == 1)
                            goLeft(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        else
                            goLeftBoosted(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        currentPlayerPos[1] -= step;
                        break;
                    case 'u':
                        if (moveType == 1)
                            goUp(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        else
                            goUpBoosted(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        currentPlayerPos[0] -= step / 2;
                        break;
                    case 'd':
                        if (moveType == 1)
                            goDown(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        else
                            goDownBoosted(currentPlayerPos[0], currentPlayerPos[1], currentPlayerChar);
                        currentPlayerPos[0] += step / 2;
                        break;
                    default:
                        break;
                    }
                }
            }
            if (buffer == 'p')
            {
                
            }
        }
    }
}


//test