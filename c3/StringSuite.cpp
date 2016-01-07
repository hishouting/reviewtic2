#include <iostream>
#include "../TestSuite/Suite.h"
#include "StringStorage.h"
#include "Sieve.h"
#include "TrimTest.h"
using namespace std;
using namespace TestSuite;

int main(){
	Suite suite("String Tests");
	suite.addTest(new StringStorageTest);
	suite.addTest(new SieveTest);
	suite.run();
	long nFail = suite.report();
	suite.free();
	return nFail;
}