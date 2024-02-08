
  // Student grading system

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    double grade;
};

int main() {
    vector<Student> studentVec;
    int numStudents;

    cout << "\nEnter the total number of students: ";
    cin >> numStudents;

    // Input the student names and their corresponding grades.
    for (int i = 0; i < numStudents; ++i) {
        Student stu;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> stu.name;
        cout << "Enter the grade of student " << i + 1 << ": ";
        cin >> stu.grade;
        studentVec.push_back(stu);
    }

    // Calculate the average grade
    double sumGrades = 0.0;
    for (Student student : studentVec) {
        sumGrades += student.grade;
    }
    double averageGrade = sumGrades / numStudents;

    // Find highest and lowest grades
    double highestGrade = studentVec[0].grade;
    double lowestGrade = studentVec[0].grade;
    for (Student student : studentVec) {
        highestGrade = max(highestGrade, student.grade);
        lowestGrade = min(lowestGrade, student.grade);
    }

    // Display results
    cout << "\nStudent Grades Summary:\n";
    for (Student student : studentVec) {
        cout << student.name << ": " << student.grade << endl;
    }

    cout << "\nAverage Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}