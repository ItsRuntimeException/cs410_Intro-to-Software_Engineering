/*
 *	Author:     Run Lin
 *	Project:    Homework 2: Krusty's Operation Atlantis Escape!
 *	Date:       November 9, 2019
 *	File:		functions.cpp
*/

#include "functions.h"	// function prototypes
using namespace std;

// stacking requirement
int seed = 0;
// stack
vector<creature> stackable(INIT_SIZE);

/* Requirement description:
 * As an example: card1 is 4 x 8, card2 is 2 x 9. These can NOT satisfy Krusty's criteria since there is no way to orient (at right angles) 
 * these two cards without one hanging over the other. As another example: card1 is 2 x 3 and card2 is 1 x 2. These two CAN satisfy Krusty's criteria
 * since card2 can be stacked below card1 in a way that it will not hang over the top card since 1 < 2 and 2 < 3. So, you see, you must compare the cards in both orientations.
 * Both dimensions of a Lowerbound card must not exceed either dimensions of an Upperbound card, and at least one dimension of an Upperbound card must be strictly greater than at least one dimension of a Lowerbound card.
 * (Another ex: a 1 x 1 card can be below a 1 x 2 card).
 * (card_1 stack on top of card_2)
 * 
 * Compare the previous index if it can be inserted
 * 
 * Post-condition: This is the requirement#1 for determining vector insertion
*/
bool isStackable_Upperbound(const int x1, const int y1, const int x2, const int y2)
{
	if ((x1 > x2) && (y1 >= y2))
		return true;
	else if ((x1 >= x2) && (y1 > y2))
		return true;
	else if ((x1 > y2) && (y1 >= x2))
		return true;
	else if ((x1 >= y2) && (y1 > x2))
		return true;
	else
		return false;
}

/* Requirement description:
 * Compare the current index (Lowerbound bound) if it can be inserted in between
 * 
 * Post-condition: This is the requirement#2 for determining vector insertion
*/
bool isStackable_Lowerbound(const int x1, const int y1, const int x2, const int y2)
{
	if ((x1 < x2) && (y1 <= y2))
		return true;
	else if ((x1 <= x2) && (y1 < y2))
		return true;
	else if ((x1 < y2) && (y1 <= x2))
		return true;
	else if ((x1 <= y2) && (y1 < x2))
		return true;
	else
		return false;
}

bool is_Equalbound(const int x1, const int y1, const int x2, const int y2)
{
	if ( (x1 == x2) && (y1 == y2) )
	{
		return true;
	}
	else if ( (x1 == y2) && (y1 == x2) )
	{
		return true;
	}
	else
		return false;
}
/* Requirement description:
 * Pre-condition: pass in a working stackable vector, and creatures vector
 * 
 * Post-condition: Checks for the condition in which if Krusty is able to leave yet, [true for YES, false for NO]
*/
bool leavature(const vector<creature> stackable, const vector<creature> creatures) {
	int collected = 0;
	// stack contains 6 different card dimensions
	if (stackable.size() == MAX_SIZE) {
		return true;
	}
	
	// all creatures collected
	for (int i = 0; i < creatures.size(); i++)
	{
		if (creatures[i].collected)
		{
			collected++;
		}
	}
	if (collected == creatures.size()) {
		return true;
	}
	return false;
}

/* Requirement description:
 * Pre-condition:  Pass in a working stack, empty or not. It is also referenced such that it will update by reference, not by value
 * Pre-condition2: Also pass in a random creature to be determined if it is eligible to be inserted into the stack
 * 
 * Post-condition: push the creature into the stack vector IF the requirements are met
*/
void insert_to_Stackable(vector<creature> &stackable, creature atlantians)
{
	if (stackable.size() > 1)
	{
		for (int i = 0; i < stackable.size()-1; i++)
		{
			if (is_Equalbound(stackable[i].length, stackable[i].width, atlantians.length, atlantians.width))
			{
				break;
			}
			// insert front
			if (i == 0 && isStackable_Lowerbound(stackable[i].length, stackable[i].width, atlantians.length, atlantians.width))
			{
				stackable.insert(stackable.begin()+i, atlantians);
				break;
			}
			// insert last
			else if (i == stackable.size()-2)
			{
				if (isStackable_Upperbound(stackable[i+1].length, stackable[i+1].width, atlantians.length, atlantians.width))
				{
					stackable.push_back(atlantians);
					break;
				}
			}
			// insert everything in between
			else if(isStackable_Upperbound(stackable[i].length, stackable[i].width, atlantians.length, atlantians.width))
			{
				if (isStackable_Lowerbound(stackable[i+1].length, stackable[i+1].width, atlantians.length, atlantians.width))
				{
					stackable.insert(stackable.begin()+(i+1), atlantians);
					break;
				}
			}
		}
	}
	// exceptions
	if (stackable.size() == 1)
	{
		if (isStackable_Lowerbound(stackable[0].length, stackable[0].width, atlantians.length, atlantians.width))
		{
			stackable.insert(stackable.begin(), atlantians);
		}
		else if (isStackable_Upperbound(stackable[0].length, stackable[0].width, atlantians.length, atlantians.width))
		{
			stackable.push_back(atlantians);
		}
	}
	// exceptions
	if (stackable.empty())
	{
		stackable.push_back(atlantians);
	}
	cout << "STACK AFTER COMPARISON:\n";
	for(int i = 0; i < stackable.size(); i++) {
		cout << "(" << stackable[i].length << ", " << stackable[i].width << ")";
		cout << " || ";
		cout << "(" << stackable[i].width << ", " << stackable[i].length << ")\t";
		cout << stackable[i].name << endl;
	}
	cout<<endl;
}

