#include <iostream>
using namespace std;

struct Subject {
    string subjectName;
    int mark;
    char grade;
};

struct Student {
    string name;
    int age;
    int totalSubject;
    Subject subjects[5];
    float cpa;
};

char calcGrade(int mark) {
    if (mark >= 80) return 'A';
    else if (mark >= 70) return 'B';
    else if (mark >= 60) return 'C';
    else if (mark >= 50) return 'D';
    else return 'F';
}

float calcCPA(Student s) {
    float total = 0;
    for (int i = 0; i < s.totalSubject; i++) {
        total += s.subjects[i].mark;
    }
    return total / s.totalSubject;
}

int main() {
    Student students[10];
    int totalStudent;

    cout << "Enter number of students (max 10): ";
    cin >> totalStudent;

    for (int i = 0; i < totalStudent; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> students[i].name;
        cout << "Enter age: ";
        cin >> students[i].age;
        cout << "Enter number of subjects (max 5): ";
        cin >> students[i].totalSubject;

        for (int j = 0; j < students[i].totalSubject; j++) {
            cout << "\nSubject " << j + 1 << endl;
            cout << "Enter subject name: ";
            cin >> students[i].subjects[j].subjectName;
            cout << "Enter mark (0-100): ";
            cin >> students[i].subjects[j].mark;

            while (students[i].subjects[j].mark < 0 || students[i].subjects[j].mark > 100) {
                cout << "Invalid mark! Please enter again (0-100): ";
                cin >> students[i].subjects[j].mark;
            }

            students[i].subjects[j].grade = calcGrade(students[i].subjects[j].mark);
        }

        students[i].cpa = calcCPA(students[i]);
    }

    cout << "\nStudent's information\n";
    for (int i = 0; i < totalStudent; i++) {
        cout << "\nStudent " << i + 1 << ": " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "CPA: " << students[i].cpa << endl;
        cout << "Subjects:\n";

        for (int j = 0; j < students[i].totalSubject; j++) {
            cout << "  " << students[i].subjects[j].subjectName
                 << " - Mark: " << students[i].subjects[j].mark
                 << ", Grade: " << students[i].subjects[j].grade << endl;
        }
    }

    return 0;
}