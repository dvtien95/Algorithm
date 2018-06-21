// Implementation of abstract based class: StoreItem
#include "StoreItem.h"
#include <iostream>
#include <string>

//Get price
double StoreItem::getPrice( void ) const
{
	return m_price;
}

//Get number of copies in the store
int StoreItem::getCopy( void ) const
{
	return m_copy;
}

//Get number of copies to be ordered
int StoreItem::getDemand( void ) const
{
	return m_demand;
}

//Increase # of copies by 1
//precondition: m_copy >= 0
void StoreItem::increaseCopy( void )
{
	if (m_copy >= 0)
		m_copy += 1;
}

//Decrease # of copies by 1
//precondition: m_copy > 0
void StoreItem::decreaseCopy( void )
{
	if (m_copy > 0)
		m_copy -= 1;
}

//Increase # of copies to be ordered by 1
//precondition: m_copy == 0
void StoreItem::increaseDemand( void )
{
	if (m_copy == 0)
		m_demand += 1;
}

//Decrease # of copies to be ordered by 1
//precondition: m_demand > 0
void StoreItem::decreaseDemand( void )
{
	if (m_demand > 0)
		m_demand -=1;
}

//Compare two store items. Return true if they have the same barcode,
//otherwise false.
bool StoreItem::operator == (const StoreItem& rhs) const
{
	return m_barcode == rhs.m_barcode;
}

//Compare two store items by barcode
bool StoreItem::operator < (const StoreItem& rhs) const
{
	return m_barcode < rhs.m_barcode;
}
