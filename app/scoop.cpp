// Arya Kashani
// 10847777
// ICS 45c
// Project 2
// scoop.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "scoop.hpp"

struct Student students;

struct Raw rawScores;

void scoopGrades(double* totalPointsPossible, double* relativeWeight, int gradedArtifacts) {
	for(int i=0; i < gradedArtifacts; i++) {
		int x;
		std::cin >> x;
		totalPointsPossible[i] = x;
	}
	for(int i=0; i < gradedArtifacts; i++) {
		int x;
		std::cin >> x;
		relativeWeight[i] = x;
	}
}

void scoopStudents(Student* students, int numberOfStudents) {
	for(int i=0; i < numberOfStudents; i++) {
		std::string s;
		std::getline (std::cin, s);
		int position = s.find(" ");
		int temp = std::stoi(s.substr(0,position));
		students[i].id = temp;
		s.erase(0, position+1);
		students[i].gradeOption = s.substr(0,1);
		s.erase(0,2);
		students[i].name = s;
	}
}

void scoopRaw(Raw* rawScores, int numberOfStudents2, int gradedArtifacts, double* totalPointsPossible, double* relativeWeight) {
	for(int i=0; i < numberOfStudents2; i++) {
		std::string s;
		std::getline(std::cin, s);
		int position = s.find(" ");
		int num = std::stoi(s.substr(0,position));
		s.erase(0, position+1);
		rawScores[i].id = num;
		double cum = 0.0;
		for(int j=0; j < gradedArtifacts; j++) {
			if(j == gradedArtifacts-1) {
				double x = std::stod(s);
				double n = x / totalPointsPossible[j];
				n = n * relativeWeight[j];
				cum += n;
			}
			else {
				int pos = s.find(" ");
				double x = std::stod(s.substr(0, pos));
				s.erase(0, pos+1);
				double n = x / totalPointsPossible[j];
				n = n * relativeWeight[j];
				cum += n;
			}
		rawScores[i].cumalitive = cum;
		}
	}
}

void scoopPrint(Student* students, Raw* rawScores, int numberOfStudents, int numberOfStudents2) {
	std::cout << "TOTAL SCORES" << std::endl;
	for(int i=0; i < numberOfStudents; i++) {
		std::cout << students[i].id << " " << students[i].name << " ";
		bool found = false;
		for(int j=0; j < numberOfStudents2; j++) {
			if(students[i].id == rawScores[j].id) {
				std::cout << rawScores[j].cumalitive << std::endl;
				found = true;
			}
		}
		if(found == false) {
			std::cout << 0.0 << std::endl;
		}
	}
}

void handleCutpointSet(int cutpointSets, int numberOfStudents, int numberOfStudents2, Student* students, Raw* rawScores) {
	for(int i=0; i < cutpointSets; i++) {
		std::cout << "CUTPOINT SET " << i+1 << std::endl;
		std::string s;
		std::getline(std::cin, s);
		double* cp = new double[4];
		for(int j=0; j < 4; j++) {
			if(j == 3) {
				double grade = std::stod(s);
				cp[j] = grade;
			}
			else {
				int position = s.find(" ");
				double grade = std::stod(s.substr(0,position));
				s.erase(0, position+1);
				cp[j] = grade;
			}
		}
		for(int k=0; k < numberOfStudents; k++) {
			std::cout << students[k].id << " " << students[k].name << " ";
			for(int z=0; z < numberOfStudents2; z++) {
				if(students[k].id == rawScores[z].id) {
					bool printed = false;
					for(int j=0; j < 4; j++) {
						if(rawScores[z].cumalitive >= cp[j]) {
							if(j==0) {
								if(students[k].gradeOption == "G") {
									std::cout << "A" << std::endl;
								}
								else {
									std::cout << "P" << std::endl;
								}
								printed = true;
								break;
							}
							else if(j==1) {
								if(students[k].gradeOption == "G") {
									std::cout << "B" << std::endl;
								}
								else {
									std::cout << "P" << std::endl;
								}
								printed = true;
								break;
							}
							else if(j==2) {
								if(students[k].gradeOption == "G") {
									std::cout << "C" << std::endl;
								}
								else {
									std::cout << "P" << std::endl;
								}
								printed = true;
								break;
							}
							else if(j==3) {
								if(students[k].gradeOption == "G") {
									std::cout << "D" << std::endl;
								}
								else {
									std::cout << "P" << std::endl;
								}
								printed = true;
								break;
							}
						}
					}
					if(printed == false) {
						if(students[k].gradeOption == "G") {
							std::cout << "F" << std::endl;
						}
						else {
							std::cout << "NP" << std::endl;
						}
						break;
					}
				}
			}
		}
		delete[] cp;
	}
}