//
//  main.cpp
//  HW1
//
//  Created by Time Thief on 1/23/23.
//

#include "Set.h"
#include "CardSet.h"
   #include <iostream>
   #include <cassert>
   using namespace std;

   int main()
   {
       CardSet cards;
       assert(cards.size()==0);
       cards.add(45678);
       assert(cards.add(45678)==false);
       assert(cards.add(12345)==true);
       assert(cards.size()==2);
       cards.add(23456);
       cards.add(34567);
       assert(cards.size()==4);
       cards.print();
       cout<<"success"<<endl;
   }


