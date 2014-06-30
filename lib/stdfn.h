#include <stdio.h>
#include <time.h>

/*
*	Standard C functions personal library
*	Copyright © 2014 Sasha Pavelovich
*	Free and open source under the MIT license
*
*
*/

int intro(char name[30], int year, char license[10])
{
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("|                     %30s                                                             |\n", name);
	printf("|                     Copyright © %4d Sasha Pavelovich                                                          |\n", year);
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

char askChar(char question[200])
{
	char text[200];
	printf("%s", question);
	scanf("%s", text);
	//printf("The string is: %s \n", text);
	return *text;
}

double askDouble(char question[200])
{
	double number;
	printf("%s", question);
	scanf("%lf", &number);
	//printf("The number is %lf \n", number);
	return number;
}

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
	int randomNumber = (((ran1+ran2+ran3+ran4+ran5+ran6)*(ran1%10)*ran1*ran2*ran3*ran6/(ran4%1000)+ran1-(ran5%1000000000))%100);
	randomNumber = (randomNumber*ran5+ran6)%100;
	if (randomNumber < 0)
	{
		randomNumber = randomNumber * -1;
	}
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