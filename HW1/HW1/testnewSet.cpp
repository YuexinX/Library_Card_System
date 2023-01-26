//
//  main.cpp
//  HW1
//
//  Created by Time Thief on 1/23/23.
//

#include "newSet.h"
   #include <iostream>
   #include <cassert>
   using namespace std;

   int main()
   {
       Set a(1000);   // a can hold at most 1000 distinct items
        Set b(5);      // b can hold at most 5 distinct items
        Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
        ItemType v[6] = {"a","b","c","d","e","f"};

        for (int k = 0; k < 5; k++)
            assert(b.insert(v[k]));

              // Failure if we try to insert a sixth distinct item into b
        assert(!b.insert(v[5]));

              // When two Sets' contents are swapped, their capacities are swapped
              // as well:
        a.swap(b);
        assert(!a.insert(v[5])  &&  b.insert(v[5]));
    
           Set ss;
               ss.insert("2222");
               ss.insert("1111");
               ss.insert("3333");
               ss.insert("4444");
               ss.insert("5555");
               ss.insert("2222");
               ss.insert("3333");
               assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
               ItemType x;
               ss.get(0, x);
               assert(x == "1111");  // "chapati" is greater than exactly 0 items in ss
               ss.get(4, x);
               assert(x == "5555");  // "roti" is greater than exactly 4 items in ss
               ss.get(2, x);
               assert(x == "3333");  // "lavash" is greater than exactly 2 items in ss
           Set ss1(10);
               ss1.insert("12345");
               Set ss2(5);
               ss2.insert("23456");
               ss2.insert("34567");
               ss1.swap(ss2);
               assert(ss1.size() == 2  &&  ss1.contains("23456")  &&  ss1.contains("34567")  &&
                      ss2.size() == 1  &&  ss2.contains("12345"));
           Set s;
                   assert(s.empty());
                   ItemType y = "1345";
                   assert( !s.get(42, y)  &&  y == "1345"); // x unchanged by get failure
                   s.insert("2333");
                   assert(s.size() == 1);
                   assert(s.get(0, y)  &&  y == "2333");
       assert(s.insert("5777"));
                   
           Set sss;
                       assert(sss.insert("1333"));
                       assert(sss.insert("1444"));
                       assert(sss.size() == 2);
                       assert(sss.contains("1333"));
       assert(sss.erase("1333"));
       assert(sss.size()==1);
                       ItemType z = "7777";
                       assert(sss.get(0, z)  &&  z == "1444");
                       assert(!sss.get(1, z)  &&  z == "1444");
       Set sc = sss;
       assert(sc.size()==1);
       assert(sc.contains("1444"));
       sc = s;
       assert(sc.size()==2);
       assert(sc.get(1,z) && z == "5777");
           cout << "Passed all tests" << endl;
   }


