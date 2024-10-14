#pragma once

int getNumberOfPlayer();
void newGame();
void printSupport();

void startGameOf2();
void startGameOf4();

struct Player {
	char name[25];
	char character;
	char color[10];
};