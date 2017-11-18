#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

string GetGrade(int total){
	if (total > 100 && total < 0)
		return "Invalid";
	if (total >= 90)
		return "A";
	else if (total >= 80)
		return "B";
	else if (total >= 70)
		return "C";
	else if (total >= 60)
		return "D";
	else
		return "F";
}

Student::Student()
{
	length = 0;
	currentPos = 0;
}

Student::~Student()
{
	
}

void Student::Insert(ItemType item){
	a_students[length] = item;
	length ++;
}

void Student::Reset(){
	currentPos = 0;
}

void Student::Display() const{
	cout << right;
	cout <<setw(8)<<"ID"<<setw(6)<<"CLA"<<setw(6)<<"OLA"<<setw(7)<<"Quiz"<<setw(11)<<"Homework"<<setw(7)<<"Exam"<<setw(8)<<"Bonus"<<setw(8)<<"Total"<<setw(13)<<"FinalGrade"<<endl;
	for (int i=0; i<length; i++){
		int total = a_students[i].CLA + a_students[i].OLA + a_students[i].quiz + a_students[i].homework + a_students[i].exam + a_students[i].bonus;
		cout <<setw(8)<<a_students[i].id<<setw(6)<<a_students[i].CLA<<setw(6)<<a_students[i].OLA<<setw(7)<<a_students[i].quiz<<setw(11)<<a_students[i].homework<<setw(7)<<a_students[i].exam<<setw(8)<<a_students[i].bonus<<setw(8)<<total<<setw(13)<<GetGrade(total)<<endl;
	}
	cout << endl;
}

void Student::SearchStudent(){
	string tmpID;
	cout << "Enter student ID: ";
	cin.ignore(100, '\n');
	getline(cin, tmpID);
	
	int i=0;
	while ((a_students[i].id != tmpID) && (i < length)){
		i++;
	}
	if (i == length){
		cout << "Student not found! " << endl;
		cout << endl;
	}
	else{
		cout << right;
		cout <<setw(8)<<"ID"<<setw(6)<<"CLA"<<setw(6)<<"OLA"<<setw(7)<<"Quiz"<<setw(11)<<"Homework"<<setw(7)<<"Exam"<<setw(8)<<"Bonus"<<setw(8)<<"Total"<<setw(13)<<"FinalGrade"<<endl;
		int total = a_students[i].CLA + a_students[i].OLA + a_students[i].quiz + a_students[i].homework + a_students[i].exam + a_students[i].bonus;
		cout <<setw(8)<<a_students[i].id<<setw(6)<<a_students[i].CLA<<setw(6)<<a_students[i].OLA<<setw(7)<<a_students[i].quiz<<setw(11)<<a_students[i].homework<<setw(7)<<a_students[i].exam<<setw(8)<<a_students[i].bonus<<setw(8)<<total<<setw(13)<<GetGrade(total)<<endl;
		cout << endl;
	}
}