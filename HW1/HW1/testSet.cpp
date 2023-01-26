//
//  main.cpp
//  HW1
//
//  Created by Time Thief on 1/23/23.
//

#include "Set.h"
   #include <iostream>
   #include <cassert>
#include <string>
   using namespace std;

   int main()
   {
       Set ss;
           ss.insert("lavash");
           ss.insert("roti");
           ss.insert("chapati");
           ss.insert("injera");
           ss.insert("roti");
           ss.insert("matzo");
           ss.insert("injera");
           assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
           ItemType x;
           ss.get(0, x);
           assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
           ss.get(4, x);
           assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
           ss.get(2, x);
           assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss
       Set ss1;
           ss1.insert("laobing");
           Set ss2;
           ss2.insert("matzo");
           ss2.insert("pita");
           ss1.swap(ss2);
           assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
                  ss2.size() == 1  &&  ss2.contains("laobing"));
       Set s;
               assert(s.empty());
               ItemType y = "arepa";
               assert( !s.get(42, y)  &&  y == "arepa"); // x unchanged by get failure
               s.insert("chapati");
               assert(s.size() == 1);
               assert(s.get(0, y)  &&  y == "chapati");
               
       Set sss;
                   assert(sss.insert("roti"));
                   assert(sss.insert("pita"));
                   assert(sss.size() == 2);
                   assert(sss.contains("pita"));
                   ItemType z = "laobing";
                   assert(sss.get(0, z)  &&  z == "pita");
                   assert(sss.get(1, z)  &&  z == "roti");
       cout << "Passed all tests" << endl;
   }


