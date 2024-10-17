#include "run.h"
#include "../../src/utils/coords.h"
#include "../../src/utils/timer.h"
#include "playerQol.h"

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

bool legitCheckBorder(int x, int y, char movement)
{
    cleanup();
    gotoligcol(20, 0);
    printf("Checking your move...\n");

    switch (movement)
    {
    case 'r':
        if (y + 4 <= 36)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Invalid move");
            return false;
        }
    case 'l':
        if (y - 4 >= 4)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Invalid move");
            return false;
        }
    case 'u':
        if (x - 2 >= 2)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Invalid move");
            return false;
        }
    case 'd':
        if (x + 2 <= 18)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Invalid move");
            return false;
        }
    default:
        return false;
    }
}

bool legitCheckPlayer(int x1, int y1, int x2, int y2, char movement)
{
    cleanup();
    gotoligcol(20, 0);

    switch (movement)
    {
    case 'r':
        if (y1 + 4 != y2)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Need more checks");
            return false;
        }
    case 'l':
        if (y1 - 4 != y2)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Need more checks");
            return false;
        }
    case 'u':
        if (x1 - 2 != x2)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Need more checks");
            return false;
        }
    case 'd':
        if (x1 + 2 != x2)
        {
            printf("Valid move");
            return true;
        }
        else
        {
            printf("Need more checks");
            return false;
        }
    default:
        return false;
    }
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
    }

    gotoligcol(4, 50);
    printf("%s", player1);

    gotoligcol(4, 50 + strlen(player1));
    printf("(%c) VS (%c)", character1, character2);

    gotoligcol(4, 50 + strlen(player1) + 11);
    printf("%s", player2);

    gotoligcol(6, 50);
    printf("Turn: %s", firstPlayer);

    int score = 0;

    gotoligcol(8, 50);
    printf("Score : %d", score);

    char buffer, buffer2;

    while (true)
    {
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
                getchar();
                scanf_s("%c", &movement, 2);
            } while (!legitCheckBorder(posFirstPlayer[0], posFirstPlayer[1], movement) );

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
        }

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
                getchar();
                scanf_s("%c", &movement, 2);
            } while (!legitCheckBorder(posSecondPlayer[0], posSecondPlayer[1], movement));

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
                posFirstPlayer[0] -= 2;
                break;
            case 'd':
                goDown(posSecondPlayer[0], posSecondPlayer[1], secondPlayerChar);
                posSecondPlayer[0] += 2;
                break;
            default:
                break;
            }
        }
    }
}