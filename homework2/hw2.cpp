/*
 *	Author:     Run Lin
 *	Project:    Homework 2: Krusty's Operation Atlantis Escape!
 *	Date:       November 9, 2019
 *	File:		functions.cpp
*/

#include "functions.cpp"	// relied functions
using namespace std;

int main()
{
	// initialize my dialogues
	const vector<string> dialogues =
	{
		"Whazzup?",
        "Duuude, totally love the clown head and human body combo!",
        "Looking for a card (shark)?",
        "Are you someone famous?",
        "You look fishy to me; or are you clowning around?",
        "Don't trust the salmon!!!",
        "Here's some advice:  the shark wants you to be his chum!",
        "Better take some paper towels if you visit the blobfish",
        "Hey man, got any sea-weed?",
        "Let me give you my card...my phone number is on the back",
        "I'd gladly pay you Tuesday for a lobster roll today.",
        "Don't be so crabby!",
        "Just keep swimming, swimmin, swimming, ...",
        "You just keep sinking, sinking, sinking,..."
	};
	
    // initialize my vectors
	vector<creature> creatures =
	{
		{"Wanda Walrus", 2, 6, false},
		{"Stanley Sardine", 3, 1, false},
		{"Sylvia Seahorse", 4, 2, false},
		{"Janie Jellyfish", 1, 10, false},
    	{"Doris Dolphin", 8, 4, false},
    	{"Bob Blobfish", 1, 5, false},
    	{"Sammy Shark", 8, 4, false},
    	{"Walter Whale", 6, 2, false},
    	{"Stevie Salmon", 2, 3, false},
    	{"Sheila Shellfish", 1, 3, false},
    	{"Daniel Octopus", 3, 7, false},
    	{"Mark Herrings", 9, 5, false},
    	{"Bernie Tuna", 3, 5, false},
    	{"Oscar Tilapia", 5, 3, false}
	};

	// Let the program greet the user
	greetings();

	// Enter the seed
	get_UserInput();

	// Simulate Krusty's Operation Atlantis Escape!
	simulate_Krusty(dialogues, creatures);

	// print the content of the stack and the creatures that were collected
	print_Content(creatures);

	// calculate Krusty's total Calories burned during his Operation Atlanta
	calculate_Calories();
	
	return 0;
}
