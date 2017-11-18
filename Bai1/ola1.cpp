#include "Roster.h"
#include "Student.h"
#include <iostream>
#include <string>

int main()
{
	string courseName;
	cout << "Enter course name: ";
	getline(cin,courseName);
	
	Roster r(courseName);
	
	string fileName;
	cout << "Enter fileName: ";
	getline(cin,fileName);
	r.readStudentRecord(fileName);
	
	for (int i=0; i < r.getStudentNum(); i++)
	{
		cout << r.getStudent(i).getID() << "\t";
		for (int j=0; j < Student::CATEGORY_NUM; j++)
			cout << r.getStudent(i).getScore((const Student::ScoreType)j) << '\t';
		cout << endl;
	}
}