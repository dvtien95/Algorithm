#include "Roster.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

Roster::Roster(string courseName)
{
	m_courseName = courseName;
	m_studentNum = 0;
}

void Roster::readStudentRecord(string fileName)
{
	ifstream myIn;
	myIn.open(fileName.c_str());
	assert(myIn);
	
	myIn.ignore(100, '\n');
	string tmpID;
	int tmpScore;
	while (getline(myIn,tmpID) && (m_studentNum < MAX_NUM)){
		m_students[m_studentNum].setID(tmpID);
		for (int i=0; i <= Student::CATEGORY_NUM; i++){
			myIn >> tmpScore;
			m_students[m_studentNum].changeScore((Student::ScoreType) i, tmpScore);
		}
		
		myIn.ignore(100, '\n');
		
		m_studentNum ++;
	}
}

int Roster::getStudentNum(){
	return m_studentNum;
}

Student Roster::getStudent(int i)
{
	if (i < m_studentNum)
		return m_students[i];
}