#ifndef TRIMTEST_H
#define TRIMTEST_H 
#include "Trim.h"
#include "../TestSuite/Test.h"

class TrimTest : public TestSuite::Test{
    enum { NTESTS = 11, };
    static std::string s[NTESTS];
public:
	void testTrim(){
		test_(trim(s[0]) == "abcdefghijklmnop");
		test_(trim(s[1]) == "abcdefghijklmnop");
		test_(trim(s[2]) == "a b c");
	}	
	void run(){
		testTrim();
	}
};
#endif // TRIMTEST_H