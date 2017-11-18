#include "Student.h"
#include <iostream>
#include <string>


using namespace std;

string Student::getID() const{
	return m_id;
}

void Student::setID(string tmpID){
	m_id = tmpID;
}

void Student::changeScore(const ScoreType tmpType, const int tmpScore){
	m_score[tmpType] = tmpScore;
}

int Student::getScore(const ScoreType tmpType) const{
	return m_score[tmpType];
}