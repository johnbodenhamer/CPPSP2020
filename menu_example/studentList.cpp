//****************************************************************************************************
//
//		File:					pal.cpp
//
//		Student:				John Bodenhamer
//
//		Assignment:	 			Program  # 10
//
//		Course Name:			Data Structures   I
//
//		Course Number:			COSC 3050 - 10
//
//		Due:					Feb 24, 2020
//
//	    This program uses a stack to evaluate expressions read in from a file in
//      reverse polish notation.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "Student.h"
#include "DLList.h"

char getChoice();
void process(DLList<Student> &);
void buildList(DLList<Student> &);
void displayStudents(DLList<Student> &);
void displayStudentRev(DLList<Student> &);
void countStudents(DLList<Student> &);
void addNewStudent(DLList<Student> &);
void removeStudent(DLList<Student> &);
void findStudent(DLList<Student> &);

int main() {
   DLList<Student> studentList;

   buildList(studentList);
   process(studentList);
    return 0;
}

void buildList(DLList<Student> & studentList)
{
    Student student;
    ifstream studentData;

    studentData.open("studentFile.txt");

    while (studentData >> student.id)
    {
        studentData.ignore();
        studentData.getline(student.name, 50);
        studentData.getline(student.citystate, 50);
        studentData >> student.phone
                    >> student.gender
                    >> student.year
                    >> student.credits
                    >> student.gpa
                    >> student.major;

        studentList.insert(student);
    }

    studentData.close();
}

void process(DLList<Student> & studentList)
{
    char choice;

    do
    {
        choice = getChoice();

        switch (choice)
        {
            case 'A' : addNewStudent(studentList);
                break;
            case 'F' : findStudent(studentList);
                break;
            case 'R' : removeStudent(studentList);
                break;
            case 'C' : countStudents(studentList);
                break;
            case 'D' : displayStudents(studentList);
                break;
            case 'V' : displayStudentRev(studentList);
                break;
            case 'Q' : break;
        }
    }
    while (choice != 'Q');
}

char getChoice()
{
    char choice;
    bool valid;

    cout << "======== Menu ========\n"
         << " A:   Add a new Student \n"
         << " F:   Find a Student Record \n"
         << " R:   Remove a Student \n"
         << " C:   Get Number of Students \n"
         << " D:   Display all Students \n"
         << " V:   Display all Students in Reverse \n"
         << " Q: Quit       \n\n";

    do
    {
        cin >> choice;
        choice = toupper(choice);

        switch(choice)
        {
            case 'A':
            case 'F':
            case 'R':
            case 'C':
            case 'D':
            case 'V':
            case 'Q': valid = true;
                break;
            default : valid = false;
                cout << "\aInvalid choice\n"
                << "Please try again: ";
                break;

        }
    }
    while (!valid);

    return choice;
}

void displayStudents(DLList<Student> & studentList)
{
    cout << "\tSTUDENT LIST" << endl;
    for (int i = 0; i < 51; i++)
    {
        cout << '=';
    }

    cout << "\nID\t\t\tNAME\t\t\t\t\tMAJOR\t\tGPA" << endl;
    for (int i = 0; i < 51; i++)
    {
        cout << '=';
    }

    cout << '\n';
    studentList.display();
    cout << endl;
}

void displayStudentRev(DLList<Student> & studentList)
{
    cout << "\tREVERSE STUDENT LIST" << endl;
    for (int i = 0; i < 51; i++)
    {
        cout << '=';
    }

    cout << "\nID\t\t\tNAME\t\t\t\t\tMAJOR\t\tGPA" << endl;
    for (int i = 0; i < 51; i++)
    {
        cout << '=';
    }

    cout << '\n';
    studentList.displayReverse();
    cout << endl;
}

void countStudents(DLList<Student> & studentList)
{
   cout <<  studentList.getNumValues() << endl;
}

void addNewStudent(DLList<Student> & studentList)
{
    Student student;

    cout << "Enter student details" << endl;

    cout << "ID:";
    cin >> student.id;
    cout << "NAME: ";
    cin >> student.name;
    cout << "CITY/STATE: ";
    cin >> student.citystate;
    cout << "GENDER: ";
    cin >> student.gender;
    cout << "YEAR: ";
    cin >> student.year;
    cout << "PHONE: ";
    cin >> student.phone;
    cout << "GPA: ";
    cin >> student.gpa;

    studentList.insert(student);
    cout << student << " added" << endl;
}

void removeStudent(DLList<Student> & studentList)
{
    Student student;

    cout << "Enter a Student Id to remove: ";
    cin >> student.id;

    studentList.remove(student);
    cout << student << " removed" << endl;
}

void findStudent(DLList<Student> & studentList)
{
    Student student;

    cout << "Enter a Student Id to retrieve that student's information: ";
    cin >> student.id;

    studentList.retrieve(student);
    cout << student << endl;
}