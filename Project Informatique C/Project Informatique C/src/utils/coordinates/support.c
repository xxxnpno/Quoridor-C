#include "support.h"
#include "coords.h"

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