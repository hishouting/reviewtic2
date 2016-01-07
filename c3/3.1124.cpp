
#include <cassert>
#include <iostream>
#include "iwchar_traits.h"
using namespace std;

int main(){
	iwstring first = L"tHis";
	iwstring second = L"ThIs";
	wcout << first << endl;
	wcout << second << endl;
	assert(first.compare(second) == 0);
	assert(first.find('h') == 1);
}

// #include <iostream>
// #include <string>
// #include <exception>
// using namespace std;

// int main(){
// 	bool r;
// 	int i; 
// 	string s2("That"), s1("This");
// 	r = s2.compare("That");
// 	i = s2.compare("That");
// 	// if(r) cout << "..." << endl;
// 	cout << i << endl;
// 	i = s2.compare(s1);
// 	cout << i << endl;
// 	i = s1.compare(s2);
// 	cout << i << endl;
// 	// s2 = s2.substr(0, 2);
// 	i = s2.compare(0, 2, s1, 0, 2);
// 	cout << i << endl;
// 	cout << endl << s1[1] << endl << s1.at(1) << endl;
// 	try{
// 		// cout << s1[5] << endl;
// 		// s1.at(5);
// 	}catch(exception& e){
// 		cerr << e.what() << endl;
// 	}
// 	// if("That" == s2)
// 	// 	cout << "m" << endl;
// 	// if(s1 != s2.c_str())
// 	// 	cout << "n" << endl;
// }

// #include <algorithm>
// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
// 	string s = "this";
// 	string ss = " is ...";
// 	string sss = ss[4] + s + ss;
// 	cout << sss << endl;
// 	// string s("aaaxaaaxaaaxaaaxxxaaxxaaxxxxxaa");
// 	// cout << s << endl;
// 	// replace(s.begin(), s.end(), 'x', 'o');
// 	// cout << s << endl;
// }

// #include <iostream>
// #include <string>
// #include "ReplaceAll.h"
// using namespace std;

// int main(){
// 	string t = "a man, a plan, a canal, Panama";
// 	// replaceAll(t, "an", "xxx");
// 	cout << t << endl;
// 	t.replace(2, 3, "ddddd");
// 	cout << t << endl;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
// 	string b("I saw...");
// 	string r(" you.");
// 	cout << b << endl;
// 	b.replace(b.size() - 3, r.size(), r);
// 	cout << b << endl;
// }

// #include <iostream>
// #include <cstddef>
// #include <string>
// using namespace std;

// void replaceChars(string& modifyMe, const string& findMe, const string& newChars){
// 	size_t i = modifyMe.find(findMe, 0);
// 	if(i != string::npos)
// 		modifyMe.replace(i, findMe.size(), newChars);
// }

// int main(){
//     string b = "I thought i saw...";
//     string replacement = "i";
//     string findMe = "I";
//     cout << b << endl;
//     replaceChars(b, findMe, replacement);
//     cout << b << endl;
// }

// #include <cassert>
// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
// 	string s("A piece of text");
// 	string tag("$tag$");
// 	s.insert(8, tag + ' ');
// 	assert(s == "A piece $tag$ of text");
// 	cout << s << endl;
//     int start = s.find(tag);
//     cout << start << endl;
//     s.replace(start, tag.size(), "hello there");
//     cout << s << endl;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
// 	string s("I saw Elvis in a UFO");
// 	cout << s << endl;
// 	cout << "Size = " << s.size() << endl;
// 	cout << "capacity = " << s.capacity() << endl;
// 	s.insert(1, " thought I");
// 	cout << s << endl;
// 	cout << "Size = " << s.size() << endl;
// 	cout << "capacity = " << s.capacity() << endl;
// 	s.reserve(18);
// 	s.append(" ...I....................  ");
// 	s.resize(60);
// 	cout << s << endl;
// 	cout << "Size = " << s.size() << endl;
// 	cout << "capacity = " << s.capacity() << endl;
// }

// #include <string>
// #include <iostream>
// #include <cassert>
// using namespace std;

// int main(){
// 	string s("fknkklfe");
// 	string ss(s.begin(), s.end());
// 	assert(s == ss);
// 	string o(5, 'f');
// 	assert(o == "fffff");
// }

// #include <string>
// #include <iostream>
// using namespace std;

// int main(){
// 	string s1 = "What is the sound of one clam napping?";
// 	string s2("Anything worth doing is worth overdoing.");
// 	string s3("I saw Elvis in a UFO");
// 	string s4(s1, 0, 8);
// 	cout << s4 << endl;
// 	string s5(s2, 15, 6);
// 	cout << s5 << endl;
// 	string s6(s3, 6, 100);
// 	cout << s6 << endl;
// 	string q = s4 + "that" +s1.substr(20, 10) + s5 + "with" 
// 	              + s3.substr(5, 100) + s1.substr(37, 1);
// 	cout << q << endl;
// }

// #include <string>
// using namespace std;

// int main(){
// 	string imBlank;
// 	string heyMom("dd");
// 	string stdReply = "one"
// 	                  "two";
//     string useaAgain(stdReply);
// }

