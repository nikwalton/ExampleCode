/********************
* Nikolaus Walton
* CS 122 PA 1
* Created 8/22/2018
* Last Modified 9/3/2018
* Description: This program parses fitbibt csv file and does data analysis stuff
**********************/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

typedef struct fitbit {
	char Patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitbitData;


int fileCheck(FILE *file);
int checkTarget(char *line, char target[]);

unsigned int getFloorsAndSteps(char *token);
unsigned int getHeartRate(char *token);
unsigned int totalFloors(FitbitData data[]);
unsigned int totalSteps(FitbitData data[]);
unsigned int maxSteps(int *minuteOcur, FitbitData data[]);
unsigned int sleepQuality(int *timeStart, int *timeEnd, FitbitData data[]);


double getDoubleEntry(char *token);
double totalCal(FitbitData data[]);
double totalDist(FitbitData data[]);
double avgHeartRate(FitbitData data[]);


char * getTarget(FILE *infile);
char * getMinute(char *token);
char * minutesToTime(int minuteCount);
#endif // !HEADER_H
