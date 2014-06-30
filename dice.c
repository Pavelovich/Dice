#include <stdio.h>
#include "lib/stdfn.h"

int main(int argc, char *argv[]) {
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	intro("Dice", 2014, "MIT");
	int dice = askInt("How many dice do you want to roll? ");
	for (int rolls = 1; rolls <= dice; rolls++) {
		int number = ranGen();
		if (number > 83)
			six++;
		else if (number > 66)
			five++;
		else if (number > 49)
			four++;
		else if (number > 31)
			three++;
		else if (number > 15)
			two++;
		else
			one++;
		busyRun(1000000);
	}
	printf("Six: %d\nFive: %d\nFour: %d\nThree: %d\nTwo: %d\nOne: %d\n", six, five, four, three, two, one);
}