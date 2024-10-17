#pragma once

int getNumberOfPlayer();
short random();

void cleanup();

struct Player {
	char name[25];
	char character;
};

void get2Players();
