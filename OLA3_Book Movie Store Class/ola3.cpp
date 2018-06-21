#include "StoreItem.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

void CommandDescription();

int main()
{
	CommandDescription();
	
	char choice = ' ';
	while (choice != 'Q' || choice != 'q')
	{
		cout << "Please enter your command <M, B, L, R, C, Q>: ";
		cin >> choice;
		
		if (choice == 'M' || choice == 'm')
		{
			cout << "Done " << endl;
		}
		if (choice == 'B' || choice == 'b')
		{
			cout << "Done " << endl;
		}
		if (choice == 'L' || choice == 'l')
		{
			cout << "Done " << endl;
		}
		if (choice == 'R' || choice == 'r')
		{
			cout << "Done " << endl;
		}
		if (choice == 'C' || choice == 'c')
		{
			cout << "Done " << endl;
		}
		if (choice == 'Q' || choice == 'q')
		{
			break;
		}
	}
	
	return 0;
}

void CommandDescription()
{
	cout << "			MiniMovie Store		" << endl;
	for (int i=0; i<40; i++)
		cout << "*";
	cout << endl;
	cout << "Command	Description" << endl;
	cout << "M			Inquire a movie by title" << endl;
	cout << "B			Inquire a book by author" << endl;
	cout << "L			List inventory" << endl;
	cout << "R			Return one movie" << endl;
	cout << "C			Check out" << endl;
	cout << "Q			Quit the main menu" << endl;
	for (int i=0; i<40; i++)
		cout << "*";
	cout << endl;
}