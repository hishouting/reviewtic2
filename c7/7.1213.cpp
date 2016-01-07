
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 };

template<class Cont>
void frontInsertion(Cont& ci){
	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type), front_inserter(ci));
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << endl;
}

template<class Cont>
void backInsertion(Cont& ci){
	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type), back_inserter(ci));
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << endl;
}

template<class Cont>
void midInsertion(Cont& ci){
	typename Cont::iterator it = ci.begin();
	++it; ++it; ++it;
	copy(a, a+sizeof(a)/sizeof(typename Cont::value_type)*2, inserter(ci, it));
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << endl;
}

int main(){
	deque<int> di;
	list<int> li;
	vector<int> vi;

	frontInsertion(di);
	frontInsertion(li);
	di.clear();
	li.clear();
	backInsertion(vi);
	backInsertion(di);
	backInsertion(li);
	midInsertion(vi);
	midInsertion(di);
	midInsertion(li);
}


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