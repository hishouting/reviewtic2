
#include <cstddef>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	char* fname = "7.1213.cpp";
	ifstream in(fname);
	vector<string> vstrings;
	deque<string> dstrings;
	string line;
	clock_t ticks = clock();
	while(getline(in, line))
		vstrings.push_back(line);
	ticks = clock() - ticks;
	cout << "Read into vector: " << ticks << endl;
	ifstream in2(fname);
	ticks = clock();
	while(getline(in2, line))
		dstrings.push_back(line);
	ticks = clock() - ticks;
	cout << "Read into deque: " << ticks << endl;
	ticks = clock();
	for(size_t i = 0; i < vstrings.size(); i++){
		ostringstream ss;
		ss << i;
		vstrings[i] = ss.str() + ": " + vstrings[i];
	}
	ticks = clock() - ticks;
	cout << "Indexing vector: " << ticks << endl;
	ticks = clock();
	for(size_t j = 0; j < dstrings.size(); j++){
		ostringstream ss;
		ss << j;
		dstrings[j] = ss.str() + ": " + dstrings[j];
	}
	ticks = clock() - ticks;
	cout << "Indexing deque: " << ticks << endl;
	ofstream tmp1("tmp1.tmp"), tmp2("tmp2.tmp");
	ticks = clock();
	copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(tmp1, "\n"));
	ticks = clock() - ticks;
	cout << "Iterating vector: " << ticks << endl;
	ticks = clock();
	copy(dstrings.begin(), dstrings.end(), ostream_iterator<string>(tmp2, "\n"));
	ticks = clock() - ticks;
	cout << "Iterating deque: " << ticks << endl;
}

// #include <algorithm>
// #include <iostream>
// #include <iterator>
// #include <vector>
// #include "Noisy.h"
// using namespace std;

// int main(){
// 	vector<Noisy> v;
// 	v.reserve(11);
// 	cout << "11 spaces have been reserved" << endl;
// 	generate_n(back_inserter(v), 10, NoisyGen());
// 	ostream_iterator<Noisy> out(cout, " ");
// 	cout << endl;
// 	copy(v.begin(), v.end(), out);
// 	cout << "Inserting an element:" << endl;
// 	vector<Noisy>::iterator it = v.begin() + v.size()/2;
// 	v.insert(it, Noisy());
// 	cout << endl;
// 	copy(v.begin(), v.end(), out);
// 	cout << "\nErasing an element:" << endl;
// 	it = v.begin() + v.size()/2;
// 	v.erase(it);
// 	cout << endl;
// 	it = v.begin() + v.size()/2;
// 	cout << endl;
// }

// #include <iterator>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
// 	vector<int> vi(10, 0);
// 	ostream_iterator<int> out(cout, " ");
// 	vector<int>::iterator i = vi.begin();
// 	*i = 47;
// 	copy(vi.begin(), vi.end(), out);
// 	cout << endl;
// 	vi.resize(vi.capacity() + 1);
// 	*i = 48;
// 	copy(vi.begin(), vi.end(), out);
// }

// #include <cstdlib>
// #include <iostream>
// #include <vector>
// #include <vector>
// #include "Noisy.h"
// using namespace std;

// int main(){
// 	int SIZE = 10;
// 	vector<Noisy> vn;
// 	Noisy n;
// 	for (int i = 0; i < SIZE; i++){
// 		vn.push_back(n);
// 	}
// 	cout << "\n cleaning up " << endl;
// }

// #include <iostream>
// #include <iterator>
// #include <algorithm>
// #include <memory>
// #include "Noisy.h"
// using namespace std;

// int main(){
// 	const int QUANTITY = 10;
// 	Noisy* np = reinterpret_cast<Noisy*>(new char[QUANTITY * sizeof(Noisy)]);
// 	raw_storage_iterator<Noisy*, Noisy> rsi(np);
// 	for(int i = 0; i < QUANTITY; i++)
// 		*rsi++ = Noisy();
// 	cout << endl;
// 	copy(np, np+QUANTITY, ostream_iterator<Noisy>(cout, " "));
// 	cout << endl;
// 	for(int j = 0; j < QUANTITY; j++)
// 		(&np[j])->~Noisy();
// 	delete reinterpret_cast<char*>(np);
// }

// #include <deque>
// #include <iostream>
// #include <list>
// #include <vector>
// using namespace std;

