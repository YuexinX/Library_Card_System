//
//  CardSet.cpp
//  HW1
//
//  Created by Time Thief on 1/24/23.
//

#include "newSet.h"
#include <iostream>

Set::Set(const int max_items)
{// Create an empty set that can hold at most max_item elements (i.e., one whose size() is 0).
    if(max_items<0)
    {
        std::cout<<"a set can't be negative!"<<std::endl;
        exit(9);
    }
    num_items=0;
    m_arrNum = max_items;
    m_arr = new ItemType[max_items];
}

Set::~Set()
{
    delete [] m_arr;
}

Set::Set(const Set& src)
{
    num_items = src.num_items;
    m_arrNum = src.m_arrNum;
    m_arr = new ItemType[m_arrNum];
    for(int i = 0; i<m_arrNum;i++)
    {
        m_arr[i] = src.m_arr[i];
    }
}

Set &Set::operator = (const Set &src)
{
    if(m_arr == src.m_arr)
        return *this;
    delete [] m_arr;
    m_arrNum = src.m_arrNum;
    num_items = src.num_items;
    m_arr = new ItemType[src.m_arrNum];
    for (int i = 0; i < m_arrNum; i++)
    {
        m_arr[i] = src.m_arr[i];
    }
    return *this;
}

bool Set::empty()const
{// Return true if the set is empty, otherwise false.
    return (num_items==0);
}

int Set::size() const
{
    return num_items;
}// Return the number of items in the set.

bool Set::insert(const ItemType& value)
{
    if(num_items == m_arrNum)
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
  // Insert value into the set if it is not already present.  Return
  // true if the value is actually inserted.  Leave the set unchanged
  // and return false if value is not inserted (perhaps because it
  // was already in the set or because the set has a fixed capacity and
  // is full).

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
    for(int i = 0; i<num_items; i++)
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
{ // Change the implementation of the swap function so that the number of statement executions when swapping two sets is the same no matter how many items are in the sets.
  // Exchange the contents of this set with the other one.
    Set temp = *this;
    *this = other;
    other = temp;
}


