// Implementation of child class: Movie
#include "Movie.h"
#include <string>
#include <sstream>
#include <iostream>

std::string Movie::getTitle() const
{
	return m_movieTitle;
}

std::string Movie::getDirector() const
{
	return m_director;
}


Movie* Movie::createFromString( const std::string info)
{
	
}

// If item is a movie, print like this
void Movie::printItem()
{
	std::cout << "************ Movie with barcode " << m_barcode << " ************" << std::endl;
	std::cout << "Movie Title:	" << m_movieTitle << std::endl;
	std::cout << "Director:	" << m_director << std::endl;
	std::cout << "Price:		" << m_price << std::endl;
	std::cout << "# of copy:	" << m_copy << std::endl;
	std::cout << "# of demand:	" << m_demand << std::endl;
	std::cout << std::endl;
}