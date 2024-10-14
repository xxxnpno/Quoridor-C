#include "run.h"
#include "../../src/utils/coords.h"
#include "../../src/utils/timer.h"
#include "playerQol.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool doesMoveExist(const char* move) {
    if (strlen(move) != 2) {
        return false;
    }

    if (move[0] < 'A' || move[0] > 'I') {
        return false;
    }

    if (move[1] < '1' || move[1] > '9') {
        return false;
    }

    return true;
}

void run2players(const short choice, const char* player1, const char* player2, const char character1, const char character2)
{
    char firstPlayer[25];
    char secondPlayer[25];

    choice == 0 ? strcpy_s(firstPlayer, sizeof(firstPlayer), player1) : strcpy_s(firstPlayer, sizeof(firstPlayer), player2);
    firstPlayer == player1 ? strcpy_s(secondPlayer, sizeof(secondPlayer), player2) : strcpy_s(secondPlayer, sizeof(secondPlayer), player1);

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

    int walls1 = 20;
    int walls2 = 20;

    gotoligcol(10, 50);
    printf("Walls left: %d", walls1);

    //timer(1, 0); <- while(true) == pause

    char move[] = "move";
    char place[] = "place";
    char buffer[5];

    int posFirstPlayer[2] = { 2, 20 };
    int posSecondPlayer[2] = { 18, 20 };

    do {
        gotoligcol(20, 0);
        printf("It's your turn %s", firstPlayer);
        gotoligcol(20, strlen(firstPlayer) + 14);
        printf(": (move/place) ");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = 0;
    } while (strcmp(buffer, "move") != 0 && strcmp(buffer, "place") != 0); // ?

    if (buffer == "move")
    {
        char tempMove[3];

        cleanup();

        do {
            printf("Where do you want to move? ");
            fgets(tempMove, sizeof(tempMove), stdin);

            tempMove[strcspn(tempMove, "\n")] = 0;

        } while (!doesMoveExist(tempMove));
    }
}
void run4players(const short choice)
{

}