// template<typename Container>
// void print(Container& c, char* title = ""){
// 	cout << title << ':' << endl;
// 	if(c.empty()){
// 		cout << "(empty)" << endl;
// 		return;
// 	}
// 	typename Container::iterator it;
// 	for(it = c.begin(); it != c.end(); it++)
// 		cout << *it << " ";
// 	cout << endl;
// 	cout << "size() "      << c.size()
// 		 << " max_size() " << c.max_size()
// 		 << " front() "    << c.front()
// 		 << " back() "     << c.back()
// 		 << endl;
// }

// template<typename ContainerOfInt>
// void basicOps(char* s){
// 	cout << "---" << s << "---" << endl;
// 	typedef ContainerOfInt Ci;
// 	Ci c;
// 	print(c, "c after default constructor");
// 	Ci c2(10, 1);
// 	print(c2, "c2 after constructor(10, 1)");
// 	int ia[] = {1,3,5,7,9};
// 	const int IASZ = sizeof(ia)/sizeof(*ia);
// 	Ci c3(ia, ia+IASZ);
// 	print(c3, "c3 after constructor(iter, iter)");
// 	Ci c4(c2);
// 	print(c4, "c4 after copy-constructor(c2)");
// 	c = c2;
// 	print(c, "c after operator=c2");
// 	c.assign(10, 2);
// 	print(c, "c after assign(10, 2)");
// 	c.assign(ia, ia+IASZ);
// 	print(c, "c after assign(iter, iter)");
// 	cout << "c using reverse iterators:" << endl;
// 	typename Ci::reverse_iterator rit = c.rbegin();
// 	while(rit != c.rend())
// 		cout << *rit++ << " ";
// 	cout << endl;
// 	c.resize(4);
// 	print(c, "c after resize(4)");
// 	c.push_back(47);
// 	print(c, "c after push_back(47)");
// 	c.pop_back();
// 	print(c, "c after pop_back()");
// 	typename Ci::iterator it = c.begin();
// 	++it; ++it;
// 	c.insert(it, 74);
//     print(c, "c after insert(it, 74)");
//     it = c.begin();
//     ++it;
//     c.insert(it, 3, 96);
//     print(c, "c after insert(it, 3, 96)");
//     it = c.begin();
//     ++it;
//     c.insert(it, c3.begin(), c3.end());
//     print(c, "c after insert(it, c3.begin(), c3.end())");
//     it = c.begin();
//     ++it;
//     c.erase(it);
//     print(c, "c after erase(it)");
//     typename Ci::iterator it2 = it = c.begin();
//     ++it;
//     ++it2; ++it2; ++it2; ++it2; ++it2;
//     c.erase(it, it2);
//     print(c, "c after erase(it, it2)");
//     c.swap(c2);
//     print(c, "c after swap(c2)");
//     c.clear();
//     print(c, "c after clear()");    
// }

// int main(){
// 	basicOps<vector<int> >("vector");
// 	basicOps<deque<int> >("deque");
// 	basicOps<list<int> >("list");
// }

// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <iterator>
// using namespace std;

// int main(){
// 	ifstream in("FileEditor.h");
// 	istreambuf_iterator<char> isb(in), end;
// 	ostreambuf_iterator<char> osb(cout);
// 	while(isb != end)
// 		*osb++ = *isb++;
// 	cout << endl;
// 	ifstream in2("FileEditor.cpp");
// 	istream_iterator<char> is(in2), end2;
// 	ostream_iterator<char> os(cout);
// 	while(is != end2)
// 		*os++ = *is++;
// 	cout << endl;
// }

// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include <string>
// #include <vector>
// using namespace std;

// int main(){
// 	ifstream in("FileEditor.h");
// 	istream_iterator<string> begin(in), end;
// 	ostream_iterator<string> out(cout, "\n");
// 	vector<string> vs;
// 	copy(begin, end, back_inserter(vs));
// 	copy(vs.begin(), vs.end(), out);
// 	*out++ = vs[0];
// 	*out++ = "That's all, folks!";
// }

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <list>
// #include <iterator>
// using namespace std;

// int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 };

// template<class Cont>
// void frontInsertion(Cont& ci){
// 	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type), front_inserter(ci));
// 	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
// 	cout << endl;
// }

// template<class Cont>
// void backInsertion(Cont& ci){
// 	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type), back_inserter(ci));
// 	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
// 	cout << endl;
// }

// template<class Cont>
// void midInsertion(Cont& ci){
// 	typename Cont::iterator it = ci.begin();
// 	++it; ++it; ++it;
// 	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type)*2, inserter(ci, it));
// 	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
// 	cout << endl;
// }

// int main(){
// 	deque<int> di;
// 	list<int> li;
// 	vector<int> vi;

