#pragma once

int getNumberOfPlayer();
short random();

void cleanup();

struct Player {
	char name[25];
	char character;
	char color[10];
};

void get2Players();
