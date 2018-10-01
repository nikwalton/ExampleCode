/********************
* Nikolaus Walton
* CS 122 PA 1
* Created 8/22/2018
* Last Modified 9/3/2018
* Description: This program parses fitbibt csv file and does data analysis stuff
**********************/

#include "header.h"

/*
* fileCheck()
* Created 8/22/2018
* Modified 8/22/2018
* Description: checks if a file is successfully opened
*/
int fileCheck(FILE *file) {
	if (file == NULL) {
		printf("Error: file not found");
		exit(1);
	}
	else {
		return 0;
	}
}
/*
* getTarget()
* Created 9/1/2018
* Modified 9/1/2018
* Description: gets the target ID from the CSV file
*/
char * getTarget(FILE *infile) {
	char buf[50] = { "\0" };
	fgets(buf, 50, infile);
	char *target = strtok(buf, ",");
	target = strtok(NULL, ","); //get next element of the row
	return target;
}

/*
* checkTarget()
* Created 9/1/2018
* Modified 9/1/2018
* Desc: checks if the target of the line is the target for the data
*	we want
*/
int checkTarget(char *line, char target[]) {
	int success = 0;
	char *token = strtok(line, ",");
	if (line != "\0" && token != NULL) {

		success = strcmp(target, token);

		if (success == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}

/*
* getMinute()
* Created 9/1/2018
* Modified 9/1/2018
* Description: gets the minute entry off of the data file
*/
char * getMinute(char *token) {
	token = strtok(NULL, ",");
	char minute[9] = {"\0"};
	if (token != NULL) {
		strcpy(minute, token);
	}
	else {
		return minute;
	}
}
/*
* getDoubleEntry()
* Created 9/2/2018
* Modified 9/2/2018
* Description: gets the calories and distance 
*	entries from the data file
*/
double getDoubleEntry(char *token) {
	token = strtok(NULL, ",");
	double entry = atof(token);
	return entry;
}

/*
* getFloorsAndSteps()
* Created 9/2/2018
* Modified 9/2/2018
* Description: gets the floors, heartRate
*	and steps entries frm the data file. Also works for Sleep.
*/
unsigned int getFloorsAndSteps(char *token) {
	token = strtok(NULL, ",");
	if (token != "\n" && token != NULL) {
		unsigned int val = atoi(token);
		return val;
	}
	else {
		return ;
	}
}

/*
* getHeartRate()
* Created 9/2/2018
* Modified 9/2/2018
* Description: gets the heartrate from the data file,
*/
unsigned int getHeartRate(char *token) {
	token = strtok(NULL, ",");
	unsigned int heartRate = atoi(token);
	return heartRate;
	
}

/*
* minutesToTime()
* Created 9/2/2018
* Modified 9/2/2018
* Description: takes a int minute count in minutes and converts it into
* hh:mm:ss format.
*/
char * minutesToTime(int minuteCount) {
	char min[10] = { "\0" };
	char hr[10] = { "\0" };
	char time[100] = { "\0" };
	int minutes = minuteCount % 60;
	int hours = (minuteCount - minutes) / 60;
	itoa(minutes, min, 10);
	itoa(hours, hr, 10);
	strcat(time, hr);
	strcat(time, ":");
	if (minutes <= 9) {
		strcat(time, "0");
		strcat(time, min);
		strcat(time, ":00");
	}
	else {
		strcat(time, min);
		strcat(time, ":00");
	}
	return time;
}

/*
* totalCal()
* Created 9/3/2018
* Modified 9/3/2018
* Description: uses data from the struct to return the total amount of calories
*			   burned within a 24 hour period
*/
double totalCal(FitbitData data[]) {
	double totalCal = 0.0;
	for (int i = 0; i < 1440; i++) {
		totalCal += data[i].calories;
	}
	return totalCal;
}

/*
* totalDist()
* Created 9/3/2018
* Modified 9/3/2018
* Description: uses data from the struct to return the total amount of
			   distance traveled in miles within a 24 hour period
*/
double totalDist(FitbitData data[]) {
	double totalDist = 0.0;
	for (int i = 0; i < 1440; i++) {
		totalDist += data[i].distance;
	}
	return totalDist;
}

/*
* totalFloors()
* Created 9/3/2018
* Modified 9/3/2018
* Descriptions: uses data from the struct to return the total amount of
*				floors climbed within a 24 hour period
*/
unsigned int totalFloors(FitbitData data[]) {
	unsigned int totalFloors = 0;
	for (int i = 0; i < 1440; i++) {
		totalFloors += data[i].floors;
	}
	return totalFloors;
}

/*
* totalSteps()
* Created 9/3/2018
* Modified 9/4/2018
* Description: uses data from the struct to return the total amount of
			   steps taken within 24 hour period
*/
unsigned int totalSteps(FitbitData data[]) {
	unsigned int totalSteps = 0;
	for (int i = 0; i < 1440; i++) {
		totalSteps += data[i].steps;
	}
	return totalSteps;
}
/* 
* avgHeartRat()
* Created 9/5/2018
* Modified 9/5/2018
* Description: uses data from the struct to return the average
*			   heart rate within a 24 hour period
*/
double avgHeartRate(FitbitData data[]) {
	unsigned int avgHeartRate = 0;
	for (int i = 0; i < 1440; i++) {
		avgHeartRate += data[i].heartRate;
	}
	avgHeartRate = avgHeartRate / 1440;
	return avgHeartRate;
}
/*
* maxSteps()
* Created 9/5/2018
* Modified 9/5/2018
* Description: uses data from the struct to return the max steps taken
*			   within a 24 hour period. If two maxes are found, it returns
*				the later occurance
*/
unsigned int maxSteps(int *minuteOcur, FitbitData data[]) {
	int minutes = 0;
	int max = data[0].steps;
	for (int i = 0; i < 1440; i++) {
		if (data[i].steps > max) {
			max = data[i].steps;
			minutes = i;
		}
	}
	*minuteOcur = minutes;
	return max;
}
/*
* sleepQuality()
* Created 9/5/2018
* Modified 9/5/2018
* Description: finds the longest period of poor quality sleep and returns the 
			 start and end value of the period
*/
unsigned int sleepQuality(int *timeStart, int*timeEnd, FitbitData data[]) {
	unsigned int start = 0, end = 0, max = 0;
	int temp = 0;
	for (int i = 0; i < 1440; i++) {
		if (data[i].sleepLevel > 1 ) {
			max = 0;
			start = i;
			temp = i;
			while (data[temp].sleepLevel > 1) {
				max += data[temp].sleepLevel;
				temp++;
				i = temp;
			}
			end = i - 1;
		}
	}
	*timeStart = start;
	*timeEnd = end;
	return max;
}
