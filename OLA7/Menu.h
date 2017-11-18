// Tien Dinh - CSCI3110-001 - ola7: Graph implementation

#ifndef _MENU_H_
#define _MENU_H_

#include <string>

#include "Graph.h"

class Menu
{
	public:
        //default constructor
        //create a graph at the page 748 for debug purpose
        Menu();
		// This function  displays the main menu, reads
		// the command and executes it.
		void execution( void );

	private:

		// This function displays the main menu
		void displayMainMenu( void ) const;

		void addVertex( void );

		void addEdge( void );

        void removeVertex( void );

        void removeEdge( void );

        void DFS( void );

        void BFS( void );

        void shortestPath( void );

        void display( void ) const;

	private:
		Graph       m_graph; // The inventory associated with the menu 
};
	
#endif
