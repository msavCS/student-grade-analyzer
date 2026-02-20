# Student Grade Analyzer

A lightweight C++ console application that helps teachers and instructors quickly analyze student grades, calculate statistics, and assign letter grades based on customizable thresholds.

Currently a terminal-based tool — **web interface + tiny backend server coming soon**.

## Features

- Customizable grade boundaries (A/B/C/D/F thresholds)
- Input validation for number of students and individual scores (0–100)
- Calculates and displays:
  - Highest score + letter grade
  - Lowest score + letter grade
  - Class average + letter grade
  - Number of passing students
  - Number of failing students
- Clean per-student output showing percentage and corresponding letter grade
- Simple, beginner-friendly code structure

## Current Version (Console)

```text
Set Custom grade limits? [y/n]:
Enter the Number of Students (UP TO 100):
Enter score number 1: ...
...
STATISTICS:
Highest Grade is: 98% / A
Lowest Grade is:  42% / F
Average Grade is: 78% / C
Passed:  24
Failed:   6

GRADES:
Student 1  Score is 98 and grade is A
Student 2  Score is 85 and grade is B
...
