#include "playerQol.h"
#include "run.h"

#include <stdio.h>
#include <Windows.h>
#include <time.h>

int getNumberOfPlayer()
{
	char player;

	do
	{
		system("cls");
		printf("How many player are playing ? (2 or 4): ");

		player = _getch();

	} while (player != '2' && player != '4');

	printf("\nStarting a game with %c players !\n", player);

	return player;
}

short random()
{
	srand(time(NULL));

	return rand() % 2;
}

void cleanup()
{
	for (int i = 20; i < 25; i++)
	{
		gotoligcol(i, 0);
		printf("                                                             ");
	}
}

void get2Players()
{
	struct Player player1;

	printf("\n\nEnter player 1 name: ");
	fgets(player1.name, 25, stdin);

	printf("\nEnter player 1 character: ");
	player1.character = getchar();
	while (getchar() != '\n');

	gotoligcol(2, 20);
	printf("%c", player1.character);

	gotoligcol(23, 0);
	printf("\nEnter player 1 color: ");
	fgets(player1.color, 10, stdin);

	cleanup();

	struct Player player2;

	gotoligcol(18, 0);
	printf("\n\nEnter player 2 name: ");
	fgets(player2.name, 25, stdin);

	printf("\nEnter player 2 character: ");
	player2.character = getchar();
	while (getchar() != '\n');

	gotoligcol(18, 20);
	printf("%c", player2.character);

	gotoligcol(23, 0);
	printf("\nEnter player 2 color: ");
	fgets(player2.color, 10, stdin);

	cleanup();

	run2players(random(), player1.name, player2.name, player1.character, player2.character);
}