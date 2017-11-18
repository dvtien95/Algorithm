// Implementation of child class: Book
#include "Book.h"
#include <string>
#include <sstream>
#include <iostream>

std::string Book::getTitle() const
{
	return m_bookTitle;
}

std::string Book::getDirector() const
{
	return m_author;
}


Book* Book::createFromString( const std::string info)
{
	
}

// If item is a book, print like this
void Book::printItem()
{
	std::cout << "************ Book with barcode " << m_barcode << " ************" << std::endl;
	std::cout << "Book Title:	" << m_bookTitle << std::endl;
	std::cout << "Author:	" << m_author << std::endl;
	std::cout << "Publish Date:" << m_date << std::endl;
	std::cout << "Price:		" << m_price << std::endl;
	std::cout << "# of copy:	" << m_copy << std::endl;
	std::cout << "# of demand:	" << m_demand << std::endl;
	std::cout << std::endl;
}

