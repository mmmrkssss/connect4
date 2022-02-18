/*
 ============================================================================
 Name        : connect4.c
 Author      : Markus Haller
 Version     : 1.0
 Copyright   : Free for use
 Description : Console connect4 for 2 in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int HEIGHT = 6;
int WIDTH = 7;
int lastColumnPlayed;
char field[7][6];
char activePlayer;

_Bool checkIfUserWon(char activePlayer);
_Bool hasColumnSpace(int column);
void clearScreen();

int main(void) {
	_Bool notExited = true;
	_Bool ongoingLoop;
	int movesMade = 0;
	int scoreX = 0;
	int scoreO = 0;
	char decision;

	while(notExited) {
		resetField();
		clearScreen();
		printField();
		ongoingLoop = true;

		while(ongoingLoop) {
			if(activePlayer == 'X') {
				activePlayer = 'O';
			} else {
				activePlayer = 'X';
			}
			printf("Moves made: %d\n%c starts.\n", movesMade, activePlayer);
			makeNextMove(activePlayer);
			printField();
			movesMade++;
			if(checkIfUserWon(activePlayer)) {
				printf("%c won!\n", activePlayer);
				if(activePlayer == 'X') {
					scoreX++;
					printf("added score");
				} else {
					scoreO++;
				}
				ongoingLoop = false;
			} else if (movesMade >= 42) {
				printf("Draw!\n");
				ongoingLoop = false;		}
		}
		ongoingLoop = true;
		while(ongoingLoop) {
			clearScreen();
			printf("  X  :  O  \n"
				  "  %d  :  %d  \n", scoreX, scoreO);
			printf("Play Again?\n");
			printf("Yes (y) Reset Scores (r) No (n)\n");
			char decision = getchar();
			if(decision == 'y' || decision == 'Y') {
				ongoingLoop = false;
			} else if(decision == 'r' || decision == 'R') {
				scoreX = 0;
				scoreO = 0;
				ongoingLoop = false;
			} else if(decision == 'n' || decision == 'N') {
				notExited = false;
				ongoingLoop = false;
			}
		}
	}
	return EXIT_SUCCESS;
}

void resetField() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			field[j][i] = ' ';
		}
	}

}

void printField() {
	printf("\n");
	for (int i = 0; i < WIDTH; i++) {
		printf(" %d" ,(i + 1));
	}
	printf("\n");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("|%c" ,field[j][i]);
		}
		printf("|\n");
	}

	for (int i = 0; i < WIDTH; i++) {
		printf("¯¯");
	}
	printf("¯\n");

}

_Bool checkIfUserWon(char activPlayer) {
	// verticalCheck
	for (int j = 0; j < HEIGHT - 3; j++) {
		for (int i = 0; i < WIDTH; i++) {
			if (field[i][j] == activePlayer && field[i][j + 1] == activePlayer && field[i][j + 2] == activePlayer && field[i][j + 3] == activePlayer) {
				return true;
			}
		}
	}
	// horizontalCheck
	for (int i = 0; i < WIDTH - 3; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (field[i][j] == activePlayer && field[i + 1][j] == activePlayer && field[i + 2][j] == activePlayer && field[i + 3][j] == activePlayer) {
				return true;
			}
		}
	}
	// ascendingDiagonalCheck
	for (int i = 3; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT - 3; j++) {
			if (field[i][j] == activePlayer && field[i - 1][j + 1] == activePlayer && field[i - 2][j + 2] == activePlayer && field[i - 3][j + 3] == activePlayer) {
				return true;
			}
		}
	}
	// descendingDiagonalCheck
	for (int i = 3; i < WIDTH; i++) {
		for (int j = 3; j < HEIGHT; j++) {
			if (field[i][j] == activePlayer && field[i - 1][j - 1] == activePlayer && field[i - 2][j - 2] == activePlayer && field[i - 3][j - 3] ==  activePlayer) {
				return true;
			}
		}
	}
	return false;
}

void makeNextMove(char activePlayer) {
	char columnPlayed;
	printf("Enter the Number of the column you want to play: ");
	columnPlayed = getchar();
	if(isdigit(columnPlayed)){
		int column = columnPlayed - '0';
		if(column <=7 && column >= 1 && hasColumnSpace(column)){
			placeInColumn(column, activePlayer);
			lastColumnPlayed = column;
		} else {
			clearScreen();
			printf("Last Played %d\n%c is next.", lastColumnPlayed, activePlayer);
			printField();
			printf("That number won't work, please chose another.\n");
		}
	} else {
		clearScreen();
		printf("Last Played %d\n%c is next.", lastColumnPlayed, activePlayer);
		printField();
		makeNextMove(activePlayer);
	}
}

_Bool hasColumnSpace(int column) {
	for (int i = HEIGHT - 1; i >= 0; i--) {
		if (field[column - 1][i] == ' ') {
			return true;
		}
	}
	return false;
}

void placeInColumn(int column, char activePlayer) {
	bool played = false;
	for (int i = HEIGHT - 1; i >= 0 && !played; i--) {
		if (field[column - 1][i] == ' ') {
			field[column - 1][i] = activePlayer;
			played = true;
		}
	}
}

void clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
}

