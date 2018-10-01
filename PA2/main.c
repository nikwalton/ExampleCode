/*
* PA 2
* Programmed by: Nikolaus Walton
* Date Created: 9/11/2018
* Date Modified: 9/13/2018
* Description: Takes information from a file about songs, stores them in a doubly
*			   linked list and allows the user to perform different operations
*			   on the list of songs provided.
*/
#include "header.h"

int main(void) {
	FILE *infile = fopen("musicPlayList.csv", "r");
	FILE *outfile = fopen("musicPlayListOut.csv", "w");
	Node *pPlaylist = NULL;
	Record newRecord = { NULL };
	
	int selection = 0;
	int i = 0;
	int success = 0;
	int buf = 100;
	int displaySelection = 0;

	char prevLine[100] = { "\0" };
	char firstName[20];
	char lastName[20];
	char songTitle[100];
	char artistName[100];

	if (infile == NULL) {
		printf("Error: Playlist file could not be opened or has no data");
		exit(1);
	}

	while (1) {
		printf("  /////,^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("o^ &xxxx333333oo33oo3o33333333333oo  /\n");
		printf("u  M             iPod      |||||  M  /\n");
		printf("u  M                              N  ,\n");
		printf("u  M  Load                   > 1  H  ,\n");
		printf("u^ M  Store                  > 2  H  ,\n");
		printf("u^ M  Display                > 3  H  ,\n");
		printf("u^ M  Insert                 > 4  H  ,\n");
		printf("u^ M  Delete                 > 5  H  ,\n");
		printf("u^^M  Edit                   > 6  H  ,\n");
		printf("u^^M  Sort                   > 7  H  ^\n");
		printf("u^^M  Rate                   > 8  H  ^\n");
		printf("u^^M  Play                   > 9  H  ^\n");
		printf("u^^M  Shuffle                > 10 H  ^\n");
		printf("u^^M  Exit                   > 11 H  ^\n");
		printf("X^^Nyyyyyyyyyyyyyyyy88888888888888M  ^\n");
		printf("X,,,^^^^^^^^^                        ^\n");
		printf("X,,,,,^^^^^^^^                       ^\n");
		printf("X,,,,,^^^^^^^^   ^^^^                ^\n");
		printf("X,,,,,,^^^^^^,///,//////,            ^\n");
		printf("X,,,,,,,^^,///(<<<<<<<<</(/^         ^\n");
		printf("X,,,,,,,,/<<(<<<<<<<<<<<<(<</        ^\n");
		printf("X,/,,,,,(&<<<<<&&////<&&<<<&&/       ^\n");
		printf("X///,,,/&&&&%%&/       /&&<<&&&^     ^\n");
		printf("X//////<(//&&&&        <&&&&////     ^\n");
		printf("X//////<&ooooo3^       &ooooo&/      ,\n");
		printf("X///////o3333333<,^^^/o333oo33,      ,\n");
		printf("8///////<33333333333333333333/^^     ,\n");
		printf("8/////////&333xxxxxxxxxx333%/^^^^^   ,\n");
		printf("8/<<(///////&3xxx&&o&xx3o&/,^^^^^^^  ,\n");
		printf("y(<<<</////////(<&&&<<//,,,^^^^^^^^^ /\n");
		printf("y<<<<<<//////////////,,,,,,,,^^^^^^^^/\n");
		printf("8(<<<<<(//////////////,,,,,,,,^^^^^^^<\n");
		printf("uu3o&&&&<<<<<<(/////////////////// <^ \n");
		printf("^,,////////////////////////////,,^^   \n\n");

		printf("Selection: ");
		scanf("%d", &selection);
		switch (selection){
		case 1: //load
			while (!feof(infile)) {
				char *line = (char*)malloc(sizeof(char) * 256);
				char *token;
				char temp[1];
				char durationTemp[10];
				fgets(line, 100, infile);
					if (line[0] == '\"') {
						token = strtok(line, "\"\"");
						newRecord.artist = token;
					}
					else {
						token = strtok(line, ",");
						newRecord.artist = token;
					}
					token = strtok(NULL, ",");
					newRecord.albumTitle = token;

					token = strtok(NULL, ",");
					newRecord.songTitle = token;

					token = strtok(NULL, ",");
					newRecord.genre = token;

					token = strtok(NULL, ",");
					strcpy(durationTemp, token);

					token = strtok(NULL, ",");
					newRecord.timesPlayed = atoi(token);

					token = strtok(NULL, ",");
					newRecord.rating = atoi(token);

					token = strtok(durationTemp, ":");
					newRecord.duration.minutes = atoi(token);
					token = strtok(NULL, "\0");
					newRecord.duration.seconds = atoi(token);

					insertAtFront(&pPlaylist, newRecord);
					i++;
				}
			printf("Files loaded!\n");
			system("pause");
			system("cls");
			break;
		case 2: //store
			storeList(outfile, pPlaylist);
			printf("Playlist stored to file!");
			system("pause");
			system("cls");
			break;
		case 3: //display
			printf("Would you like to: 1) Display All Records or 2) Display Records Based by Artist: ");
			scanf("%d", &displaySelection);
			switch (displaySelection) {
			case 1:
				system("cls");
				printList(pPlaylist);
				putchar('\n');
				system("pause");
				system("cls");
				break;
			case 2:
				printf("Enter a artists name. (Lastname, Firstname when applicable): ");
				scanf(" %[^\n]s", &artistName);
				displaySearch(artistName, pPlaylist);
				system("pause");
				system("cls");
				break;
			}
			break;
		case 4: //insert
			insertNewRecord(&pPlaylist);
			system("cls");
			//PA3
			break;
		case 5: //delete
			printf("Enter a song title to delete: ");
			scanf(" %[^\n]s", &songTitle);
			deleteNode(&pPlaylist, songTitle);
			//PA3
			break;
		case 6: //edit			
			printf("Enter a artists name. (Lastname, Firstname when applicable): ");
			scanf(" %[^\n]s", &artistName);
			printf("enter a song title: ");
			scanf(" %[^\n]s", &songTitle);
			success = 0;
			success = editSong(artistName, songTitle, &pPlaylist);
			if (success == 1) {
				printf("Song Edited\n");
				system("pause");
				system("cls");
			}
			else {
				printf("Song Failed to be edited\n");
				system("pause");
				system("cls");
			}
			break;
		case 7: //sort
			//PA3
			break;
		case 8:// rate
			printf("Enter a artists name. (Lastname, Firstname when applicable): ");
			scanf(" %[^\n]s", &artistName);
			printf("enter a song title: ");
			scanf(" %[^\n]s", &songTitle);
			success = rateSong(artistName, songTitle, &pPlaylist);
			if (success == 1) {
				printf("Rating change successful");
				system("pause");
				system("cls");
			}
			else {
				printf("song not found. Try again");
				system("pause");
				system("cls");
			}
			break;
		case 9: //play
			play(pPlaylist);
			system("cls");
			break;
		case 10:
			//PA3
			break;
		case 11:
			storeList(outfile, pPlaylist);
			fclose(infile);
			fclose(outfile);
			exit(0);
			break;
		}
	}
	return 0;
}