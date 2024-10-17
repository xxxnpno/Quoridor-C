#include "newGame.h"
#include "../../src/game/player/playerQol.h"
#include "../../src/utils/coordinates/support.h"

void startGameOf2()
{
	system("cls");

	printSupport();
	get2Players();
}
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