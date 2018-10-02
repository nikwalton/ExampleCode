/*
* PA6: Battleship
* Programmed by: Nik Walton
* Created: 3.19.2018
* Last Modified: 3.26.2018
* Desc:A game of battleship.
*/
#include "functions.h"

double main(void)
{
	int game = 1, selection = 0, check = 0;
	int xCord = 0, yCord = 0;
	char p1GameBoard[ROW][COL] = { '\0' };
	char p2GameBoard[ROW][COL] = { '\0' };

	Direction direct = HORIZONTAL;
	Plyr player = PLAYER1;
	Stat player1Stats = { 0, 0, 0, 0.0 };
	Stat player2Stats = { 0, 0, 0, 0.0 };

	FILE *infile = fopen("battleship.log", "w");
	srand((unsigned int)time(NULL));


	while (game == 1)
	{
		system("cls");
		welcomeScreen();
		selection = getSelection();
		switch (selection)
		{
		case 1:
			system("cls");
			initializeGameBoard(p1GameBoard, ROW, COL);
			initializeGameBoard(p2GameBoard, ROW, COL);
			placeShipsRandomly(p2GameBoard, ROW, COL);
			randOrMan();
			selection = getSelection();
			if (selection == 1)
			{
				manuallyPlaceShipsOnBoard(p1GameBoard);

			}
			else if (selection == 2)
			{
				placeShipsRandomly(p1GameBoard);
				printf("Player 1's gameboard has been generated randomly\n");
			}
			printf("Player 2's (COM) gameboard has been genearted randomly.\n");
			printf("A random player will be selected to start first.\n");
			system("pause");
			player = selectWhoStartsFirst();
			system("cls");
			switch (player)
			{
			O:case PLAYER1:
				printf("Player 1\n");
				displayBoard(PLAYER2, p2GameBoard, ROW, COL);
				takeShot(&xCord, &yCord);
				player1Stats.shotsTaken += 1;
				outputCurrentMove(infile, PLAYER1, xCord, yCord, player1Stats.shotsTaken);
				check = checkShot(p2GameBoard, xCord, yCord, &player1Stats);
				updateBoard(p2GameBoard, check, xCord, yCord);
				system("cls");
				if (check == 1)
				{
					printf("%d, %d is a hit!\n", xCord, yCord);
				}
				else
				{
					printf("%d, %d is a miss!\n", xCord, yCord);
				}
				displayBoard(PLAYER2, p2GameBoard, ROW, COL);
				system("pause");
				check = isWinner(p2GameBoard);
				if (check == 1)
				{
					system("cls");
					printf("PLAYER 1 WINS\n");
					player1Stats.hitMissRatio = ((double)player1Stats.totalHit / player1Stats.totalMiss) * 100;
					player2Stats.hitMissRatio = ((double)player2Stats.totalHit / player2Stats.totalMiss) * 100;
					outputStats(infile, PLAYER1, player1Stats);
					outputStats(infile, PLAYER2, player2Stats);
					exit(1);
				}
				else
				{
					system("cls");
					goto T;
				}
				break;
			T:case PLAYER2:
				printf("player 2\n");
				xCord = rand() % 10;
				yCord = rand() % 10;
				player2Stats.shotsTaken += 1;
				outputCurrentMove(infile, PLAYER2, xCord, yCord, player2Stats.shotsTaken);
				check = checkShot(p1GameBoard, xCord, yCord, &player2Stats);
				updateBoard(p1GameBoard, check, xCord, yCord);
				system("cls");
				if (check == 1)
				{
					printf("%d, %d is a hit!\n", xCord, yCord);
				}
				else
				{
					printf("%d, %d is a miss!\n", xCord, yCord);
				}
				displayBoard(PLAYER1, p1GameBoard, ROW, COL);
				system("pause");
				check = isWinner(p1GameBoard);
				if (check == 1)
				{
					system("cls");
					printf("PLAYER 2 WINS");
					player1Stats.hitMissRatio = ((double)player1Stats.totalMiss / player1Stats.totalHit) * 100;
					player2Stats.hitMissRatio = ((double)player2Stats.totalMiss / player2Stats.totalHit) * 100;
					outputStats(infile, PLAYER1, player1Stats);
					outputStats(infile, PLAYER2, player2Stats);
					exit(1);
				}
				else
				{
					system("cls");
					goto O;
				}
				break;
			}
			break;
		case 2:
			system("cls");
			printRules();
			system("pause");
			break;
		case 3:
			exit(1);

		}

		fclose(infile);
		return 0;
	}
}
