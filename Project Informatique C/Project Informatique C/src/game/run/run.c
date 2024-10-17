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
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
        if (x1 == x2)
        {
            if (y1 + 8 <= 36)
            {
                printf("Valid move");
                return 2;
            }
            else
            {
                printf("Invalid move");
                return 3;
            }
        }
        else
        {
            if (y1 + 4 <= 36)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
    case 'l':
        if (y1 - 4 != y2)
        {
            if (y1 - 4 >= 4)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
        if (x1 == x2)
        {
            if (y1 - 8 >= 4)
            {
                printf("Valid move");
                return 2;
            }
            else
            {
                printf("Invalid move");
                return 3;
            }
        }
        else
        {
            if (y1 - 4 >= 4)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
    case 'u':
        if (x1 - 2 != x2)
        {
            if (x1 - 2 >= 2)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
        if (y1 == y2)
        {
            if (x1 - 4 >= 2)
            {
                printf("Valid move");
                return 2;
            }
            else
            {
                printf("Invalid move");
                return 3;
            }
        }
        else
        {
            if (x1 - 2 >= 2)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
    case 'd':
        if (x1 + 2 != x2)
        {
            if (x1 + 2 <= 18)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }

        }
        if (y1 == y2)
        {
            if (x1 + 4 <= 18)
            {
                printf("Valid move");
                return 2;
            }
            else
            {
                printf("Invalid move");
                return 3;
            }
        }
        else
        {
            if (x1 + 2 <= 18)
            {
                printf("Valid move");
                return 1;
            }
            else
            {
                printf("Invalid move");
                return 0;
            }
        }
    default:
        return 0;
    }
}

bool winner(bool quoicouVariavble, int x1, int x2, char* firstPlayer, char* secondPlayer)
{
    if (quoicouVariavble)
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

    bool quoicouVariavble;

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
        quoicouVariavble = true;
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
        quoicouVariavble = false;
    }

    gotoligcol(4, 50);
    printf("%s", firstPlayer);

    gotoligcol(4, 50 + strlen(firstPlayer));
    printf("(%c) VS (%c)", firstPlayerChar, secondPlayerChar);

    gotoligcol(4, 50 + strlen(firstPlayer) + 11);
    printf("%s", secondPlayer);

    while (!winner(quoicouVariavble, posFirstPlayer[0], posSecondPlayer[0], firstPlayer, secondPlayer))
    {
        char buffer, buffer2;

        int score = 0;

        gotoligcol(8, 50);
        printf("Score : %d", score);

        gotoligcol(6, 50);
        printf("                                    ");
        gotoligcol(6, 50);
        printf("Turn: %s", firstPlayer);

        gotoligcol(10, 50);
        printf("                                    ");
        gotoligcol(10, 50);
        printf("Walls left: %d", firstPlayerWalls);

        do {
            cleanup();
            gotoligcol(20, strlen(firstPlayer) + 37);
            printf("             ");

            gotoligcol(20, 0);
            printf("It's your turn %s", firstPlayer);
            gotoligcol(20, strlen(firstPlayer) + 14);
            printf(" move = m, place = p : ");
            scanf_s("%c", &buffer, 2);

        } while (buffer != 'm' && buffer != 'p');

        if (buffer == 'm')
        {
            char movement;
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
            } while (legitCheck(posFirstPlayer[0], posFirstPlayer[1], posSecondPlayer[0], posSecondPlayer[1], movement) == 0 || legitCheck(posFirstPlayer[0], posFirstPlayer[1], posSecondPlayer[0], posSecondPlayer[1], movement) == 3);

            switch (legitCheck(posFirstPlayer[0], posFirstPlayer[1], posSecondPlayer[0], posSecondPlayer[1], movement))
            {
            case 1:
                switch (movement)
                {
                case 'r':
                    goRight(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[1] += 4;
                    break;
                case 'l':
                    goLeft(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[1] -= 4;
                    break;
                case 'u':
                    goUp(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[0] -= 2;
                    break;
                case 'd':
                    goDown(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[0] += 2;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                switch (movement)
                {
                case 'r':
                    goRightBoosted(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[1] += 8;
                    break;
                case 'l':
                    goLeftBoosted(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[1] -= 8;
                    break;
                case 'u':
                    goUpBoosted(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[0] -= 4;
                    break;
                case 'd':
                    goDownBoosted(posFirstPlayer[0], posFirstPlayer[1], firstPlayerChar);
                    posFirstPlayer[0] += 4;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        gotoligcol(6, 50);
        printf("                                    ");
        gotoligcol(6, 50);
        printf("Turn: %s", secondPlayer);

        gotoligcol(10, 50);
        printf("                                    ");
        gotoligcol(10, 50);
        printf("Walls left: %d", secondPlayerWalls);

        do {
            cleanup();
            gotoligcol(20, strlen(secondPlayer) + 37);
            printf("             ");

            gotoligcol(20, 0);
            printf("It's your turn %s", secondPlayer);
            gotoligcol(20, strlen(secondPlayer) + 14);
            printf(" move = m, place = p : ");
            scanf_s("%c", &buffer, 2);

        } while (buffer != 'm' && buffer != 'p');

        if (buffer == 'm')
        {
            char movement;
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
            } while (legitCheck(posSecondPlayer[0], posSecondPlayer[1], posFirstPlayer[0], posFirstPlayer[1], movement) == 0 || legitCheck(posSecondPlayer[0], posSecondPlayer[1], posFirstPlayer[0], posFirstPlayer[1], movement) == 3);

            switch (legitCheck(posSecondPlayer[0], posSecondPlayer[1], posFirstPlayer[0], posFirstPlayer[1], movement))
            {
            case 1:
                switch (movement)
                {
                case 'r':
                    goRight(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[1] += 4;
                    break;
                case 'l':
                    goLeft(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[1] -= 4;
                    break;
                case 'u':
                    goUp(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[0] -= 2;
                    break;
                case 'd':
                    goDown(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[0] += 2;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                switch (movement)
                {
                case 'r':
                    goRightBoosted(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[1] += 8;
                    break;
                case 'l':
                    goLeftBoosted(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[1] -= 8;
                    break;
                case 'u':
                    goUpBoosted(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[0] -= 4;
                    break;
                case 'd':
                    goDownBoosted(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                    posSecondPlayer[0] += 4;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
    
}