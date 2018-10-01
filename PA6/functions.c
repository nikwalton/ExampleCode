/*
* PA6: Battleship
* Programmed by: Nik Walton
* Created: 3.19.2018
* Last Modified: 3.26.2019
* Desc:A game of battleship.
*/
#include "functions.h"
/*
* welcomeScreen()
* created 3.19.2018
* modified 3.21.2018
* preconditions: none
* postconditions: displays a welcome screen for battlehsip
*/
void welcomeScreen()
{
	printf(" _           _   _   _           _     _       \n");
	printf("| |         | | | | | |         | |   (_)      \n");
	printf("| |__   __ _| |_| |_| | ___  ___| |__  _ _ __  \n");
	printf("| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ \n");
	printf("| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n");
	printf("|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ \n");
	printf("                                        | |    \n");
	printf("                                        |_|    \n");
	printf("\n");
	printf("+-------------------------------------------------+\n");
	printf("|           1)      Start Game                    |\n");
	printf("|           2)      Rules                         |\n");
	printf("|           3)      Exit                          |\n");
	printf("+-------------------------------------------------+\n");

}
/*
* initializeGameBoard()
* created 3.19.2018
* modified 3.23.2018
* preconditions: none
* postconditions: initializes the game board
*/
void initializeGameBoard(char gameboard[][COL], int rows, int cols) // return type is a placeholder
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++) 
		{
			gameboard[i][j] = '~';
		}
	}
}
/*
* selectWhoStartsFirst()
* created 3.19.2018
* modified 3.26.2018
* preconditions: none
* postconditions: selects which player will start first
*/
Plyr selectWhoStartsFirst()
{
	Plyr player = PLAYER1;
	player = rand() % 2;
	return player;
}
/*
* manuallyPLaceShipsOnBoard()
* created 3.19.2018
* modified 3.28.2018
* preconditions: game needs to be running
* postconditions: allows user to place each of the 5 ships on their board
*/
void manuallyPlaceShipsOnBoard(char gameboard[][COL]) //return type is a placeholder
{
	int xCord = 0, ycord = 0;
	Direction direct = HORIZONTAL;
}
/*
* randomlyPlaceShipsOnBoard()
* created 3.18.2018
* modified 3.28.2018
* preconditions: game needs to be running
* postconditions: randomly places the 5 ships on a board
*/
void randomlyPlaceShipsOnBoard(char arr[][COL], ShipFlag val) //return type is a placeholder for now
{
	//randomly place the 5 ships on the given board
	//return modified board
	int xCord = 0;
	int yCord = 0;
	int check = 0;
	Direction direct = HORIZONTAL;
	switch (val)
	{
	B:case BATTLESHIPF:
		direct = generateDirection(); // Start of rand num gen
		xCord = rand() % 10;
		yCord = rand() % 10; // end random num gen
		check = checkBoard(arr, BATTLESHIP, xCord, yCord, direct); //check if no other ships in area
		if (check == 1)
		{
			if (direct == HORIZONTAL && xCord <= 4 && yCord < 9) //check if the cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else if (direct == VERTICAL && xCord < 9 && yCord <= 4) // check if the cords are usable/ no other ships in area
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else
			{
				goto B; //start of case
			}
		}
		else
		{
			goto B; //start of case
		}
		break;
	R:case CRUISERF:
		direct = generateDirection(); // start rand num gen
		xCord = rand() % 10;
		yCord = rand() % 10; //end rand num gen
		check = checkBoard(arr, CRUISERSUB, xCord, yCord, direct); //check if no other ships in area
		if (check == 1)
		{
			if (direct == HORIZONTAL && xCord <= 6 && yCord < 9) //check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else if (direct == VERTICAL && xCord < 9 && yCord <= 6)//check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else
			{
				goto R; //start of case
			}
		}
		else
		{
			goto R; // start of case
		}
		break;
	C:case CARRIERF:
		direct = generateDirection(); //start of rand num gen
		xCord = rand() % 10;
		yCord = rand() % 10; // end of rand num gen
		check = checkBoard(arr, CARRIER, xCord, yCord, direct); //check if no other ships in area
		if (check == 1)
		{
			if (direct == HORIZONTAL && xCord <= 4 && yCord < 9) //check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else if (direct == VERTICAL && xCord < 9 && yCord <= 4)//check if the cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else
			{
				goto C; //start of case
			}
		}
		else
		{
			goto C; //start of case
		}
		break;
	D:case DESTROYERF:
		direct = generateDirection(); //start of rand num generation
		xCord = rand() % 10;
		yCord = rand() % 10; //end of rand num gen
		check = checkBoard(arr, DESTROYER, xCord, yCord, direct); //check if no other ships in area
		if (check == 1)
		{
			if (direct == HORIZONTAL && xCord <= 8 && yCord <= 9) //check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else if (direct == VERTICAL && xCord < 9 && yCord <= 8) //check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else
			{
				goto D; //start of case
			}
		}
		else
		{
			goto D; //start of case
		}
		break;
	S:case SUBF:
		direct = generateDirection(); //start of rand num gen
		xCord = rand() % 10;
		yCord = rand() % 10; //end of rand num gen
		check = checkBoard(arr, CRUISERSUB, xCord, yCord, direct); //check if other ships are in area
		if (check == 1)
		{
			if (direct == HORIZONTAL && xCord <= 6 && yCord < 9) //check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else if (direct == VERTICAL & xCord < 9 && yCord <= 6)//check if cords are usable
			{
				placeShip(arr, xCord, yCord, val, direct);
			}
			else
			{
				goto S; //start of case
			}

		}
		else
		{
			goto S; //start of case
		}	
		break;
	}
}
/*
* checkShot()
* created 3.18.2018
* modified 3.18.2018
* preconditions: a shot had happened
* postconditions: checks if the shot is a hit or miss and valid
*/
int checkShot(/*opponentGameBoard?*/)
{
	//if shot is valid
	//if shot is hit return 1
	//else if shot is miss return 0
	//if shot is not valid
	//ask for new shot

}
/*
* isWinner()
* created 3.18.2018
* modified 3.18.2018
* preconditions: a game is to be running
* postconditions: returns if a winner is found
*/
int isWinner(/*player1GameBoard*//*player2GameBoard*/)
{
	//if player 1's gameboard has all 5 ships destroyed
	//return 0 for player 2 has won
	//else if players 2 gameboard has all 5 ships destroyed
	//return 1 for player 1 has won
}
/*
* updateBoard()
* created 3.18.2018
* modified 3.18.2018
* preconditions: a game has to be running
* postconditions: updates the gameboard
*/
void updateBoard(/*gameboard*//*hitOrMiss*//*shot*/) //return type is a placeholder
{
	//if hitOrMiss = 1
	//return updated gameboard with '*' at location of the shot
	//else if hitOrMiss = 0
	//return updated gameboard with 'm' at location of the shot
}
/*
* displayBoard()
* created 3.18.2018
* modified 3.26.2018
* preconditions: a game has to be running
* postconditions: displays the gameboard given the flag
*/
void displayBoard(Plyr player, char gameboard[][COL], int rows, int cols)
{ 
	if(player == PLAYER1) // player 1
	{ 
		printf("  0 1 2 3 4 5 6 7 8 9\n"); // top header
		for(int i = 0; i < rows; i++) 
		{
			printf("%d ", i); //row header
			for(int j = 0; j < cols; j++)
			{
				printf("%c ", gameboard[i][j]);
			}
			printf("\n");
		}
	}
	else if(player == PLAYER2) //player 2
	{ 
		printf("  0 1 2 3 4 5 6 7 8 9\n"); //top header
		for(int i = 0; i < rows; i++)
		{
			printf("%d ", i); //row header
			for (int j = 0; j < cols; j++) 
			{
				printf("%c ",gameboard[i][j]);
			}
			putchar('\n');
		}
	}
	else //invalid flag
	{
		printf("Invalid Flag");
	}
}
/*
* outputCurrentMove
* created 3.18.2018
* modified 3.26.2018
* preconditions: none probably
* postconditions: outputs the current move made by the
*                 current player to the .log file
*/
void outputCurrentMove(FILE *infile, Plyr player, int move[], int numMoves)
{
	if (player == PLAYER1)
	{
		fprintf("Player 1 Move %d: (%d,%d)", numMoves, move[0], move[1]);
	}
	else if (player == PLAYER2)
	{
		fprintf("Player 2 Move %d: (%d,%d)", numMoves, move[0], move[1]);
	}
}
/*
* checkIfSunkShip()
* created 3.18.2018
* modified 3.18.2018
* preconditions: game has to be running
* postconditions: checks to see if selected ship is sunk
*/
int checkIfSunkShip(/*players ship*/)
{
	// if player ship is sunk
	// return 1
	// if player ship is not sunk
	// return 0
}
/*
* outputStats()
* created 3.18.2018
* modified 3.27.2018
* preconditions: none probably
* postconditions: writes stats collected on each player
*                 to the .log file
*/
void outputStats(FILE *infile, Plyr player, Stat stats)
{
	
	if (player == PLAYER1)
	{
		fprintf(infile,"-----Player 1 Statistics-----\n");
		fprintf(infile,"# Shots Taken:    %d\n", stats.shotsTaken);
		fprintf(infile,"# Total Misses:   %d\n", stats.totalMiss);
		fprintf(infile,"# Total Hits:     %d\n", stats.totalHit);
		fprintf(infile,"Hit / Miss Ratio: %lf\n", stats.hitMissRatio);
	}
	else if (player == PLAYER2)
	{
		fprintf(infile,"-----Player 2 Statistics-----\n");
		fprintf(infile,"# Shots Taken:    %d\n", stats.shotsTaken);
		fprintf(infile,"# Total Misses:   %d\n", stats.totalMiss);
		fprintf(infile,"# Total Hits:     %d\n", stats.totalHit);
		fprintf(infile,"Hit / Miss Ratio: %lf\n", stats.hitMissRatio);
	}
}
/*
* getSelection()
* created 3.23.2018
* modified 3.23.2018
* preconditions: a single numerical selection needs to be made
* postconditions: returns a single numerical selection
*/
int getSelection()
{
	int selection = 0;
	printf("Enter Selection: ");
	scanf("%d", &selection);
	return selection;
}
/*
* getCoordinate()
* created: 3.28.2018
* modified 3.28.2018
* precondition: a coordinate point needs to be entered by the user
* postcondition: gets a coordinate point from the user.
*/
void getCoordinate(ShipFlag ship, int *xCord, int *yCord)
{
	switch (ship)
	{
	B:case BATTLESHIPF:
		system("cls");
		printf("Enter a starting coordinate point for your Battleship: ");
		scanf("%d%d", xCord, yCord);
		if (*xCord < 9 && *yCord < 9)
		{
			break;
		}
		else
		{
			printf("Coordinate off the gameboard, enter a new coordinate");
			system("pause");
			goto B;
		}
	R:case CRUISERF:
		system("cls");
		printf("Enter a starting coordinate point for your Cruiser: ");
		scanf("%d%d", xCord, yCord);
		if (*xCord < 9 && *yCord < 9)
		{
			break;
		}
		else
		{
			printf("Coordinate off the gameboard, enter a new coordinate");
			system("pause");
			goto R;
		}
	C:case CARRIERF:
		system("cls");
		printf("Enter a starting coordinate point for your Carrier: ");
		scanf("%d%d", xCord, yCord);
		if (*xCord < 9 && *yCord < 9)
		{
			break;
		}
		else
		{
			printf("Coordinate off the gameboard, enter a new coordinate");
			system("pause");
			goto C;
		}
	D:case DESTROYERF:
		system("cls");
		printf("Enter a starting coordinate point for your Destroyer: ");
		scanf("%d%d", xCord, yCord);
		if (*pXCord < 9 && *pYCord < 9)
		{
			break;
		}
		else
		{
			printf("Coordinate off the gameboard, enter a new coordinate");
			system("pause");
			goto D;
		}

	}
}
/*
* playerMove()
* created 3.26.2018
* modified 3.26.2019
* precondition: none
* postcondition: return a tuple probably of the shot taken
*/
int playerMove()
{
	int move[2];
	printf("Enter the coordinates for your shot: ");
	scanf("%d%d", &move[0], &move[1]);
	return move;
}
/*
* printRules()
* created: 3.26.2018
* modified: 3.26.2018
* precondition: none
* postcondition: prints the rules for battleship
*/
void printRules()
{
	printf("+------------------------------------------------------+\n");
	printf("| Battleship is a two player game. Player one is you,  |\n");
	printf("| and player two is the computer. A coin will be tossed|\n");
	printf("| to decide which player will go first. You can decide |\n");
	printf("| to place your ships manually or randomly generate a  |\n");
	printf("| a board for you to play on. once the ships are set,  |\n");
	printf("| each player will take turns taking a shot at the     |\n");
	printf("| players board until all ships are deystroyed on a    |\n");
	printf("| players gameboard.                                   |\n");
	printf("+------------------------------------------------------+\n");
}
/*
* randOrMan()
* created: 3.28.2018
* modified: 3.28.2018
* precondition: none
* postcondition: prints a menu for the user to select from.
*/
void randOrMan()
{
	printf("+----------------------------------+\n");
	printf("| Would you like to:               |\n");
	printf("|       1) Place Ships Manually    |\n");
	printf("|       2) Place Ships Randomly    |\n");
	printf("+----------------------------------+\n");
}
/*
* generateDirection()
* created: 3.23.2018
* modified 3.23.2018
* precondition: none
* postcondition: generates a random direction for use in the random
				 placement of ships.
*/
Direction generateDirection()
{
	Direction direct = HORIZONTAL;
	direct = rand() % 2;
	return direct;
}
/*
* placeShip()
* created: 3.27.2018
* modified: 3.28.2018
* precondition: none
* postcondtion: places ship board
*/
void placeShip(char arr[][COL], int xCord, int yCord, ShipFlag val, Direction direct)
{
	switch (val)
	{
	case BATTLESHIPF:
		if ((xCord <= 4 && yCord < 9) && direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + BATTLESHIP; i++)
			{
				arr[yCord][i] = 'b';
			}
		}
		else if ((xCord < 9 && yCord <= 4) && direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + BATTLESHIP; i++)
			{
				arr[i][xCord] = 'b';
			}
		}
		break;
	case CARRIERF:
		if ((xCord <= 4 && yCord < 9) && direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + CARRIER; i++)
			{
				arr[yCord][i] = 'c';
			}
		}
		else if ((xCord < 9 && yCord <= 5) && direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + CARRIER; i++)
			{
				arr[i][xCord] = 'c';
			}
		}
		break;
	case CRUISERF:
		if ((xCord <= 6 && yCord < 9) && direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + CRUISERSUB; i++)
			{
				arr[yCord][i] = 'r';
			}
		}
		else if ((xCord < 9 && yCord <= 6) && direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + CRUISERSUB; i++)
			{
				arr[i][xCord] = 'r';
			}
		}
		break;
	case DESTROYERF:
		if ((xCord <= 8 && yCord < 9) && direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + DESTROYER; i++)
			{
				arr[yCord][i] = 'd';
			}
		}
		else if ((xCord < 9 && yCord <= 8) && direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + DESTROYER; i++)
			{
				arr[i][xCord] = 'd';
			}
		}
		break;
	case SUBF:
		if ((xCord <= 6 && yCord < 9) && direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + CRUISERSUB; i++)
			{
				arr[yCord][i] = 's';
			}
		}
		else if ((xCord < 9 && yCord <= 6) && direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + CRUISERSUB; i++)
			{
					arr[i][yCord] = 's';
			}
		}
		break;
	}
}
/*
* checkBoard()
* created 3.27.2018
* modified 3.28.2018
* precondtions: a ship needs to be written to the board
* postcondition: makes sure the ship can actually go there
*/
int checkBoard(char gameboard[][COL], Ship val, int xCord, int yCord, Direction direct)
{
	int truthVal = 0;
	switch (val)
	{
	case BATTLESHIP:
		if (direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord +BATTLESHIP; i++)
			{
				if (gameboard[yCord][i] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[yCord][i] != '~')
				{
					return 0;
				}
			}
		}
		else if (direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + BATTLESHIP; i++)
			{
				if (gameboard[xCord][i] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[xCord][i] != '~')
				{
					return 0;
				}
			}
		}
		break;
	case CRUISERSUB:
		if (direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + CRUISERSUB; i++)
			{
				if (gameboard[yCord][i] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[yCord][i] != '~')
				{
					return 0;
				}
			}
		}
		else if (direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + CRUISERSUB; i++)
			{
				if (gameboard[i][xCord] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[i][xCord] != '~')
				{
					return 0;
				}
			}
		}
		break;
	case CARRIER:
		if (direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + CARRIER; i++)
			{
				if (gameboard[yCord][i] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[yCord][i] != '~')
				{
					return 0;
				}
			}
		}
		else if (direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + CARRIER; i++)
			{
				if (gameboard[i][xCord] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[i][xCord] != '~')
				{
					return 0;
				}
			}
		}
		break;
	case DESTROYER:
		if (direct == HORIZONTAL)
		{
			for (int i = xCord; i < xCord + DESTROYER; i++)
			{
				if (gameboard[yCord][i] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[yCord][i] != '~')
				{
					return 0;
				}
			}
		}
		else if (direct == VERTICAL)
		{
			for (int i = yCord; i < yCord + DESTROYER; i++)
			{
				if (gameboard[i][xCord] == '~')
				{
					truthVal = 1;
				}
				else if (gameboard[i][xCord] != '~')
				{
					return 0;
				}
			}
		}
		break;
	}
	switch (truthVal)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	
	}
}
/*
* placeShipsRandomly()
* created 3.28.2018
* modified 3.28.2018
* preconditions: user has selected to place ships randomly
* postcondition: places ships randomly
*/
void placeShipsRandomly(char gameboard[][COL])
{
	randomlyPlaceShipsOnBoard(gameboard, BATTLESHIPF);
	randomlyPlaceShipsOnBoard(gameboard, CRUISERF);
	randomlyPlaceShipsOnBoard(gameboard, CARRIERF);
	randomlyPlaceShipsOnBoard(gameboard, DESTROYERF);
	randomlyPlaceShipsOnBoard(gameboard, SUBF);

}