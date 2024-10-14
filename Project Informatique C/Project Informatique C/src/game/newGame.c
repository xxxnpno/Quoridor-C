#include "newGame.h"

#include <stdio.h>
#include <windows.h>

void gotoligcol(int lig, int col)
{
	COORD mycoord;
	mycoord.X = col;
	mycoord.Y = lig;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}
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

void printSupport()
{
	char setupX[] = "ABCDEFGHI";
	char setupY[] = "123456789";

	int k = 0;
	for (int i = 4; i < 9 * 4 + 4; i += 4)
	{
		gotoligcol(0, i);
		printf("%c", setupX[k]);
		k++;
	}
	int j = 0;
	for (int i = 2; i < 9 * 2 + 2; i += 2)
	{
		gotoligcol(i, 0);
		printf("%c", setupY[j]);
		j++;
	}

	for (int h = 2; h < 9 * 2 + 2; h += 2)
	{
		for (int i = 4; i < 9 * 4 + 4; i += 4)
		{
			gotoligcol(h, i);
			printf("+");
		}
	}

	for (int h = 3; h < 8 * 2 + 3; h += 2)
	{
		for (int i = 4; i < 9 * 4 + 4; i += 4)
		{
			gotoligcol(h, i);
			printf("."); //printf("%c", 0xB7);
		}
	}
	for (int h = 2; h < 9 * 2 + 1; h++)
	{
		for (int i = 6; i < 8 * 4 + 6; i += 4)
		{
			gotoligcol(h, i);
			printf("."); //printf("%c", 0xB7);
		}
	}
}

void startGameOf2()
{
	system("cls");

	printSupport();

	struct Player player1;

	printf("\n\nEnter player 1 name: ");
	fgets(player1.name, 25, stdin);

	printf("\nEnter player 1 character: ");
	player1.character = getchar();
	while (getchar() != '\n');

	printf("\nEnter player 1 color: ");
	fgets(player1.color, 10, stdin);

	gotoligcol(20, 2);
	printf("%c", player1.character);

	for (int i = 20; i < 40; i++)
	{
		gotoligcol(i, 0);
		printf("                                                             ");
	}

	struct Player player2;

	gotoligcol(13, 0);

	printf("\n\nEnter player 2 name: ");
	fgets(player2.name, 25, stdin);

	printf("\nEnter player 2 character: ");
	player2.character = getchar();
	while (getchar() != '\n');

	printf("\nEnter player 2 color: ");
	fgets(player2.color, 10, stdin);

	gotoligcol(20, 2);
	printf("%c", player2.character);
}

/*struct Player player2;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter player 2 name: ");
	fgets(player2.name, 25, stdin);

	printf("\nEnter player 2 character: ");
	player2.character = getchar();
	while (getchar() != '\n');

	printf("\nEnter player 2 color: ");
	fgets(player2.color, 10, stdin);

	gotoligcol(40, 20);
	printf("%c", player2.character);*/

void startGameOf4()
{

}

void newGame()
{
	switch (getNumberOfPlayer())
	{
	case '2':
		startGameOf2();
		break;
	case '4':
		startGameOf4();
		break;
	default:
		break;
	}
}