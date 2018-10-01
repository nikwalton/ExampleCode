#include "header.h"

/********************
* Nikolaus Walton
* CS 122 PA 1
* Created 8/22/2018
* Last Modified 9/3/2018
* Description: This program parses fitbibt csv file and does data analysis
**********************/

int main() {
	int minuteCount = 0; //used to index the minutes for struct arr
	int success = 0; //used for strcmp
	int timeSuccess = 0; //used for checking for duplicate entries
	int timeStart = 0;  //start and end used for sleep quality
	int timeEnd = 0;    
	

	unsigned int intTemp = 0; 
	
	double doubTemp = 0.0;


	char line[100] = { "\0" };
	char *token = { "\0" };
	char tarCopy[10];
	char *saveTarget = { "\0" };
	char *tokTemp = { "\0" };
	char *tempTime = { "\0" };
	char *tempTime2 = { "\0" };
	char curTime[10];
	char endTime[10];

	FitbitData data[1440] = { "\0","\0",0,0,0,0,0,NONE};
	
	FILE *inputFile = fopen("FitbitData.csv", "r");
	FILE *outputFile = fopen("Results.csv", "w");
	
	fileCheck(inputFile);
	
	//start of data processing
	token = getTarget(inputFile);
	strcpy(tarCopy, token);
	fgets(line, 100, inputFile); //get rid of the labing patient minutes etc.
	
	while (! feof(inputFile)) {
		fgets(line, 100, inputFile);
		
		success = checkTarget(line, tarCopy);
		if (success == 0) { //check if it is the righ patient
		
			//get time from count and parse it into string format used in csv file
			tempTime = minutesToTime(minuteCount);
			strcpy(curTime, tempTime);

			tokTemp = getMinute(token); // get time from csv file
			timeSuccess = strcmp(tokTemp, curTime);

			if (timeSuccess == 0) { //checks if it is a duplicate entry at that time slot
				//copy patient ID to the struct
				strcpy(data[minuteCount].Patient, tarCopy);
				
				//copy the minute value to the struct
				strcpy(data[minuteCount].minute, tokTemp);
				
				//get calorie data from FitbitData.csv
				doubTemp = getDoubleEntry(token);
				data[minuteCount].calories = doubTemp;
				
				//get distance data from FitbitData.csv
				doubTemp = getDoubleEntry(token);
				data[minuteCount].distance = doubTemp;
				
				//get floors data from FitbitData.csv
				intTemp = getFloorsAndSteps(token);
				data[minuteCount].floors = intTemp;
				
				//get heartRate data from FitbitData.csv
				/*checks for double comma instances within the file since it only 
				  occurs with the heart rate with this particular file. Can be 
				  implemented to all other data cases too*/
				if (line[29] == '\0' && line[30] == ',') {
					data[minuteCount].heartRate = 0;
				}
				else {
					intTemp = getHeartRate(token);
					data[minuteCount].heartRate = intTemp;
				}
				
				//get steps data from FitbitData.csv
				intTemp = getFloorsAndSteps(token);
				data[minuteCount].steps = intTemp;
				
				//get sleep data from FitBitData.csv
				intTemp = getFloorsAndSteps(token);
				data[minuteCount].sleepLevel = intTemp;
				
				minuteCount++; //add one to the minute counter
			}
		}
		else {
			continue; //skip this line
		}

	}
	//end data processing
	
	fprintf(outputFile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	doubTemp = totalCal(data);
	fprintf(outputFile, "%lf,", doubTemp); //print total calories
	doubTemp = totalDist(data);
	fprintf(outputFile, "%lf,", doubTemp); //print total distance
	intTemp = totalFloors(data);
	fprintf(outputFile, "%d,", intTemp); //print total floors
	intTemp = totalSteps(data);
	fprintf(outputFile, "%d,", intTemp); //print total steps
	doubTemp = avgHeartRate(data);
	fprintf(outputFile, "%lf,", doubTemp); //print avg heartrate
	intTemp = maxSteps(&minuteCount, data);
	fprintf(outputFile, "%d,", intTemp); // print max steps
	intTemp = sleepQuality(&timeStart, &timeEnd, data);
	tempTime = minutesToTime(timeStart);
	strcpy(curTime, tempTime);
	tempTime2 = minutesToTime(timeEnd);
	strcpy(endTime, tempTime2);
	fprintf(outputFile, "%s : %s\n", curTime, endTime); //print range of poor sleep

	fprintf(outputFile,"Target: ,%s,,,,,,\n", tarCopy);
	fprintf(outputFile, "Patient,minute,calories,distance,floors,heart,steps,sleep_level\n");
	
	for (int i = 0; i < 1440; i++) {
		fprintf(outputFile, "%s,", data[i].Patient);
		fprintf(outputFile, "%s,", data[i].minute);
		fprintf(outputFile, "%lf,", data[i].calories);
		fprintf(outputFile, "%lf,", data[i].distance);
		fprintf(outputFile, "%d,", data[i].floors);
		fprintf(outputFile, "%d,", data[i].heartRate);
		fprintf(outputFile, "%d,", data[i].steps);
		fprintf(outputFile, "%d\n", data[i].sleepLevel);
	}
	printf("Results printed to Results.csv");
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}