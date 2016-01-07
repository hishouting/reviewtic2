#ifndef RPARSE_H
#define RPARSE_H 
#include <cstddef>
#include <string>
#include <vector>
#include "../TestSuite/Test.h"
using std::size_t;
using std::string;
using std::vector;

class RparseTest : public TestSuite::Test{
    vector<string> strings;
public:
	void parseForData(){
		string s("now.;sense;make;to;going;is;This");
		int last = s.size();
		size_t current = s.rfind(';');
		while(current != string::npos){
			++current;
			strings.push_back(s.substr(current, last - current));
			current -= 2;
			last = current + 1;
			current = s.rfind(';', current);
		}
		strings.push_back(s.substr(0, last));
	}	
	void testData(){
		test_(strings[0] == "This");
		test_(strings[6] == "now.");
        string sentence;
        for(size_t i = 0; i < strings.size() - 1; i++)
        	sentence += strings[i] += " ";
        sentence += strings[strings.size() - 1];
        test_(sentence == "This is going to make sense now.");
	}
	void run(){
		parseForData();
		testData();
	}
};
#endif // RPARSE_H