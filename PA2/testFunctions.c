#include "testFunctions.h"
#include "header.h"
void testInsert() {
	Node *pPlaylist = NULL;
	insertNewRecord(&pPlaylist);
	if (pPlaylist != NULL) {
		printf("Data inserted into list!");
		if (pPlaylist->data.rating >= 5 || pPlaylist->data.rating <= 1) {
			printf("Rating is within the acceptable value range!");
		}
		else {
			printf("Rating is not within the acceptable value range!");
		}
		if (pPlaylist->data.timesPlayed > 0) {
			printf("Times Played is non-negative!");
		}
		else {
			printf("Times played is negative!");
		}
	}
	else {
		printf("Insertion of data failed!");
	}
}
void testDelete() {

}
void testShuffle() {

}
