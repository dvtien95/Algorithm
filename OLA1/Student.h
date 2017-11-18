#ifndef Student_H
#define Student_H

#include <string>

using namespace std;

struct ScoreType
{
	string id;
	int CLA, OLA, quiz, homework, exam, bonus;
	
};

const int MAX_NUM = 25;
typedef ScoreType ItemType;

class Student
{
public:
	Student();
	
	~Student();
	
	void Insert(ItemType item);
	
	void Reset();
	
	void Display() const;
	
	void SearchStudent();
	
private:
	int length;
	ItemType a_students[MAX_NUM];
	int currentPos;
	
};

#endif