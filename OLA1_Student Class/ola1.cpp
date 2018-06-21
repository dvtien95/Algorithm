#include "Student.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>

using namespace std;

void BuildStudentFile(ifstream & myIn, int & size, Student & studentFile, ScoreType & m_students);
void MenuOptions();

int main()
{
	int size = 0;
	ScoreType m_students;
	Student studentFile;
	
	ifstream myIn;
	myIn.open("point.dat");
	assert(myIn);
	
	BuildStudentFile(myIn,size,studentFile,m_students);
	
	MenuOptions();
	
	int choice = 0;
	while (choice != 3){
		cout << "Your selection is: ";
		cin >> choice;
		
		if (choice == 1)
			studentFile.Display();
		if (choice == 2)
			studentFile.SearchStudent();
	}
	
	myIn.close();
	
	return 0;
}

void BuildStudentFile(ifstream & myIn, int & size, Student & studentFile, ScoreType & m_students){
	myIn.ignore(100, '\n');
	while ((myIn >> m_students.id) && (size < MAX_NUM)){
		myIn >> m_students.CLA;
		myIn >> m_students.OLA;
		myIn >> m_students.quiz;
		myIn >> m_students.homework;
		myIn >> m_students.exam;
		myIn >> m_students.bonus;
		
		myIn.ignore(100, '\n');
		
		studentFile.Insert(m_students);
		size ++;
	}
}

void MenuOptions(){
	cout << "Select one of the options below: " << endl;
	cout << "	1. Display information of ALL students in the class " << endl;
	cout << "	2. Display information of a specified students ID " << endl;
	cout << "	3. Exit " << endl;
	cout << endl;
}