// Helper function for randomizing from a certain range
int random(const int range)
{
	return rand() % range; // limit from index 0 ~ range
}

void greetings() {
    cout << "\nGreetings dear user! This program is called \"Krusty's Operation Atlantis Escape!\",\nit simulates Krusty's mission to escape from Atlantis!" << endl;
    cout << "Programmed by Run Lin.\n" << endl;
}

void get_UserInput() {
	cout << "Enter the seed number to generate its randomness (you should enter 37, blank will result in true randomness: ";
	string input;
	getline(cin, input);
	// psuedo random based on seed number
	if (!input.empty()) {
		istringstream stream(input); // convert string to integer
		stream >> seed;
		srand(seed);
	}
	// true random
	else {
		srand(time(NULL));
	}
}

void simulate_Krusty(const vector<string> dialogues, vector<creature> & creatures) {
	int counter = 0;
	while (counter < MAX_CARDS && !leavature(stackable, creatures))
	{
		string current_Dialogue;
		
		int rand1 =  random(creatures.size()); // random is the limit from index 0 ~ creatures.size()
		int rand2 =  random(creatures.size()); // random is the limit from index 0 ~ creatures.size()
		
		cout << "CURRENT CREATURE: " << creatures[rand1].length << ", " << creatures[rand1].width << "\t";
		cout << creatures[rand1].name << endl;
		creatures[rand1].collected = true;
		current_Dialogue = dialogues[rand2];	// passed by value

		cout << creatures[rand1].name << " said:\t" << current_Dialogue << endl;
		insert_to_Stackable(stackable, creatures[rand1]);
		counter ++;
		// let's print the dialogue
	}
	if (counter == 150)
		cout << "Krusty might as well live(die) in Atlantis(forever). HA. HA. HA...\n";
}

void print_Content(const vector<creature> creatures) {
	int collected = 0;

	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	// let's print the stack
	cout << "\nFINAL STACK CONTENT:\n";
	for(int i = 0; i < stackable.size(); i++) {
		cout << "(" << stackable[i].length << ", " << stackable[i].width << ")";
		cout << " || ";
		cout << "(" << stackable[i].width << ", " << stackable[i].length << ")\t";
		cout << stackable[i].name << endl;
	}
	if (stackable.size() < MAX_SIZE)
	{
		cout << "\nKrusty had only found " << stackable.size() << " stackable cards\n";
	}
	else
	{
		cout << "\nKrusty found all " << MAX_SIZE << " stackable cards\n";
		cout << endl;
	}



	// let's print the creatures that he obtained (aka print creature's name is creature[i].collected == true)
	cout << "\nCREATURES COLLECTED:\n";
	for(int i = 0; i < creatures.size(); i++) {
		if (creatures[i].collected == true) {
			cout << creatures[i].name << endl;
			collected++;
		}
	}
	if (collected < creatures.size())
	{
		cout << "\nKrusty had only found " << collected << " creatures\n";
	}
	else
	{
		cout << "\nKrusty found all " << creatures.size() << " stackable cards\n";
		cout << endl;
	}

	if (stackable.size() == MAX_SIZE || collected == creatures.size())
	{
		cout << "\nKrusty says: I'M GETTING THE **** OUTTA HERE!!! SAYONARA ATLANTIANS!!!!\n" << endl;
	}

	cout << "\n//////////////////////////////////////////////////////////////////////////////////////////////////////////\n" << endl;
}

void calculate_Calories() {
	float weight = 0;
	float height = 0;
	float temperature = 0;
	cout << "During the times when Krusty was trying to get out of Atlanta, he had walked 6 miles.";
	cout << "\nWhy don't you decide his weight(lbs), height(ft), and temperature(*Celcius) at Atlanta\nso his Calories burned is calculated;\n";
	cout << "weight(lbs): ";
	cin >> weight;
	cout << "height(ft): ";
	cin >> height;
	cout << "temperature(*Celcius): ";
	cin >> temperature;

	float calories = 0;
	// Lambda to calculate krusty's calories burned
	auto calc_caloric = [&calories] (float wt, float ht, float temp)
	{
    	calories = (6*wt)+(2*ht)+(1/temp)+6;
	};

	calc_caloric(weight, height, temperature);
	cout << "Krusty's total calories burned: " << calories << " Cals" << endl;
}