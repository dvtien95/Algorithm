// Book is a child of StoreItem and has its own private data: m_bookTitle, m_author, m_date
#include "StoreItem.h"
#include <string>

class Book : public StoreItem
{
public:
    //default constructor setting every thing to empty or 0
    Book( std::string bookTitle="", std::string author="", std::string m_date="",
        std::string barcode="", double price=0, int copy=0, int demand=0);

    std::string getTitle() const;

    std::string getDirector() const;

    Book* createFromString( const std::string info) override;

    void printItem() override;

private:
    std::string m_bookTitle;        // book title
    std::string m_author;     // book author
	std::string m_date;		// book publish date
};