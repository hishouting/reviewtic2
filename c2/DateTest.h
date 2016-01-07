#ifndef DATETEST_H
#define DATETEST_H
#include "Date.h"
#include "../TestSuite/Test.h"

class DateTest : public TestSuite::Test{
    Date mybday;
    Date today;
public:
	DateTest() : mybday(1951, 10, 1){}
	void run(){
		testOps();
		testFunctions();
		testDuration();
	}
	void testOps(){
		test_(mybday < today);
		test_(mybday != today);
	}
	void testFunctions(){
		test_(mybday.getYear() == 1951);
	}
	void testDuration(){
		Date d2(2003, 7, 4);
		Date::Duration dur = duration(mybday, d2);
		test_(dur.years == 51);
		test_(dur.years == 50);
	}
};
#endif // DATETEST_H