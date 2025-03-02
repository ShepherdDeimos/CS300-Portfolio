//============================================================================
// Name        : Final.cpp
// Author      : Stephen Zawatski
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Function to load course data from a file into a map
void loadCourses(map<string, Course>& courses) {
    string fileName;
    cout << "Enter the name of the course data file: ";
    cin >> fileName;
    ifstream file(fileName);

    if (!file) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNum, courseTitle, prereq;
        getline(ss, courseNum, ',');
        getline(ss, courseTitle, ',');
        Course course;
        course.courseNumber = courseNum;
        course.courseTitle = courseTitle;

        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }
        courses[courseNum] = course;
    }
    file.close();
    cout << "Courses successfully loaded from " << fileName << endl;
}

// Function to print all courses in alphanumeric order
void printCourseList(const map<string, Course>& courses) {
    cout << "\nCourse List:" << endl;
    for (const auto& pair : courses) {
        cout << pair.second.courseNumber << " - " << pair.second.courseTitle << endl;
    }
}

// Function to print a specific course's information
void printCourseInfo(const map<string, Course>& courses) {
    string courseNum;
    cout << "Enter course number: ";
    cin >> courseNum;

    auto it = courses.find(courseNum);
    if (it != courses.end()) {
        cout << "\nCourse: " << it->second.courseNumber << " - " << it->second.courseTitle << endl;
        cout << "Prerequisites: ";
        if (it->second.prerequisites.empty()) {
            cout << "None";
        }
        else {
            for (const auto& prereq : it->second.prerequisites) {
                cout << prereq << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Error: Course not found." << endl;
    }
}

// Function to display the menu and get user input
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Load course data" << endl;
    cout << "2. Print course list" << endl;
    cout << "3. Print course information" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    map<string, Course> courses;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            loadCourses(courses);
            break;
        case 2:
            printCourseList(courses);
            break;
        case 3:
            printCourseInfo(courses);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}
