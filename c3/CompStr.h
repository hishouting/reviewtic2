#ifndef COMPSTR_H
#define COMPSTR_H 
#include <string>
#include "../TestSuite/Test.h"
using std::string;

class CompStrTest : public TestSuite::Test{
public:
	void run(){
		string s1("This");
		string s2("That");
		test_(s1 == s2);
		test_(s1 < s2);
		test_(s1 > s2);
	}
};
#endif // COMPSTR_H