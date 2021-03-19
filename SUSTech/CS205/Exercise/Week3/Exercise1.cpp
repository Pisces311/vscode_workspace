#include <iostream>
using namespace std;

struct Student {
    char first[25], last[25];
    char grade;
    int age;
} student;

int main() {
    cout << "What is your first name? ";
    cin.getline(student.first, 20);
    cout << "What is your last name? ";
    cin.getline(student.last, 20);
    cout << "What letter grade do you deserve? ";
    cin >> student.grade;
    cout << "What is your age? ";
    cin >> student.age;
    cout << "The information you entered is:" << endl;
    cout << "Name: " << student.first << ", " << student.last << endl;
    cout << "Grade: " << student.grade << endl;
    cout << "Age: " << student.age << endl;
    return 0;
}