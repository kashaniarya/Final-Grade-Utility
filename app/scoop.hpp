// Arya Kashani
// 10847777
// ICS 45c
// Project 2
// scoop.hpp

#ifndef SCOOP_HPP
#define SCOOP_HPP
#include <iostream>


struct Student {
	int id;
	std::string gradeOption;
	std::string name;
};

struct Raw {
	int id;
	double cumalitive;
};

void scoopGrades(double* totalPointsPossible, double* relativeWeight, int gradedArtifacts);
void scoopStudents(Student* students, int numberOfStudents);
void scoopRaw(Raw* rawScores, int numberOfStudents2, int gradedArtifacts, double* totalPointsPossible, double* relativeWeight);
void scoopPrint(Student* students, Raw* rawScores, int numberOfStudents, int numberOfStudents2);
void handleCutpointSet(int cutpointSets, int numberOfStudents, int numberOfStudents2, Student* students, Raw* rawScores);

#endif