//
//  CardSet.cpp
//  HW1
//
//  Created by Time Thief on 1/24/23.
//

#include "CardSet.h"

CardSet::CardSet()
{
    
}// Create an empty card set.


bool CardSet::add(unsigned long cardNumber)
{
  // Add a card number to the CardSet.  Return true if and only if the
  // card number was actually added.
    return m_cards.insert(cardNumber);
}

int CardSet::size() const
{// Return the number of card numbers in the CardSet.
    return m_cards.size();
}

void CardSet::print() const
{
  // Write to cout every card number in the CardSet exactly once, one
  // per line.  Write no other text.
    for (int i = 0; i<m_cards.size(); i++)
    {
        unsigned long value;
        m_cards.get(i, value);
        std::cout<<value<<std::endl;
    }

}


