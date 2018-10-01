/*
* PA 2
* Programmed by: Nikolaus Walton
* Date Created: 9/11/2018
* Date Modified: 9/13/2018
* Description: Takes information from a file about songs, stores them in a doubly
*			   linked list and allows the user to perform different operations
*			   on the list of songs provided.
*/
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {
	char *artist;
	char *albumTitle;
	char *songTitle;
	char *genre;
	Duration duration;
	int timesPlayed;
	int rating; // 1 - 5
} Record;

typedef struct node {
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;

Node *makeNode(Record newRecord);

int insertAtFront(Node **pPlaylist, Record newRecord);
int rateSong(char *name, char* songTitle, Node **pPlaylist);
int editSong(char *name, char *songTitle, Node **pPlaylist);

void printList(Node *pPlaylist);
void displaySearch(char *name, Node *pPlaylist);
void deleteNode(Node **pPlaylist, char *songTitle);
void play(Node *pPlaylist);
void insertNewRecord(Node **pPlaylist);

#endif