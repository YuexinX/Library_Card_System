//
//  Set.cpp
//  HW1
//
//  Created by Time Thief on 1/23/23.
//

#include "Set.h"

Set::Set()
{
    num_items = 0;
}

bool Set::empty() const
{
    return (num_items == 0);
}

int Set::size() const
{
    return num_items;
}// Return the number of items in the set.

bool Set::insert(const ItemType& value)
{  // Insert value into the set if it is not already present.  Return
  // true if the value is actually inserted.  Leave the set unchanged
  // and return false if value is not inserted (perhaps because it
  // was already in the set or because the set has a fixed capacity and
  // is full).
    if(num_items == DEFAULT_MAX_ITEMS)
        return false;
    for (int i =0; i<num_items; i++)
    {
        if (m_arr[i] == value)
        {
            return false;
        }
    }
    m_arr[num_items] = value;
    num_items +=1;
    return true;
}

bool Set::erase(const ItemType& value)
{
  // Remove the value from the set if it is present.  Return true if the
  // value was removed; otherwise, leave the set unchanged and
  // return false.
    for(int i = 0; i<num_items; i++)
    {
        ItemType check;
        check = m_arr[i];
        if(check == value)
        {
            for(int j=i; j<num_items-1; j++)
            {
                m_arr[j]=m_arr[j+1];
            }
            num_items -= 1;
            return true;
        }
    }
    return false;
}
 
bool Set::contains(const ItemType& value) const
{
  // Return true if the value is in the set, otherwise false.
    for(int i=0; i<num_items; i++)
    {
        ItemType check = m_arr[i];
        if(check == value)
            return true;
    }
    return false;
}
 
bool Set::get(int i, ItemType& value)const
{
  // If 0 <= i < size(), copy into value the item in the set that is
  // strictly greater than exactly i items in the set and return true.
  // Otherwise, leave value unchanged and return false.
    if (i<0 || i>=num_items)
    {
        return false;
    }
    else
    {
        int largerThan;
        for(int k = 0; k<num_items; k++)
        {
            largerThan = 0;
            ItemType item = m_arr[k];
            for(int j = 0;j<num_items;j++)
            {
                ItemType compare = m_arr[j];
                if(item>compare)
                    largerThan++;
            }
            if(largerThan == i)
            {
                value = item;
                break;
            }
        }
        return true;
    }
}

void Set::swap(Set& other)
{
    Set temp = *this;
    *this = other;
    other = temp;
  
    
  // Exchange the contents of this set with the other one.
}



