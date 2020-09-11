// Arya Kashani
// 10847777
// ICS 45c
// Project 2
// main.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "scoop.hpp"


int main()
{
	int gradedArtifacts;
	std::cin >> gradedArtifacts;

	double* totalPointsPossible = new double[gradedArtifacts];
	double* relativeWeight = new double[gradedArtifacts];

	scoopGrades(totalPointsPossible, relativeWeight, gradedArtifacts);

	int numberOfStudents;
	std::cin >> numberOfStudents;
	std::cin.ignore(1);

	Student* students = new Student[numberOfStudents];

	scoopStudents(students, numberOfStudents);

	int numberOfStudents2;
	std::cin >> numberOfStudents2;
	std::cin.ignore(1);
	
	Raw* rawScores = new Raw[numberOfStudents2];

	scoopRaw(rawScores, numberOfStudents2, gradedArtifacts, totalPointsPossible, relativeWeight);
	
	scoopPrint(students, rawScores, numberOfStudents, numberOfStudents2);

	int cutpointSets;
	std::cin >> cutpointSets;
	std::cin.ignore(1);

	handleCutpointSet(cutpointSets, numberOfStudents, numberOfStudents2, students, rawScores);

	delete[] totalPointsPossible;
	delete[] relativeWeight;
	delete[] students;
	delete[] rawScores;
	
    return 0;
}


















