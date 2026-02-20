/*
This file contains: GradeCalc
Author: Michail Savelyev
*/                                     //@todo handle wrong inputs

#include <iostream>
using namespace std;

//prototypes
char getGrade(int);
void printGrades(int);
void printStats(int, int, int, int, int, string, string);
void printLine();

//global variables
int minA = 90 , minB = 80 , minC = 70 , minD = 60;
long failingGrades = 0;
long passingGrades = 0;

//global constants
const long maxStudents = 100;


//arrays
int percentGrade[maxStudents];
string studentNames[maxStudents];

int main() {

	char userInput;

	cout << "Set Custom Grade Thresholds? [y/n]:";
	cin >> userInput;

	while (userInput != 'y' && userInput != 'n' || cin.fail()) {
		cerr << "\n Invalid Input, Try again. \n";
		cout << "Set Custom grade limits? [y/n]:";
		cin >> userInput;
	}

	printLine();
	
	if (userInput == 'y' || userInput == 'Y') {
		cout << "Enter Min A: ";
		cin >> minA;
		cout << "Enter Min B: ";
		cin >> minB;
		cout << "Enter Min C: ";
		cin >> minC;
		cout << "Enter Min D: ";
		cin >> minD;
		printLine();
	}

	int studentAmount = 1;

	cout << "Enter the Number of Students (UP TO " << maxStudents << "): ";

	//handle wrong inputs
	while (!(cin >> studentAmount) || studentAmount > maxStudents || studentAmount < 1) {
		cin.clear();
		cin.ignore();
		cerr << "\nInvalid Input, Try again.\n";
		cout << "Enter a Number (UP TO " << maxStudents << ") ";
	}
	printLine();
	
	// displays to which student each user grade entry applies to
	int student = 1;

	//Requests Name And Grade of every student
	for (int i = 0; i < studentAmount; i++) {

		cout << "\nEnter Student's Last Name:";

		while (!(cin >> studentNames[i])) {
			cin.clear();
			cin.ignore();
			cerr << "\nInvalid Input\n";
			cout << "Enter Student Names:";
		}

		cout << "Enter " << studentNames[i] << "'s score: ";

		while (!(cin >> percentGrade[i]) || percentGrade[i] > 100 || percentGrade[i] < 0) {
			cin.clear();
			cin.ignore();
			cerr << "\nInvalid Input\n";
			cout << "Enter a Number (0-100): ";
		}
		cout << "\nStudent " << student << ": " << studentNames[i] << "'s Grade Entered Successfully";
		printLine();

		student++;
	}

	int best = percentGrade[0], lowest = percentGrade[0];
	long sumOfGrades = 0;

	string bestStudent = studentNames[0], lowestStudent = studentNames[0];


	//finds best, lowest, sum of  the grades & passing/failing totals
	for (int i = 0; i < studentAmount; i++) {
		sumOfGrades += percentGrade[i];
		if (percentGrade[i] > best) {
			best = percentGrade[i];
			bestStudent = studentNames[i];
		}
		if (percentGrade[i] < lowest) {
			lowest = percentGrade[i];
			lowestStudent = studentNames[i];
		}
		if (percentGrade[i] < minD) failingGrades++;
		else passingGrades++;
	}
	int average = sumOfGrades / studentAmount;

	int passRate = (passingGrades * 100) / studentAmount;
	int failRate = (failingGrades * 100) / studentAmount;

	//Clear Screen
	system("cls");

	cout << endl;

	//outputs every student's percent and letter grades
	printGrades(studentAmount);

	printLine();

	//outputs statistics
	printStats(best, lowest, average , passRate, failRate , bestStudent , lowestStudent);

	printLine();

	return 0;
}

//Function definitions:

//returns letter grade according to percent grade
char getGrade(int percentGrade) {
	if (percentGrade >= minA) return 'A';
	if (percentGrade >= minB) return 'B';
	if (percentGrade >= minC) return 'C';
	if (percentGrade >= minD) return 'D';
	else return 'F';

}

//outputs every student's percent and letter grades
void printGrades(int studentAmount) { 
	cout << "GRADES: " << endl;
	printLine();
	for (int i = 0; i < studentAmount; i++) {
		cout << endl;
		cout << "Student: " << studentNames[i] << endl;
		cout << "Percentage:  " << percentGrade[i] << endl;
		cout << "Letter Grade: " << getGrade(percentGrade[i]) << endl;
		cout << endl;
	}
}

//outputs statistics
void printStats(int best, int lowest, int average, int passRate, int failRate , string bestStudent, string lowestStudent) {
	cout << "STATISTICS: " << endl;
	printLine();
	cout << "Highest Grade is: " << bestStudent << ' ' << best << "% / " << getGrade(best) << endl << endl;
	cout << "Lowest Grade is: " << lowestStudent << ' ' << lowest << "% / " << getGrade(lowest) << endl << endl;
	cout << "Average Grade is: " << average << "% / " << getGrade(average) << endl << endl;
	cout << "Passed: " << passingGrades << endl;
	cout << "Pass Rate: " << passRate << '%' << endl << endl;
	cout << "Failed: " << failingGrades << endl;
	cout << "Fail Rate: " << failRate << '%' << endl << endl;
}

//prints a seperation line
void printLine(){
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << '=';
	}
	cout << endl << endl;
}