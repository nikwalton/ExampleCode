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

/*
* makeNode()
* created: 9/13/2018
* modified: 9/13/2018
* description: Creates a new node so it can be inserted into the list.
*/
Node * makeNode(Record newRecord) {
	Node * pMem = NULL;
	pMem = (Node *)malloc(sizeof(Node));
	
	pMem->data.artist = newRecord.artist;
	pMem->data.albumTitle = newRecord.albumTitle;
	pMem->data.duration = newRecord.duration;
	pMem->data.genre = newRecord.genre;
	pMem->data.rating = newRecord.rating;
	pMem->data.songTitle = newRecord.songTitle;
	pMem->data.timesPlayed = newRecord.timesPlayed;

	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

/*
* insertAtFront()
* created: 9/13/2018
* modified: 9/13/2018
* description: takes data in from the Record struct, makes it into a node,
*			   and then inserts it into the front of the list.
*/
int insertAtFront(Node **pPlaylist, Record newRecord) {
	int success = 0;
	Node *pMem = NULL;
	pMem = makeNode(newRecord);
	if (pMem != NULL) {
		success = 1;
		pMem->pNext = (*pPlaylist);
		pMem->pPrev = NULL;
		if ((*pPlaylist) != NULL) {
			(*pPlaylist)->pPrev = pMem;
		}
		(*pPlaylist) = pMem;
	}
	return success;
}

/*
* printList()
* created 9/13/2018
* modified 9/13/2018
* description: takes a pointer to a playlist and prints all data within that 
*			   playlist.
*/
void printList(Node *pPlaylist) {
	printf("-> ");
	while (pPlaylist != NULL) {
		printf("%s -> ", pPlaylist->data.artist);
		pPlaylist = pPlaylist->pNext;
	}
	putchar("\n");
}
/*
* storeList()
* created 9/15/2018
* modified 9/15/2018
* description: takes the doubly linked list and prints its current form into the outfile.
*/
void storeList(FILE *outfile, Node *pPlaylist) {
	while (pPlaylist != NULL) {
		fprintf(outfile, "%s,", pPlaylist->data.artist); 
		fprintf(outfile, "%s,", pPlaylist->data.albumTitle);
		fprintf(outfile, "%s,", pPlaylist->data.songTitle);
		fprintf(outfile, "%s,", pPlaylist->data.genre);
		fprintf(outfile, "%d:%d,", pPlaylist->data.duration.minutes, pPlaylist->data.duration.seconds);
		fprintf(outfile, "%d,", pPlaylist->data.timesPlayed);
		fprintf(outfile, "%d\n", pPlaylist->data.rating);

		pPlaylist = pPlaylist->pNext;
	}
}
/*
* displaySearch()
* created 9/15/2018
* modified 9/15/2018
* description: prints songs based on artist name
*/
void displaySearch(char *name, Node *pPlaylist) {
	while (pPlaylist != NULL) {
		if (strcmp(name, pPlaylist->data.artist) == 0) {
			printf("%s\n", pPlaylist->data.songTitle);
		}
		pPlaylist = pPlaylist->pNext;
	}
}
/*
* play()
* created 9/16/2018
* modified 9/16/2018
* description: prints what song is playing
*/
void play(Node *pPlaylist) {
	while (pPlaylist != NULL) {
		printf("Now Playing: %s, by: %s", pPlaylist->data.songTitle, pPlaylist->data.artist);
		Sleep(3000);
		system("cls");
		pPlaylist = pPlaylist->pNext;
	}
}
/*
* rateSong()
* created 9/16/2018
* modified 9/16/2018
* description: allows a user to modify the rating of a song
*/
int rateSong(char *name, char * songTitle, Node **pPlaylist) {
	int newRating = 0;
	int success = 0;
	Node *pMem = NULL;
	pMem = *pPlaylist;

	while (pMem != NULL) {
		if (strcmp(name, pMem->data.artist) == 0 && strcmp(songTitle, pMem->data.songTitle) == 0) {
			success = 1;

			while (newRating > 5 || newRating < 1) {
				printf("Enter a new rating: ");
				scanf("%d", &newRating);
				pMem->data.rating = newRating;
				break;
			}
		}
		pMem = pMem->pNext;
	}
	return success;
}
/*
* editSong()
* created 9/16/2018
* modified 9/16/2018
* description: edits a song based on user input
*/
int editSong(char *name, char *songTitle, Node **pPlaylist) {
	int edit = 1;
	int selection = 0;
	int success = 0;
	int tempInt;
	char strTemp[100];
	Node *pMem = NULL;
	pMem = *pPlaylist;

	while (pMem != NULL) {
		if (strcmp(name, pMem->data.artist) == 0 && strcmp(songTitle, pMem->data.songTitle) == 0) {
			success = 1;
			while (edit == 1) {
				printf("1) Album Title 2) Artist 3) Song Title 4) Genre 5) Duration 6) Times Played 7) Rating");
				printf("Select what you wish to edit: ");
				scanf("%d", &selection);
				switch (selection) {
				case 1:
					printf("Enter new Album Title");
					scanf("%s", &strTemp);
					pMem->data.albumTitle = strTemp;
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 2:
					printf("Enter new Artist name: ");
					scanf(" %[^\n]s", &pMem->data.artist);
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 3:
					printf("Enter new Song Title: ");
					scanf(" %[^\n]s", &pMem->data.songTitle);
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 4:
					printf("Enter new Genre: ");
					scanf(" %[^\n]s", &pMem->data.genre);
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 5:
					printf("Enter new Duration (minutes seconds): ");
					scanf(" %d %d", &pMem->data.duration.minutes, &pMem->data.duration.seconds);
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 6:
					printf("Enter new Times Played: ");
					scanf("%d", &pMem->data.timesPlayed);
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				case 7:
					tempInt = 0;
					while (tempInt > 5 || tempInt < 0) {
						printf("Enter new rating");
						scanf(" %d", &pMem->data.timesPlayed);
					}
					printf("Do you wish to continue editing 1) yes 0) no : ");
					scanf("%d", &edit);
					break;
				}

			}
		}
		if (edit == 0) {
			break;
		}
		else {
			pMem = pMem->pNext;
		}
	}
	return success;
}

void deleteNode(Node **pPlaylist, char *songTitle) {
	Node *pPrev = NULL, *pCur = *pPlaylist;
	int success = 0;
	while ((pCur != NULL) && (strcmp(pCur->data.songTitle,songTitle) != 0)) {
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	if (pCur != NULL) {
		if (pPrev != NULL) {
			pPrev->pNext = pCur->pNext;
		}
		else {
			*pPlaylist = pCur->pNext;
		}
		free(pCur);
	}
}

void insertNewRecord(Node **pPlaylist) {
	Record newRecord;
	int temp = 0, success = 0;
	printf("Enter Artist name: ");
	scanf(" %[^\n]s", &newRecord.artist);
	printf("Enter Album Title: ");
	scanf(" %[^\n]s", &newRecord.albumTitle);
	printf("Enter Song Title: ");
	scanf(" %[^\n]s", &newRecord.songTitle);
	printf("Enter Genre: ");
	scanf(" %[^\n]s", &newRecord.genre);
	printf("Enter Duration (Minutes): ");
	scanf("%d", &newRecord.duration.minutes);
	printf("Enter Duration (Seconds): ");
	scanf("%d", &newRecord.duration.seconds);
	while (success == 0) {
		printf("Enter times played (positive integers including 0): ");
		scanf("%d", &temp);
		if (temp > 0) {
			newRecord.timesPlayed = temp;
			success = 1;
		}
	}
	success = 0;
	while (success == 0) {
		printf("Enter Rating (1-5): ");
		scanf("%d", &temp);
		if (temp >= 1 && temp <= 5) {
			newRecord.rating = temp;
			success = 1;
		}
	}
	insertAtFront(&pPlaylist, newRecord);
}