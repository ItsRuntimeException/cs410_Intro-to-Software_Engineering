/*
 *	Author:     Run Lin
 *	Project:    Homework 2: Krusty's Operation Atlantis Escape!
 *	Date:       November 9, 2019
 *	File:		functions.h
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string> 		// string name
#include <vector> 		// vector of creature
#include <cstdlib>		// rand()
#include <ctime>  		// srand()
#include <iostream>		// cout, cin
#include <sstream>		// check for input.empty()
#include <algorithm>    // std::sort
using namespace std;

const int INIT_SIZE = 0;
const int MAX_SIZE = 6;
const int MAX_CARDS = 150;

struct creature
{
	string name;
	int length;
	int width;
	bool collected;
};

void greetings();
void get_UserInput();
void print_Content(const vector<creature> creatures);
void calculate_Calories();
void simulate_Krusty(const vector<string> dialogues, vector<creature> & creatures);
void insert_to_Stackable(vector<creature> &stackable, const creature atlantians);
bool leavature(const vector<creature> stackable, const vector<creature> creatures);
bool isStackable_Upperbound(const int x1, const int y1, const int x2, const int y2);
bool isStackable_Lowerbound(const int x1, const int y1, const int x2, const int y2);
bool is_Equalbound(const int x1, const int y1, const int x2, const int y2);
int random(const int range);

#endif
