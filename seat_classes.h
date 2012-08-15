#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "files.h"

using namespace std;
const int min_size = 30;
const int max_size = 100;

// base class for getting the Details.
class details
{
protected:

	// Room variables
	string room_no[min_size]; 
	int rows[min_size], cols[min_size], t_rooms;

	// Roll Number variables
	int total_branches, rollno[min_size][max_size], total_rno[min_size];
	int start_roll[min_size], end_roll[min_size];
	string branches[min_size];

	// fstream variable
	ifstream infile;
	ofstream outfile;
	
	int i,j;

public:
	// Getting Details about room and branch.
	void room_details();
	void rollno_details();

};

// Derived class from base class (details)
class seat_planner : public details
{
protected:

	int seat[min_size][min_size][min_size];	// For storing seat plan
	int start, end, start_roll1, start_roll2, end_roll1, end_roll2;
	int x, y, col, row, count[min_size], choice, sum;

	// For next branch and next room
	static int nxt_branch, nxt_room; 
	
	// For test deatils 
	string room, exam_date, exam_time, exam_name; 
	
public:

	void get_details();	// Getting deatils
	void set_branch();	// To set new branch after old one has finished.
	void set_room();	// To set new room
	void seat_plan();	// to fix the seat allocation	
	void set_rollno();	// Setting roll numbers according to branches.
	void output();	// To display the seat allocation
	void valid();	// Validations for strategy
	string branch(int rno);	// Return branch name
	void count_rollno();	// Total Students in room
	void exam_details();	// Getting exam details
	void exam_display();	// Disply aying exam details at the of room
	void report_choice();
	// To set remaining seats on empty places
	void fill_space(int start_roll, int end_roll); 

};


