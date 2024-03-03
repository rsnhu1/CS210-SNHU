// Rashni Singh
// Module 3 Project 1
// February 4, 2024
// CS210

//  This program converts a 24-hour clock into a 12-hour clock and displays both times. Program
//  also allows user to update the time by adding one hour, minute or second to the clocks.


#include<iostream>
#include<cstdlib>

using namespace std;

int main() {


    int twelveHour = 0, twentyFourHour = 0, minutes = 0, seconds = 0;		// declarations
    bool isAM;
    do {
    
        cout << "Enter Hour (24-Hour): ";	// user input for 24 hour hours
        cin >> twentyFourHour;
        if (twentyFourHour > 23) {		    // inpur validation, user must enter number lower than 23
            continue;
        }
        cout << "Enter minutes: ";			
        cin >> minutes;				        // user input for minutes
        if (minutes > 59) {			        // input validation, user must enter number lower than 59
            continue;
        }
        cout << "Enter Seconds: ";
        cin >> seconds;				        // user input for seconds
        if (seconds > 59) {			        // input validation, user must enter number lower than 59
            continue;
        }
        
    } while (twentyFourHour > 23 || minutes > 59 || seconds > 59);


    twentyFourHour > 11 ? isAM = false : isAM = true;		// adjusts am/pm for 12 hour clock
    twelveHour = twentyFourHour % 12;				        // converts 24 hour clock to 12 hour clock


    do {
        cout << "*************************\t*************************\n";		// display for clocks
        cout << "*\t12-Hour Clock\t*\t*\t24-Hour Clock\t*\n";
        cout << "*\t";

        twelveHour < 10 ? cout << "0" << twelveHour << ":" : cout << twelveHour << ":";		// adds 0 in front of hours less than 10 for 12 hour clock
        minutes < 10 ? cout << "0" << minutes << ":" : cout << minutes << ":";			    // adds 0 in front of minutes less than 10 for 12 hour clock
        seconds < 10 ? cout << "0" << seconds << " " : cout << seconds << " ";			    // adds 0 in front of seconds less than 10 for 12 hour clock
        isAM == true ? cout << "AM\t*" : cout << "PM\t";

        cout << "*\t*\t";
        twentyFourHour < 10 ? cout << "0" << twentyFourHour << ":" : cout << twentyFourHour << ":";	    // adds 0 in front of hours less than 10 for 24 hour clock
        minutes < 10 ? cout << "0" << minutes << ":" : cout << minutes << ":";				            // adds 0 in front of minutes less than 10 for 24 hour clock
        seconds < 10 ? cout << "0" << seconds << "\t*" : cout << seconds << "\t*\n";			        // adds 0 in front of seconds less than 10 for 24 hour clock


        cout << "*************************\t*************************\n";


        cout << "*************************\n";		// display menu for adjusting clock
        cout << "*  1 - Add One Hour \t*\n";
        cout << "*  2 - Add One Minute\t*\n";
        cout << "*  3 - Add One Second\t*\n";
        cout << "*  4 - Exit Program \t*\n";
        cout << "*************************\n";

        int choice;
        cin >> choice;

        switch (choice) {

        case 1:

            if (twelveHour == 12) {		// resets 12 hour clock to 1 after the twelfth
                twelveHour = 1;
            }
            else {
                ++twelveHour;
            }
            if (twelveHour > 11) {		// changes clock to PM after 11 AM
                isAM = !isAM;
            }

            if (twentyFourHour == 23) {     // resets hour to to 0 after the 23rd hour for 24 hour clock
                twentyFourHour = 0;
            }
            else {
                ++twentyFourHour;
            }
            continue;

        case 2:

            if (minutes == 59) {        //resets minutes to 0 after 59 minutes
                minutes = 0;
		        twentyFourHour++;
            }
            else {
                ++minutes;
            }
            continue;
        case 3:

            if (seconds == 59) {        //resets seconds to 0 after 59 seconds
                seconds = 0;
                ++minutes;
            }
            else {
                ++seconds;
            }
            continue;

        case 4:
            exit(1);
        }
        
    } while (true);

    return 0;
}