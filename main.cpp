#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "course.hpp"

using namespace std;

//Function to convert string to enum type
Course::dayOfWeek convert(const string& str) {
    if (str == "M") {
        return Course::MON;
    } else if (str == "T") {
        return Course::TUE;
    } else if (str == "W") {
        return Course::WED;
    } else if (str == "R") {
        return Course::THUR;
    } else if (str == "F") {
        return Course::FRI;
    }
}

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule() {
    ifstream readFile;
    readFile.open("../courses.txt");

    string title;
    string newDay;
    Course::dayOfWeek day;
    unsigned int start_time;
    unsigned int finish_time;

    vector<Course> courses;

    while(readFile >> title >> newDay >> start_time >> finish_time) {

        Course newCourse(title, convert(newDay), start_time, finish_time);
        courses.push_back(newCourse);
    }

    sort(courses.begin(), courses.end());

    //Printing out conflicts
    for(int i = 0; i < courses.size(); i++) {
        for (int j = i + 1; j < courses.size(); j++) {
            if (courses[i] == courses[j]) {
                cout << "CONFLICT:" << endl;
                cout << courses[i] << endl;
                cout << courses[j] << endl;
            }
        }
    }

    cout << endl;

    //Printing out schedule
    for(int i = 0; i < courses.size(); i++){
        cout << courses[i] << endl;
    }
}

int main () {
    //TODO read from courses.txt
    //TODO store data in an STL container
    //TODO sort your STL container with the sort algorithm
    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
//    cout << "Find the TODOs in the code and implement them." << endl;
//    cout << "Add/modify any functions/code you need to complete your task." << endl;


    printSchedule();

    return 0;
}

