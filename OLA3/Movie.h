// Movie is a child of StoreItem and has its own private data: m_movieTitle, m_director
#include <string>
/* No methods are provided to modify movie information.
 * Movie information should be stable, whch means whenever
 * you get a movie object, you are not supposed to
 * change movie information such as title, and director.
 */
#include "StoreItem.h"

class Movie : public StoreItem
{
public:
    //default constructor setting every thing to empty or 0
    Movie( std::string movieTitle="", std::string director="",
        std::string barcode="", double price=0, int copy=0, int demand=0);

    std::string getTitle() const;

    std::string getDirector() const;

    Movie* createFromString( const std::string info) override;

    void printItem() override;

private:
    std::string m_movieTitle;        // movie title
    std::string m_director;     // movie directors
};