// 	frontInsertion(di);
// 	frontInsertion(li);
// 	di.clear();
// 	li.clear();
// 	backInsertion(vi);
// 	backInsertion(di);
// 	backInsertion(li);
// 	midInsertion(vi);
// 	midInsertion(di);
// 	midInsertion(li);
// }


// #include <fstream>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main(){
// 	ifstream in("FileEditor.cpp");
// 	string line;
// 	vector<string> lines;
// 	while(getline(in, line))
// 		lines.push_back(line);
// 	for (vector<string>::reverse_iterator r = lines.rbegin(); r != lines.rend(); ++r){
// 		cout << *r << endl;
// 	}
// }

// #include <iostream>
// #include <vector>
// #include <iterator>
// using namespace std;

// template<class Cont, class PtrMemFun>
// void apply(Cont& c, PtrMemFun f){
// 	typename Cont::iterator it = c.begin();
// 	while(it != c.end()){
// 		((*it).*f)();
// 		++it;
// 	}
// }

// class Z{
// 	int i;
// public:
// 	Z(int ii):i(ii){}
// 	void g(){++i;}
// 	friend ostream& operator<<(ostream& os, const Z& z){
// 		return os << z.i;
// 	}
// };

// int main(){
// 	ostream_iterator<Z> out(cout, " ");
// 	vector<Z> vz;
// 	for (int i = 0; i < 10; i++){
// 		vz.push_back(Z(i));
// 		copy(vz.begin(), vz.end(), out);
// 		cout << endl;
// 		apply(vz, &Z::g);
// 		// copy(vz.begin(), vz.end(), out);
// 	}
// }

// #include <sstream>
// #include "FileEditor.h"
// using namespace std;
// int main(){
// 	FileEditor file;
// 	file.open("FileEditor.cpp");
// 	int i = 1;
// 	FileEditor::iterator w = file.begin();
// 	while(w != file.end()){
// 		ostringstream ss;
// 		ss << i++;
// 		*w = ss.str() + ": " + *w;
// 		++w;
// 	}
// 	file.write();
// }

// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include <sstream>
// #include <string>
// #include <vector>
// using namespace std;

// int main(){
// 	const char* fname = "7.1213.cpp";
// 	ifstream in(fname);
//     vector<string> strings;
//     string line;
//     while(getline(in, line))
//     	strings.push_back(line);
//     int i = 1;
//     vector<string>::iterator w;
//     for ( w = strings.begin(); w != strings.end(); ++w){
//     	ostringstream ss;
//     	ss << i++;
//     	*w = ss.str() + ": " + *w;
//     }
//     copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));

// }

// #include <vector>
// #include <iostream>
// using namespace std;

// class Shape{
// public:
// 	virtual void draw() = 0;
// 	virtual ~Shape(){};
// };

// class Circle : public Shape{
// public:
// 	void draw(){ cout << "Circle::draw" << endl; }
// 	~Circle(){ cout << "~Circle" << endl; }
// };

// class Triangle : public Shape{
// public:
// 	void draw(){ cout << "Triangle::draw" << endl; }
// 	~Triangle(){ cout << "~Triangle" << endl; }
// };

// class Square : public Shape{
// public:
// 	void draw(){ cout << "Square::draw" << endl; }
// 	~Square(){ cout << "~Square" << endl; }
// };

// int main(){
// 	typedef std::vector<Shape*> Container;
// 	typedef Container::iterator Iter;
// 	Container shapes;
// 	shapes.push_back(new Circle);
// 	shapes.push_back(new Square);
// 	shapes.push_back(new Triangle);
// 	for (Iter i = shapes.begin(); i != shapes.end(); i++){
// 		(*i)->draw();
// 	}
// 	for (Iter j = shapes.begin(); j != shapes.end(); ++j){
// 		delete *j;
// 	}
// }

// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include <set>
// #include <string>
// #include "../require.h"
// using namespace std;

// void wordSet(const char* fileName){
// 	ifstream source(fileName);
// 	assure(source, fileName);
// 	string word;
// 	set<string> words;
// 	while(source >> word)
// 		words.insert(word);
// 	copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
// 	cout << "number of unique words: " << words.size() << endl;
// }

// int main(){
// 	wordSet("7.1213.cpp");
// }

// #include <set>
// #include <iostream>
// using namespace std;

// int main(){
// 	set<int> intset;
// 	for(int i = 0; i < 25; i++)
// 		for(int j = 0; j < 10; j++)
// 			intset.insert(j);
// 	cout << intset.size() << endl;
// }