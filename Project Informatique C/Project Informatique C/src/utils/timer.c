#include "timer.h"
#include "coords.h"

#include <stdio.h>
#include <stdbool.h>

short calculeSeconde(short s)
{
	return s == 0 ? 60 : s - 1;
}

short calculeMinute(short m, short s)
{
	if (s == 0) return m == 0 ? 0 : m - 1;
	return m;
}

void timer(short minutes, short secondes)
{
	gotoligcol(12, 50);
	printf("Time left: %02hu : %02hu", calculeMinute(minutes, secondes), calculeSeconde(secondes));
	minutes = calculeMinute(minutes, secondes);
	secondes = calculeSeconde(secondes);
	Sleep(1000);
}