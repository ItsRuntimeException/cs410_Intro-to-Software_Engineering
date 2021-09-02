/*
*   Author:     Run Lin
*   Project:    Homework 1: Health-o-matic Program
*   Date:       October 1, 2019
*/

#include <iostream>
using namespace std;

// We promise the compiler that we will have these functions.
void greetings();
short getOptions();
int walk();
int getDay();
int getAnxiety();
void printPills(int);
int medication();
int getHours();
void printNaps(int);
int napTime(int, int);
void outputCalories(int cals);
float caloricIntake(int);

// The core function for the selection of functionalities to execute.
int main() {
    int distWalk = -1, pillTakes = -1;

    // Greet the user.
    greetings();
    short option;
    do {
        // display all the options.
        option = getOptions();
        // Big switch statement to determine which functionalities to execute.
        switch (option)
        {
        case 1:
            distWalk = walk();
            cout << "Number of steps: " << distWalk << "\n" << endl;
            break;
        case 2:
            pillTakes = medication();
            break;
        case 3:
            if (distWalk >= 0 && pillTakes >= 0) {
                napTime(distWalk, pillTakes);
            }
            else // either option 1 or 2 did not run previously.
            {
                // error message
                cout << "Option 1 or 2 did not execute prior to option 3, unable to proceed.\n" << endl;
            }
            break;
        case 4:
            if (distWalk >= 0) {
                caloricIntake(distWalk);
            }
            else
            {
                // error message
                cout << "Option 1 did not execute prior to option 4, unable to proceed.\n" << endl;
            }
            break;
        default:
            cout << endl;
            break;
        }
    } while (option < 5);
    return 0;
}

void greetings() {
    cout << "Greetings dear user! This program is called Health-o-Matic, it contains several functionalities in which it can make your healthier!" << endl;
    cout << "Programmed by Run Lin.\n" << endl;
}

short getOptions() {
    short x;
    cout << "Health-o-Matic Options\n";
    cout << "----------------------------\n\n";
    cout << "1. Taking a Walk!\n";
    cout << "2. Your Medications\n";
    cout << "3. Nap Time!!\n";
    cout << "4. Caloric Intake\n";
    cout << "5. Quit\n\n";
    cout << "Choose an option : "; // Type a number, then enter.
    cin >> x;
    return x;
}

// Calculate the number of steps to user should take by asking how many legs they have.
int walk() {
    int i, numSteps, numLegs;
    cout << "Enter the number of legs: "; // numLegs = ?
    cin >> numLegs; // user input for numLegs.
    numSteps = 1;

    for (i = 1; i <= numLegs; ++i) {
        numSteps *= i;
    }
    return numSteps;
}

// Request user input for the day of the week.
int getDay() {
    int dayOfWeek;

    do {
        cout << "Enter the day of the week (1-7): "; // dayOfWeek = ?
        cin >> dayOfWeek;
        if (dayOfWeek < 1 || dayOfWeek > 7) {
            cout << "invalid day of week, try again...\n";
        }
    } while (dayOfWeek < 1 || dayOfWeek > 7);
    return dayOfWeek;
}

// Request user input for their level of anxiety.
int getAnxiety() {
    int anxietyLevel;

    do {
        cout << "Enter your anxiety level (1-10): "; // anxietyLevel = ?
        cin >> anxietyLevel; // user input for anxietyLevel.
        if (anxietyLevel < 1 || anxietyLevel > 10) {
            cout << "invalid day of week, try again...\n";
        }
    } while (anxietyLevel < 1 || anxietyLevel > 10);
    return anxietyLevel;
}

// Output the number of pills to take to the terminal.
void printPills(int numPill) {
    cout << "Number of pills to take: " << numPill << "\n" << endl;
}

// Calculate the number of pills to take.
int medication() {
    int numPills;

    numPills = getAnxiety() - getDay();

    // if numPills is negative, set to 0.
    if (numPills <= 0) {
        numPills = 0;
    }
    printPills(numPills);
    return numPills;
}

// Request user input for their hours of sleep the previous day.
int getHours() {
    int numHourSlept;
    cout << "How many hours did you sleep last night: "; // anxietyLevel = ?
    cin >> numHourSlept; // user input for numHourSlept.
    return numHourSlept;
}

// Output the minutes of nap to take to the terminal.
void printNaps(int minNap) {
    cout << "minutes of nap to take: " << minNap << "\n" << endl;
}

// Calculate the nap time by distance walked, pills taken, and the user's input for hours of sleep they had.
int napTime(int dWalk, int pTake) {
    int minutesToNap, pills, hrSlept;
    
    hrSlept = getHours();
    
    pills = pTake;
    // if pills taken is negative, set to 1, so we don't upset the denominator later when calculating minutesToNap.
    if (pills == 0) {
        pills = 1;
    }

    minutesToNap = hrSlept + dWalk / pills;
    printNaps(minutesToNap);
    return minutesToNap;
}

// Output the maximum calories intake to the terminal.
void outputCalories(float c) {
    cout << "Max calories intake: " << c << "\n" << endl;
}

// Calculate the maximum calories intake given distance walked, and get user's input for weight, height, and room temperature.
float caloricIntake(int dWalk) {
    float cals, weight, height, roomTemp;

    do {
        cout << "Enter your weight (lbs): ";
        cin >> weight;
        if (weight < 0 || weight > 800) {
            cout << "Over 800lbs, please re-enter...\n" << endl;
        }
    } while (weight < 0 || weight > 800);

    cout << "Enter your height (inches): ";
    cin >> height;
    cout << "Enter the room's temperature (F): ";
    cin >> roomTemp;

    cals = 6 * weight + 2 * height + 1/(roomTemp) + dWalk;
    outputCalories(cals);
    return cals;
}
