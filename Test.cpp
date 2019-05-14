//
//  main.cpp
//  iterable
//
//  Created by Jeme Jbareen on 5/12/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#include <iostream>
#include <string>
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.hpp"
using namespace std;
using namespace itertools;

template <typename Iterable>
string iterable_to_string(const Iterable &iterable)
{
    ostringstream ostr;
    for (decltype(*iterable.begin()) i : iterable)
        ostr << i << ",";
    return ostr.str();
}

int main(){
    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0){
        string Test1 = "";
        string Test2 = "";
        string Test3 = "";
        string Test4 = "";
        for (int i : range(5, 9))
            Test1.append(to_string(i));
        for (int i : range(-2, 6))
            Test2.append(to_string(i));
        for (char i : range('a', 'i'))
            Test3 += i;
        for (char i : range('m', 'w'))
            Test4 += i;
        testcase.setname("range")
        .CHECK_OUTPUT(Test1, "5678")
        .CHECK_OUTPUT(Test2, "-2-1012345")
        .CHECK_OUTPUT(Test3, "abcdefgh")
        .CHECK_OUTPUT(Test4, "mnopqrstuv");
        Test1 = "";
        Test2 = "";
        Test3 = "";
        Test4 = "";
        for (int i : chain(range(1, 8), range(10, 20)))
            Test1.append(to_string(i));
        for (double i : chain(range(1.2, 14.2), range(2.4, 8.4)))
            Test2.append(to_string(i) + " ");
        for (char i : chain(range('A', 'C'), string("WORLD")))
            Test3 += i;
        for (char i: chain(string("hello"), string("WORLD")))
            Test4 += i;
        testcase.setname("chain")
        .CHECK_OUTPUT(Test1, "123456710111213141516171819")
        .CHECK_OUTPUT(Test2, "1.200000 2.200000 3.200000 4.200000 5.200000 6.200000 7.200000 8.200000 9.200000 10.200000 11.200000 12.200000 13.200000 2.400000 3.400000 4.400000 5.400000 6.400000 7.400000 ")
        .CHECK_OUTPUT(Test3, "ABWORLD")
        .CHECK_OUTPUT(Test4, "helloWORLD");
        Test1 = "";
        Test2 = "";
        Test3 = "";
        Test4 = "";
        for (auto pair : zip(range(8, 13), string("world"))){
            Test1.append(pair);
            Test1.append(" ");
        }
        for (auto pair : zip(zip(range(1, 6), string("hello")), zip(string("world"), range(5, 10)))){
            Test2.append(pair);
            Test2.append(" ");
        }
        for (auto pair : zip(range(1, 3), string("ac"))){
            Test3.append(pair);
            Test3.append(" ");
        }
        for (auto pair : zip(range(4, 14), string("helloWORLD"))){
            Test4.append(pair);
            Test4.append(" ");
        }
        testcase.setname("zip")
        .CHECK_OUTPUT(Test1, "8,w 9,o 10,r 11,l 12,d ")
        .CHECK_OUTPUT(Test2, "1,h,w,5 2,e,o,6 3,l,r,7 4,l,l,8 5,o,d,9 ")
        .CHECK_OUTPUT(Test3, "1,a 2,c ")
        .CHECK_OUTPUT(Test4, "4,h 5,e 6,l 7,l 8,o 9,W 10,O 11,R 12,L 13,D ");
        Test1 = "";
        Test2 = "";
        Test3 = "";
        Test4 = "";
        for (auto pair : product(range(1, 3), string("itertools"))){
            Test1.append(pair);
            Test1.append(" ");
        }
        for (auto pair : product(range(1, 4), range(1,5))){
            Test2.append(pair);
            Test2.append(" ");
        }
        for (auto pair : product(range(1, 4), chain(range(1,3), range(5, 9)))){
            Test3.append(pair);
            Test3.append(" ");
        }
        for (auto pair : product(range(2.2,6.2), chain(range(1.1,5.1), range(5.1, 8.1)))){
            Test4.append(pair);
            Test4.append(" ");
        }
        testcase.setname("Product")
        .CHECK_OUTPUT(Test1, "1,i 1,t 1,e 1,r 1,t 1,o 1,o 1,l 1,s 2,i 2,t 2,e 2,r 2,t 2,o 2,o 2,l 2,s ")
        .CHECK_OUTPUT(Test2, "1,1 1,2 1,3 1,4 2,1 2,2 2,3 2,4 3,1 3,2 3,3 3,4 ")
        .CHECK_OUTPUT(Test3, "1,1 1,2 1,5 1,6 1,7 1,8 2,1 2,2 2,5 2,6 2,7 2,8 3,1 3,2 3,5 3,6 3,7 3,8 ")
        .CHECK_OUTPUT(Test4, "2.2,1.1 2.2,2.1 2.2,3.1 2.2,4.1 2.2,5.1 2.2,6.1 2.2,7.1 3.2,1.1 3.2,2.1 3.2,3.1 3.2,4.1 3.2,5.1 3.2,6.1 3.2,7.1 4.2,1.1 4.2,2.1 4.2,3.1 4.2,4.1 4.2,5.1 4.2,6.1 4.2,7.1 5.2,1.1 5.2,2.1 5.2,3.1 5.2,4.1 5.2,5.1 5.2,6.1 5.2,7.1 ");
        Test1 = "";
        Test2 = "";
        Test3 = "";
        Test4 = "";
        for (auto subset : powerset(range(1, 4)))
            Test1.append(to_string(subset) + " ");
        for (auto subset : powerset(chain(range('a', 'c'), range('m', 'o'))))
            Test2.append(to_string(subset) + " ");
        testcase.setname("Powerset")
        .CHECK_OUTPUT(Test1, "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3} ")
        .CHECK_OUTPUT(Test2, "{}{a}{b}{a,b}{m}{a,m}{b,m}{a,b,m}{y}{a,n}{b,n}{a,b,n}{m,n}{a,m,n}{b,m,n}{a,b,m,n} ");
        
        grade = testcase.grade();
    }
    else{
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}

