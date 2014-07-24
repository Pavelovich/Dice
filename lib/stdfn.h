#include <stdio.h>
#include <time.h>
#include <strings.h>
#include <stdlib.h>

/*
*	Standard C functions personal library
*	Copyright © 2014 Aleksandr Pavelovich
*	Free and open source under the MIT license
*
*
*/

#ifndef STDFN_H
#define STDFN_H

int intro(char name[30], int year, char license[10])
{
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("|                     %30s                                                             |\n", name);
	printf("|                     Copyright © %4d Aleksandr Pavelovich                                                      |\n", year);
	printf("|                     Free and open source software for modification and distribution under the                  |\n");
	printf("|                     %10s license                                                                         |\n", license);
	printf("|                                                                                                                |\n");
	printf("------------------------------------------------------------------------------------------------------------------\n");
	return 0;
}

int askInt(char question[200])
{
	int number;
	printf("%s", question);
	scanf("%d", &number);
	//printf("The number is %d \n", number);
	return number;
}

char *askChar(char *question)
{
	char *text = malloc(200*sizeof(char)); // Bro, do you even malloc?
	printf("%s", question);
	scanf("%[^\n]", text);
	//printf("The string is: %s \n", text);
	return text;
}

/* An example setup ^
 * ------------------------------------
 * char *q1 = askChar("Enter your name: ");
 * printf("%s \n", q1);
*/

double askDouble(char question[200])
{
	double number;
	printf("%s", question);
	scanf("%lf", &number);
	//printf("The number is %lf \n", number);
	return number;
}

int gRan1 = 1;
int gRan2 = 1;
int gRan3 = 1;
int ranGen(void)
{
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = gmtime(&rawtime );
	clock_t microseconds = clock() / (CLOCKS_PER_SEC / 100000);
	//printf("%d", &microseconds);
	int ran1 = info->tm_hour;
	int ran2 = info->tm_mday;
	int ran3 = info->tm_mon;
	int ran4 = info->tm_min;
	int ran5 = info->tm_sec;
	int ran6 = microseconds;
	//printf("%d %d %d %d %d \n", ran1, ran2, ran3, ran4, ran5);
	int randomNumber = (((ran1+ran2+gRan1+ran3+ran4+ran5+gRan2+ran6)*(ran1%10)*ran1*ran2*gRan3*ran3*ran6/(ran4%1000)+ran1-(ran5%1000000000))%100);
	randomNumber = (randomNumber*ran5+ran6)%100;
	if (randomNumber < 0)
	{
		randomNumber = randomNumber * -1;
	}
	gRan1 = randomNumber * gRan2 * gRan3 * 4 + 10;
	gRan2 = randomNumber * gRan1 * gRan3 * 2 + 10;
	gRan3 = randomNumber * gRan1 * gRan2 * 3 + 10;
	//printf("%d", randomNumber);
	return randomNumber;
}

int busyRun(int runs)
{
	int number = 0;
	while (number < runs) {
		number++;
	}
	return 0;
}

char printOut(int rate, char *string) // Set around 10 or 20 for the rate
{
	for (int i = 0; i <= strlen(string); i++)
		{
			printf("%c", string[i]);
			fflush(stdout);
			busyRun(rate*1000000);
		}
	return 0;
}

// This function does not even lift.  Please use the one after it.
int cmd(char command[200])
{
	char cmdVar[200];
	strcpy(cmdVar, command);
	printf("Executing command: %s\nOutput:\n", command);
	system(cmdVar);
	return 0;
}

char* bash(char *cmd)
{
	FILE *pcmd = popen(cmd, "r");
	char *output = malloc(200*sizeof(char));
	char *poutput = malloc(200*sizeof(char));
	if (pcmd == NULL)
	{
		printf("The command failed\n");
		exit(0);
	}
	while (fgets(output, sizeof(output)-1, pcmd) != NULL)
	{
		strcat(poutput, output);
	}
	pclose(pcmd);
	return poutput;
}

#endif
