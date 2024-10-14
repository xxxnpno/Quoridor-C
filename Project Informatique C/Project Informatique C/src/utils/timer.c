#include "timer.h"
#include "coords.h"

#include <stdio.h>
#include <stdbool.h>

unsigned short calculeSeconde(unsigned short s)
{
	return s == 0 ? 60 : s - 1;
}

unsigned short calculeMinute(unsigned short m, unsigned short s)
{
	if (s == 0) return m == 0 ? 0 : m - 1;
	return m;
}

void timer(unsigned short minutes, unsigned short secondes)
{
	gotoligcol(12, 50);
	printf("Time left: %02hu : %02hu", calculeMinute(minutes, secondes), calculeSeconde(secondes));
	minutes = calculeMinute(minutes, secondes);
	secondes = calculeSeconde(secondes);
	Sleep(1000);
}