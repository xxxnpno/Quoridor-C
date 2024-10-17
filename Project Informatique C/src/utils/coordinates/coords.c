#include "coords.h"

#include <windows.h>

void gotoligcol(int lig, int col)
{
	COORD mycoord;
	mycoord.X = col;
	mycoord.Y = lig;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

char getCharAtPos(int lig, int col)
{
    char c = ' ';
    COORD mycoord;
    DWORD num_read;

    mycoord.X = col;
    mycoord.Y = lig;

    ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &c, 1, mycoord, &num_read);
    return c;
}