#ifndef STRINGSTORAGE_H
#define STRINGSTORAGE_H 
#include <iostream>
#include <string>
#include "../TestSuite/Test.h"
using std::cout;
using std::endl;
using std::string;

class StringStorageTest : public TestSuite::Test{
public:
	void run(){
		string s1("12345");
		string s2 = s1;
		test_(s1 == s2);
		s1[0] = '6';
		cout << "s1 = " << s1 << endl;
		cout << "s2 = " << s2 << endl;
	    test_(s1 != s2);
	}	
};
#endif