/*
This file contains: GradeCalc
Author: Michail Savelyev
*/                                     //@todo handle wrong inputs

#include <iostream>
using namespace std;

//prototypes
char getGrade(int);
void printGrades(int);
void printStats(int, int, int);

//global variables
int minA = 90;
int minB = 80;
int minC = 70;
int minD = 60;
long failingGrades;
long passingGrades;

//global constants
const long maxStudents = 100;


//arrays
int percentGrade[maxStudents];

int main() {

	char userInput;

	cout << "Set Custom grade limits? [y/n]:";
	cin >> userInput;

	while (userInput != 'y' && userInput != 'n' || cin.fail()) {
		cerr << "\n Invalid Input, Try again. \n";
		cout << "Set Custom grade limits? [y/n]:";
		cin >> userInput;
	}

	cout << endl;

	if (userInput == 'y' || userInput == 'Y') {
		cout << "Enter Min A: ";
		cin >> minA;
		cout << "Enter Min B: ";
		cin >> minB;
		cout << "Enter Min C: ";
		cin >> minC;
		cout << "Enter Min D: ";
		cin >> minD;
	}

	cout << endl;

	int studentAmount = 1;

	cout << "Enter the Number of Students (UP TO " << maxStudents << "): ";

	//handle wrong inputs
	while (!(cin >> studentAmount) || studentAmount > maxStudents || studentAmount < 1) {
		cin.clear();
		cin.ignore();
		cerr << "\nInvalid Input, Try again.\n";
		cout << "Enter a Number (UP TO " << maxStudents << ") ";
	}
	

	// displays to which student each user grade entry applies to
	int student = 1;

	//iterates one time for every student requesting grade from user
	for (int i = 0; i < studentAmount; i++) {

		cout << "Enter score number " << student << ':';

		while (!(cin >> percentGrade[i]) || percentGrade[i] > 100 || percentGrade[i] < 0) {
			cin.clear();
			cin.ignore();
			cerr << "\nInvalid Input\n";
			cout << "Enter a Number (0-100): ";
		}
		student++;
	}

	int best = percentGrade[0];
	int lowest = percentGrade[0];

	//compares every grade to find best
	for (int i = 0; i < studentAmount; i++) {

		if (percentGrade[i] > best) {
			best = percentGrade[i];
		}
	}
	//compares every grade to find lowest
	for (int i = 0; i < studentAmount; i++) {

		if (percentGrade[i] < lowest) {
			lowest = percentGrade[i];
		}
	}

	long sumOfGrades = 1;

	//finds sum of grades
	for (int i = 0; i < studentAmount; i++) {
		sumOfGrades += percentGrade[i];
	}

	int average = sumOfGrades / studentAmount;
	
	//finds sum of failing grades
	for (int i = 0; i < studentAmount; i++) {
		if (percentGrade[i] < minD) failingGrades++;
	}

	//finds sum of passing grades
	for (int i = 0; i < studentAmount; i++) {
		if (percentGrade[i] >= minD) passingGrades++;
	}

	//Clear Screen
	system("cls");

	cout << endl;

	//outputs statistics
	printStats(best, lowest, average);

	//outputs every student's percent and letter grades
	printGrades(studentAmount);

	return 0;
}

//Function definitions:

//returns letter grade according to value of percentGrade array index
char getGrade(int percentGrade) {
	if (percentGrade >= minA) return 'A';
	if (percentGrade >= minB && percentGrade < minA) return 'B';
	if (percentGrade >= minC && percentGrade < minB) return 'C';
	if (percentGrade >= minD && percentGrade < minC) return 'D';
	else return 'F';

}

//outputs every student's percent and letter grades
void printGrades(int studentAmount) { 
	cout << "\nGRADES: " << endl;
	for (int i = 0; i < studentAmount; i++) {
		cout << endl;
		cout << "Student " << i + 1 << " Score is " << percentGrade[i] << " and grade is " << getGrade(percentGrade[i]) << endl;
	}
}

//outputs statistics
void printStats(int best, int lowest, int average) {
	cout << "STATISTICS: " << endl << endl;
	cout << "Highest Grade is: " << best << "% / " << getGrade(best) << endl << endl;
	cout << "Lowest Grade is: " << lowest << "% / " << getGrade(lowest) << endl << endl;
	cout << "Average Grade is: " << average << "% / " << getGrade(average) << endl << endl;
	cout << "Passed: " << passingGrades << endl << endl;
	cout << "Failed: " << failingGrades << endl << endl;
}