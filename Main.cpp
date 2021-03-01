#include <iostream>
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

/*Brad Quackenbush
Project One*/

// functions

void  Current_time24(int hour, int minutes, int seconds) {	// defining 24-hr clock 

	cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
}


void Current_time12(int hour, int minutes, int seconds) { // defining 12-hr clock and using conditional statements to determine the hour and if AM or PM

	if (hour == 12) {
		hour = 12;
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " P M";
	}
	else if (hour > 12) {
		hour -= 12;
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " P M";
	}
	else {
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " A M";
	}
}


void InputMenu() { // prints menu for user displaying different options to add time

	cout << "**************************\n";
	cout << "* 1 - Add One Hour       *\n";
	cout << "* 2 - Add One Minute     *\n";
	cout << "* 3 - Add One Second     *\n";
	cout << "* 4 - Exit Program       *\n";
	cout << "**************************\n";
}

void PrintClock12(int hour, int minutes, int seconds) {	// prints current time with 12-hr clock format

	cout << "**************************\n";
	cout << "*      12-Hour Clock     *\n";
	cout << "*      ";
	Current_time12(hour, minutes, seconds);
	cout << "      *\n";
	cout << "**************************\n";
}

void PrintClock24(int hour, int minutes, int seconds) {	// prints current time with 24-hr clock format

	cout << "**************************\n";
	cout << "*      24-Hour Clock     *\n";
	cout << "*        ";
	Current_time24(hour, minutes, seconds);
	cout << "        *\n";
	cout << "**************************\n";
}

void AddHour(int hour, int minutes, int seconds) { // adds one hour to current time

	hour += 1;

	PrintClock12(hour, minutes, seconds);
	PrintClock24(hour, minutes, seconds);
}

void AddMin(int hour, int minutes, int seconds) { // adds one min to current time			

	minutes += 1;

	PrintClock12(hour, minutes, seconds);
	PrintClock24(hour, minutes, seconds);
}

void AddSec(int hour, int minutes, int seconds) { // adds one sec to current time			

	seconds += 1;

	PrintClock12(hour, minutes, seconds);
	PrintClock24(hour, minutes, seconds);
}


int main() {

	// local variables
	int userInput = 0;
	int hour, minutes, seconds;

	// current date/time based on current system
	time_t now = time(0);
	// get local time
	tm* ltm = localtime(&now);
	// save local time to variables
	hour = ltm->tm_hour;
	minutes = ltm->tm_min;
	seconds = ltm->tm_sec;

	// while loop to continue and add hr, min and sec if '4' not received for input
	// if user selects '4' program ends 
	while (userInput != 4) {

		cout << "\n\n\n";

		PrintClock12(hour, minutes, seconds), PrintClock24(hour, minutes, seconds);

		InputMenu();

		cin >> userInput;

		// using switch statements to increment time based on userInput
		switch (userInput) {

		case 1:
			AddHour(hour, minutes, seconds);	
			break;

		case 2:
			AddMin(hour, minutes, seconds);   
			break;

		case 3:
			AddSec(hour, minutes, seconds);	
			break;

		case 4:			
			break; // ends program
		}
		
	}

	return 0;

}
