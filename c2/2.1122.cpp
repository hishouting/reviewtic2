
// #include <iostream>
// using namespace std;

// #define TRACE(ARG) cout << #ARG << endl; ARG
// #define D(a) cout << #a "=[" << a << "]" << endl;

// int main(){
// 	int i = 0;
// 	TRACE(i);
// 	int j = 2;
// 	TRACE(i = j;)
// 	D(i)
// 	D(j)
// 	// TRACE(for(int k = 0, k < 3, k++))
// 	// TRACE(cout << k << endl;)
// }

// #include <iostream>
// #include <cassert>
// using namespace std;

// int main(){
// 	int i = 1;
// 	int j = 0;
// 	if(i == j){
// 		assert(i == j);
// 		cout << "i == j" << endl;
// 	}
// 	if(i != j){
// 		assert(i != j);
// 		cout << "i != j" << endl;
// 	}
// 	assert(i == j);
// 	cout << "i == j" << endl;
// }

// #include "DateTest.h"
// #include <iostream>
// using namespace std;

// int main(){
// 	DateTest test;
// 	test.run();
// 	return test.report();
// }

// #include <iostream>
// #include "Date.h"
// using namespace std;

// int nPass = 0, nFail = 0;
// void test(bool t){ if(t) nPass++; else nFail++; }

// int main(){
// 	Date mybday(1951, 10, 1);
//     Date today;
//     Date myevebday("19500930");

//  //    test(mybday < today);
//  //    test(mybday <= today);
//  //    test(mybday >= today);
//  //    test(mybday > today);
//  //    test(mybday != today);
//  //    test(mybday == today);
//  //    test(myevebday < mybday);
//  //    test(myevebday > mybday);
//  //    test(myevebday == mybday);
//  //    test(myevebday !=mybday);
    


// 	// test(mybday.getYear() == 1951);
// 	// test(mybday.getMonth() == 10);
// 	// test(mybday.getDay() == 1);
// 	// test(mybday.toString() == "1951101");
	
//     Date d2(2014,10,20);
//     Date::Duration dur = duration(today, d2);
//     test(dur.years == 1);
//     test(dur.months == 1);
//     test(dur.days == 2);


// 	cout << "Passed: " << nPass << ", Failed: " << nFail << endl;
// }

// #include <iostream>
// #include <fstream>
// #include "../require.h"
// using namespace std;

// #define TRACEON
// #include "../c3/Trace.h"

// int main(){
// 	ifstream f("2.1122.cpp");
// 	assure(f, "2.1122.cpp");
// 	cout << f.rdbuf();
// }

// #include <cstdlib>
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
// 	cout << "Think of a number between 1 and 100" << endl;
// 	cout << "I will make a guess;" << endl;
// 	cout << "tell me if i'm (H)igh or (L)ow" << endl; 
// 	int low = 1, high = 100;
// 	bool guessed = false;
// 	while(!guessed){
// 		if(low > high){
// 			cout << "You cheated! I quit" << endl;
// 			return EXIT_FAILURE;
// 		}
// 		int guess = (low + high) / 2;
// 		cout << "My guess is " << guess <<". ";
// 		cout << "(H)igh or (L)ow, or (E)qual? ";
// 		string response;
// 		cin >> response;
// 		switch(toupper(response[0])){
// 			case 'H':
// 			    high = guess - 1;
// 			    break;
// 			case 'L':
// 			    low = guess + 1;
// 			    break;
// 			case 'E':
// 			    guessed = true;
// 			    break;
// 			default:
// 			cout << "Invalid response" << endl;
// 			continue;
// 		}
// 	}
// 	cout << "I got it!" << endl;
// 	return EXIT_SUCCESS;
// }