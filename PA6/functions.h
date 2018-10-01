/*
* PA6: Battleship
* Programmed by: Nik Walton
* Created: 3.19.2018
* Last Modified: 3.26.2019
* Desc:A game of battleship.
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef enum direction
{
	HORIZONTAL = 0, VERTICAL = 1
} Direction; 
typedef enum player
{
	PLAYER1 = 0, PLAYER2 = 1
} Plyr;
typedef enum ship
{
	BATTLESHIP = 4, CARRIER = 5, CRUISERSUB = 3, DESTROYER = 2
} Ship;
typedef enum shipFlag
{
	BATTLESHIPF = 'b', CARRIERF = 'c', CRUISERF = 'r', DESTROYERF = 'd', SUBF = 's'
}ShipFlag;

typedef struct stat
{
	int shotsTaken, totalMiss, totalHit;
	double hitMissRatio;
} Stat;

#define ROW 10
#define COL 10

int selectWhoStartsFirst();
int checkShot(char gameboard[][COL], int xCord, int yCord, Stat *playerstat);
int isWinner(char gameboard[][COL]);
int getSelection();

void outputStats(FILE *infile, Plyr player, Stat stats);
void outputCurrentMove(FILE *infile, Plyr player, int xCord, int yCord, int numMoves);
void updateBoard(char gameboard[][COL], int hitOrMiss, int xCord, int yCord);
void displayBoard(Plyr,char gameboard[][COL], int, int);
void manuallyPlaceShipsOnBoard(char gameboard[][COL]);
void randomlyPlaceShipsOnBoard(char arr[][COL], ShipFlag flag);
void welcomeScreen();
void initializeGameBoard(char gameboard[][COL], int ,int);
void printRules();
void placeShip(char arr[][COL], int xCord, int yCord, ShipFlag val, Direction direct);
void randOrMan();
void placeShipsRandomly(char gameboard[][COL]);
void getCoordinate(ShipFlag ship, int *pXCord, int *pYCord);



#endif // !FUNCTIONS_H

