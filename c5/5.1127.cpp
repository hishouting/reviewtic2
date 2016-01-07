
#include <iostream>
using namespace std;

template<bool> struct StaticCheck{
	StaticCheck(...);
};

template<> struct StaticCheck<false>{};

#define STATIC_CHECK(expr, msg){ \
        class Error_##msg {};\
        sizeof((StaticCheck<expr>(Error_##msg())));\
}\

template<class To, class From> To safe_cast(From from){
	STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConcersion);
	return reinterpret_cast<To>(from);
}

int main(){
	void* p = 0;
	int i = safe_cast<int>(p);
	cout << "int cast okay" << endl;
	// char c = safe_cast<char>(p);
}

// #define STATIC_ASSERT(x)\
//         do{ typedef int a[(x)?1:-1];} while(0)

// int main(){
// 	STATIC_ASSERT(sizeof(int) <= sizeof(long));
// 	STATIC_ASSERT(sizeof(double) <= sizeof(int));
// }

// #include <iostream>
// using namespace std;

// template<bool cond>struct Select{};

// template<> 
// class Select<true>{
//     static void statement1(){
//     	cout << "This is statement1 executing\n";
//     }
// public:
// 	static void f() {statement1();}	
// };

// template<> 
// class Select<false>{
//     static void statement2(){
//     	cout << "This is statement2 executing\n";
//     }
// public:
// 	static void f() {statement2();}	
// };

// template<bool cond> void execute(){
// 	Select<cond>::f();
// }

// int main(){
// 	execute<sizeof(int) == 4>();
// }

// #include <iostream>
// using namespace std;

// template<int n1, int n2> struct Max{
// 	enum{val = n1 < n2 ? n1 : n2};
// };

// int main(){
// 	cout << Max<20, 10>::val << endl;
// }

// #include <iostream>
// using namespace std;

// template<int n> inline int power(int m){
// 	return power<n-1>(m) * m;
// }

// template<> inline int power<1>(int m){
// 	return m;
// }

// template<> inline int power<0>(int m){
// 	return 1;
// }

// int main(){
// 	int m = 4;
// 	cout << power<3>(m) << endl;
// }

// #include <iostream>
// using namespace std;

// template<int n, template<int> class F>
// struct Accumulate{
// 	enum{ val = Accumulate<n-1, F>::val + F<n>::val };
// };

// template<template<int> class F>
// struct Accumulate<0, F>{
// 	enum{ val = F<0>::val };
// };

// template<int n> struct Identity{
// 	enum{val = n};
// };

// template<int n> struct Square{
// 	enum{val = n*n};
// };

// template<int n> struct Cube{
// 	enum{val = n*n*n};
// };

// int main(){
// 	cout << Accumulate<4, Identity>::val << endl;
// 	cout << Accumulate<4, Square>::val << endl;
// 	cout << Accumulate<4, Cube>::val << endl;
// }

// #include <iostream>
// using namespace std;

// template<int N, int P> struct Power{
// 	enum{ val = N * Power<N, P-1>::val };
// };
// template<int N> struct Power<N, 0>{
// 	enum{ val = 1 };
// };

// int main(){
// 	cout << Power<2, 7>::val << endl;
// 	// cout << Power<2, -1>::val << endl;
// }

// #include <iostream>
// using namespace std;

// template<int n> struct Fib{
// 	enum { val = Fib<n-1>::val + Fib<n-2>::val, };
// };
// template<> struct Fib<1> { enum{ val = 1}; };
// template<> struct Fib<0> { enum{ val = 0}; };

// int main(){
// 	cout << Fib<6>::val << endl << Fib<20>::val << endl;
// }

// #include <iostream>
// using namespace std;

// template<int n> 
// struct Factorial{
// 	enum { val = Factorial<n - 1>::val * n, };
// };

// template<>
// struct Factorial<0>{
// 	enum { val = 1, };
// };

// int main(){
// 	cout << Factorial<12>::val << endl;
// 	double d[Factorial<5>::val];
// 	cout << sizeof(double) * 120 << endl << sizeof d << endl;;
// 	cout << Factorial<5>::val << endl;
// 	cout << Factorial<12>::val << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T> 
// class Counted{
//     static int count;
// public:
// 	Counted() { ++count; }
// 	Counted(const Counted<T>&) { ++count;}
// 	~Counted() { --count; }	
// 	static int getCount() { return count; }
// };

// template<class T> int Counted<T>::count = 0;

// class CountedClass2 : public Counted<CountedClass2>{};
// class CountedClass : public Counted<CountedClass2>{};

// int main(){
// 	CountedClass a;
// 	cout << CountedClass::getCount() << endl;
// 	CountedClass b = a;
// 	cout << CountedClass::getCount() << endl;
// 	CountedClass2 c;
// 	cout << CountedClass2::getCount() << endl;
// }

// #include <iostream>
// using namespace std;

// class Counted{
//     static int count;
// public:
// 	Counted() { ++count; }
// 	Counted(const Counted&) { ++count; }
// 	~Counted(){ --count; }
// 	static int getCount() { return count; }
// };

// int Counted::count = 0;

// class CountedClass : public Counted{};
// class CountedClass2 : public Counted{};

// int main(){
// 	CountedClass a;
// 	cout << CountedClass::getCount() << endl;
// 	CountedClass2 b;
// 	cout << CountedClass2::getCount() << endl;
// }

// #include <iostream>
// using namespace std;

// class CountedClass{
//     static int count;
// public:
// 	CountedClass() { ++count; }
// 	CountedClass(const CountedClass&) { ++count; cout << "&" << endl; }
// 	~CountedClass(){ --count; }
// 	static int getCount() { return count; }
// };

// int CountedClass::count = 0;

// int main(){
// 	CountedClass a;
// 	cout << CountedClass::getCount() << endl;
// 	CountedClass b;
// 	cout << CountedClass::getCount() << endl;
// 	{
// 		CountedClass c(b);
// 		cout << CountedClass::getCount() << endl;
// 		CountedClass d = c;
// 		cout << CountedClass::getCount() << endl;
// 	}
// 	cout << CountedClass::getCount() << endl;
// }

// #include <iostream>
// #include "BearCorner.h"
// using namespace std;

// class Feed{
// public:
// 	static const char* doAction() { return "Feeding"; }
// };
// class Stuff{
// public:
// 	static const char* doAction() { return "Stuffing"; }
// };

// template<class Guest, class Action, class traits = GuestTraits<Guest> >
// class BearCorner{
//     Guest theGuest;
//     typedef typename traits::beverage_type beverage_type;
//     typedef typename traits::snack_type snack_type;
//     beverage_type bev;
//     snack_type snack;
// public:
// 	BearCorner(const Guest& g) : theGuest(g){}
// 	void entertain(){
// 		cout << Action::doAction() << " " << theGuest
// 		     << " with " << bev
// 		     << " and " << snack << endl;
// 	}	
// };

// int main(){
// 	Boy cr;
// 	BearCorner<Boy, Feed> pc1(cr);
// 	pc1.entertain();
// 	Bear pb;
// 	BearCorner<Bear, Stuff> pc2(pb);
// 	pc2.entertain();
// }

// #include <iostream>
// #include "BearCorner.h"
// using namespace std;

// class MixedUpTraits{
// public:
// 	typedef Milk beverage_type;
// 	typedef Honey snack_type;
// };

// template<class Guest, class traits = GuestTraits<Guest> >
// class BearCorner{
//     Guest theGuest;
//     typedef typename traits::beverage_type beverage_type;
//     typedef typename traits::snack_type snack_type;
//     beverage_type bev;
//     snack_type snack;
// public:
// 	BearCorner(const Guest& g) : theGuest(g){}
// 	void entertain(){
// 		cout << "Entertaining " << theGuest
// 		     << " serving " << bev
// 		     << " and " << snack << endl;
// 	}	
// };

// int main(){
// 	Boy cr;
// 	BearCorner<Boy> pc1(cr);
// 	pc1.entertain();
// 	Bear pb;
// 	BearCorner<Bear> pc2(pb);
// 	pc2.entertain();
// 	BearCorner<Bear, MixedUpTraits> pc3(pb);
// 	pc3.entertain();
// }

// #include <iostream>
// using namespace std;

// template<class T>
// class  Box{
//     T t;
// public:
// 	Box(const T& theT) : t(theT) {}
//     friend Box<T> operator+(const Box<T>& b1, const Box<T>& b2){
//     	return Box<T>(b1.t + b2.t);
//     }
//     friend ostream& operator<<(ostream& os, const Box<T>& b){
//     	return os << "[" << b.t << "]";
//     }
// };

// int main(){
// 	Box<int> b1(1), b2(2);
// 	cout << b1 + b2 << endl;
// 	cout << b1 + 6 << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T> class Box;

// template<class T>
// Box<T> operator+(const Box<T>&, const Box<T>&);
// template<class T>
// ostream& operator<<(ostream&, const Box<T>&);

// template<class T>
// class Box{
//     T t;
// public:
// 	Box(const T& theT) : t(theT) {}
// 	friend  Box operator+<>(const Box<T>&, const Box<T>&);
// 	friend ostream& operator<< <>(ostream&, const Box<T>&);	
// };

// template<class T>
// Box<T> operator+(const Box<T>& b1, const Box<T>& b2){
// 	return Box<T>(b1.t + b2.t);
// }

// template<class T>
// ostream& operator<< (ostream& os, const Box<T>& b){
// 	return os << "[" << b.t << "]";
// }

// int main(){
// 	Box<int> b1(1), b2(2);
// 	cout << b1 + b2 << endl;
// 	// cout << b1 + 2 << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T>
// class Friendly{
//     T t;
// public:
// 	Friendly(const T& theT): t(theT) {}
// 	friend void f(const Friendly<T>& fo){
// 		cout << fo.t << endl;
// 	}	
// 	void g() { f(*this); }
// };

// void h() {
// 	f(Friendly<int>(1));
// }

// int main(){
// 	h();
// 	Friendly<int>(2.2).g();
// }

// #include <iostream>
// using namespace std;

// template<class T> class Friendly;
// template<class T> void f(const Friendly<T>&);

// template<class T>
// class Friendly{
//     T t;
// public:
// 	Friendly(const T& theT) : t(theT) {}
// 	friend void f<>(const Friendly<T>&);
// 	void g() { f(*this); }
// };

// void h(){
// 	f(Friendly<int>(1));
// }

// template<class T> 
// void f(const Friendly<T>& fo){
// 	cout << fo.t << endl;
// }

// int main(){
// 	h();
// 	Friendly<double>(2.01).g();
// 	Friendly<int>(2.01).g();
// }

// #include <iostream>
// using namespace std;
// class Friendly{
//     int i;
// public:
// 	Friendly(int theInt) { i = theInt; }
// 	friend void f(const Friendly&);
// 	void g() { f(*this); }	
// };

// void f(const Friendly& fo){
// 	cout << fo.i << endl;
// }

// void h(){
// 	f(1); // 1 -> Friendly(1)
// }

// void f(const Friendly& fo){
// 	cout << fo.i << endl;
// }

// int main(){
// 	h();
// 	Friendly(2).g();
// }

// #include <algorithm>
// #include <iostream>
// #include <typeinfo>
// using std::cout;
// using std::endl;

// void g() { cout << "global g()" << endl; }

// template<class T>
// class Y{
// public:
// 	void g(){
// 		cout << "Y<" << typeid(T).name() << ">::g()" << endl;
// 	}	
// 	void h(){
// 		cout << "Y<" << typeid(T).name() << ">::h()" << endl;
// 	}
// 	typedef int E;
// };

// typedef double E;

// template<class T>
// void swap(T& t1, T& t2){
// 	cout << "global swap" << endl;
// 	T temp = t1;
// 	t1 = t2;
// 	t2 = temp;
// }

// template<class T>
// class X : public Y<T>{
// public:
// 	E f(){
// 		g();
// 		this->g();
// 		this->h();
// 		T t1 = T(), t2 = T(1);
// 		cout << t1 << " 1" << endl;
// 		swap(t1, t2);
// 		cout << t1 << " 2" << endl;
// 		std::swap(t1, t2);
// 		cout << t1 << " 3" << endl;
// 		cout << typeid(E).name() << endl;
// 		return E(t2/2.0);
// 	}	
// };

// int main(){
// 	X<int> x;
// 	cout << x.f() << endl;
// }

// #include <iostream>
// using std::cout;
// using std::endl;

// void f(double) { cout << "f(double)" << endl; }
// // void f(int) { cout << "f(int)" << endl; }

// template<class T>
// class X{
// public:
// 	void g() { f(1); }	
// };

// // void f(int) { cout << "f(int)" << endl; }

// int main(){
// 	X<int>().g();
// }

// #include <iostream>
// #include <string>
// #include "Nobloat.h"
// using namespace std;

// template<class StackType>
// void emptyTheStack(StackType& stk){
// 	while(stk.size() > 0){
// 		cout << stk.top() << endl;
// 		stk.pop();
// 	}
// }

// template<class T>
// void emptyTheStack(Stack<T*>& stk){
// 	while(stk.size() > 0){
// 		cout << *stk.top() << endl;
// 		stk.pop();
// 	}
// }

// int main(){
// 	Stack<int> s1;
// 	s1.push(1);
// 	s1.push(2);
// 	emptyTheStack(s1);
// 	Stack<int*> s2;
// 	int i = 3;
// 	int j = 4;
// 	s2.push(&i);
// 	s2.push(&j);
// 	emptyTheStack(s2);
// }

// class X{
// public:
// 	void f() {}
// };

// class Y{
// public:
// 	void g(){}
// };

// template<typename T> 
// class Z{
// 	T t;
// public:
// 	void a() { t.f(); }
// 	void b() { t.g(); }
// };

// int main(){
// 	Z<X> zx;
// 	zx.a();
// 	Z<Y> zy;
// 	zy.b();
// }

// #include <cstddef>
// #include <iostream>
// #include "Sortable.h"
// #include "Urand.h"
// using namespace std;

// #define asz(a) (sizeof a / sizeof a[0])

// char* words[] = { "is", "running", "big", "dog", "a", };
// char* words2[] = { "this", "that", "theother", };

// int main(){
// 	Sortable<int> is;
// 	Urand<47> rnd;
// 	for(size_t i = 0; i < 15; ++i)
// 		is.push_back(rnd());
// 	for(size_t i = 0; i < is.size(); ++i)
// 		cout << is[i] << ' ';
// 	cout << endl;
// 	is.sort();
// 	for(size_t i = 0; i < is.size(); ++i)
// 		cout << is[i] << ' ';
// 	cout << endl;

// 	Sortable<string*> ss;
// 	for(size_t i = 0; i < asz(words2); ++i)
// 		ss.push_back(new string(words2[i]));
// 	for(size_t i = 0; i < ss.size(); ++i)
// 		cout << *ss[i] << ' ';
// 	cout << endl;
// 	ss.sort();
// 	for(size_t i = 0; i < ss.size(); ++i)
// 		cout << *ss[i] << ' ';
// 	cout << endl;

// 	Sortable<char*> scp;
// 	for(size_t i = 0; i < asz(words2); ++i)
// 		scp.push_back(words2[i]);
// 	for(size_t i = 0; i < scp.size(); ++i)
// 		cout << scp[i] << ' ';
// 	cout << endl;
// 	scp.sort();
// 	for(size_t i = 0; i < scp.size(); ++i)
// 		cout << scp[i] << ' ';
// 	cout << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T, class U> 
// class C{
// public:
// 	void f() { cout << "Primary Template\n"; }
// };

// template<class U>
// class C<int, U>{
// public:
// 	void f() { cout << "T == int\n"; }
// };

// template<class T>
// class C<T, double>{
// public:
// 	void f() { cout << "U == double\n"; }
// };

// template<class T, class U> 
// class C<T*, U>{
// public:
// 	void f() { cout << "T* used\n"; }
// };

// template<class T>
// class C<T, T>{
// public:
// 	void f() { cout << "T == U\n"; }
// };

// int main(){
// 	C<float, int>().f();
// 	C<int, float>().f();
// 	// C<int, double>().f();
// 	C<float*, float>().f();
// 	C<double, double>().f();
// }

// #include <cstring>
// #include <iostream>
// using std::strcmp;
// using std::cout;
// using std::endl;

// template<class T>
// const T& min(const T& a, const T& b){
// 	return (a < b) ? a : b;
// }

// template<>
// const char* const& min<const char*>(const char* const& a, const char* const& b){
// 	return (strcmp(a, b) < 0) ? a : b;
// }

// int main(){
// 	const char *s2 = "say \"Ni-!\"", *s1 = "knights who";
// 	cout << min(s1, s2) << endl;
// 	cout << min<>(s1, s2) << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T>
// void f(T){
// 	cout << "T" << endl;
// }

// template<class T> 
// void f(T*){
// 	cout << "T*" << endl;
// }

// template<class T>
// void f(const T*){
// 	cout << "const T*" << endl;
// }

// int main(){
// 	f(0);
// 	int i = 0;
// 	f(&i);
// 	const int j = 0;
// 	f(&j);
// }

// #include <cstddef>
// #include <iostream>
// #include <vector>
// #include "ApplySequence.h"
// #include "Gromit.h"
// #include "../purge.h"
// using namespace std;

// int main(){
// 	vector<Gromit*> dogs;
// 	for(size_t i = 0; i < 5; i++)
// 		dogs.push_back(new Gromit(i));
// 	apply(dogs, &Gromit::speak, 1);
// 	apply(dogs, &Gromit::eat, 2.0f);
// 	apply(dogs, &Gromit::sleep, 'z', 3.0);
// 	apply(dogs, &Gromit::sit);
// 	purge(dogs);
// }

// #include <algorithm>
// #include <cctype>
// #include <iostream>
// #include <string>
// using namespace std;

// template<class charT> 
// charT strToLower(charT c){
// 	return tolower(c);
// }

// int main(){
// 	string s("LOWER");
// 	transform(s.begin(), s.end(), s.begin(), &strToLower<char>);
// 	cout << s << endl;
// }

// #include <algorithm>
// #include <cctype>
// #include <iostream>
// #include <string>
// // using namespace std;
// using std::string;
// using std::cout;
// using std::endl;
// using std::transform;
// string strToLower(string);

// int main(){
// 	string s("LOWER");
// 	// cout << strToLower(s) << endl;
// 	transform(s.begin(), s.end(), s.begin(), tolower);
// 	cout << s << endl;
// }

// string strToLower(string s){
// 	transform(s.begin(), s.end(), s.begin(), tolower);
// 	return s;
// }

// template<typename T> 
// void f(T*) {}

// void h(void (*pf)(int*)) {}

// template<typename T>
// void g(void (*pf)(T*)) {}

// int main(){
// 	h(&f<int>);
// 	h(&f);
// 	g<int>(&f<int>);
// 	g(&f<int>);
// 	g<int>(&f);
// }

// #include <iostream>
// using std::cout;

// template<typename T>
// const T& min(const T& a, const T& b, const T& c){
// 	return b < c ? b : c < a ? b < c ? b : c : a;
// 	/*a < (b < c ? b : c) ? a : (b < c ? b : c);*/
// }

// int main(){
// 	cout << min(2, 2, 1) << "\n";
// }

// #include <iostream>
// #include <cstring>
// using std::strcmp;
// using std::cout;
// using std::endl;

// void t() { cout << "template" << endl; }
// template<typename T> 
// const T& min(const T& a, const T& b){
// 	t();
// 	return (a < b) ? a : b;
// }

// // void c() { cout << "char*" << endl; }
// // const char* min(const char* a, const char* b){
// // 	c();
// // 	return (strcmp(a, b) < 0) ? a : b;
// // }

// // void d() { cout << "double" << endl; }
// // double min(double x, double y){
// // 	d();
// // 	return (x < y) ? x : y;
// // }

// int main(){
// 	cout << min(1, 2) << endl;
// 	cout << min(1.1, 2.3) << endl;
// 	// cout << min<int, double>(12, 2.0) << endl;
// 	const char* s1 = "say \"Ni-!\"", *s2 = "knights who";
// 	cout << min(s1, s2) << endl;
// 	cout << min<>(s1, s2) << endl;
// }

// #include <cstddef>
// using namespace std;

// template<size_t R, size_t C, typename T>
// void init1(T a[R][C]){
// 	for (size_t i = 0; i < R; ++i)
// 		for(size_t j = 0; j < C; ++j)
// 			a[i][j] = T();
// }

// template<size_t R, size_t C, class T>
// void init2(T (&a)[R][C]){
// 	for(size_t i = 0; i < R; ++i)
// 		for(size_t j = 0; j < C; ++j)
// 			a[i][j] = T();
// }

// int main(){
// 	int a[10][20];
// 	init1<10, 20, int>(a);
// 	init2<>(a);
// }

// #include <iostream>
// using namespace std;
// template<typename P, typename R>
// R implicit_cast(const P& p){
// 	return p;
// }

// int main(){
// 	int i = 1;
// 	float x = implicit_cast<int, float>(i);
// 	cout << x << endl;
//     int k = implicit_cast<float, int>(5.25);
//     cout << k << endl;
// 	float j = implicit_cast<double, float>(1.3);
// 	cout << j << endl;
// 	// char* p = implicit_cast<char*>(i);
// }

// #include <complex>
// #include <iostream>
// #include "StringConv.h"
// using namespace std;

// int main(){
// 	int i = 1234;
// 	cout << "i == \"" << toString<float>(i) << "\"" << endl;
// 	float f = 567.89;
// 	cout << "f == \"" << toString<int>(f) << "\"" << endl;
// 	complex<float> c(1.0, 2.0);
// 	cout << "c == \"" << toString(c) << "\"" << endl;
// 	cout << endl;
// 	i = fromString<int>("1234");
// 	cout << "i == " << i << endl;
// 	f = fromString<float>(string("567.89"));
// 	cout << "f == " << f << endl;
// 	c = fromString<complex<float> >(string("(1.0, 2.0)"));
// 	cout << "c == " << c << endl;
// }

// #include <iostream>
// #include <typeinfo>
// #include <string>
// using namespace std;

// template<class T>
// class Outer{
// public:
//     template<class R>
//     class Inner{
//     public:
//     	void f();    	
//     };	
// };

// template<class T> template<class R>
// void Outer<T>::Inner<R>::f(){
// 	cout << "Outer == " << typeid(T).name() << endl;
// 	cout << "Inner == " << typeid(R).name() << endl;
// 	cout << "Full Inner == " << typeid(*this).name() << endl;
// }

// int main(){
// 	Outer<int>::Inner<bool> inner;
// 	inner.f();
// 	cout << typeid(int).name() << endl;
// 	cout << typeid(double).name() << endl;
// 	cout << typeid(float).name() << endl;
// 	cout << typeid(int*).name() << endl;
// 	cout << typeid(bool).name() << endl;
// 	cout << typeid(short).name() << endl;
// 	cout << typeid(long).name() << endl;
// 	cout << typeid(unsigned long).name() << endl;
// 	cout << typeid(char).name() << endl;
// 	cout << typeid(string*).name() << endl;
// 	cout << typeid(cout).name() << endl;
	
// }

// #include <bitset>
// #include <cstddef>
// #include <iostream>
// #include <string>
// using namespace std;

// template<class charT, size_t N>
// basic_string<charT> bitsetToString(const bitset<N>& bs){
// 	return bs.template to_string<charT, char_traits<charT>, allocator<charT> >();
// }

// int main(){
// 	bitset<10> bs;
// 	bs.set(1);
// 	bs.set(5);
// 	cout << bs << endl;
// 	bs.set(3);
// 	string s = bitsetToString<char>(bs);
// 	cout << s << endl;
// }

// #include <iostream>
// #include <list>
// #include <vector>
// #include <memory>
// using namespace std;

// template<typename T, template<class U, class = allocator<U> > class Seq>
// void printSeq(Seq<T>& seq){
// 	for(typename Seq<T>::iterator b = seq.begin(); b != seq.end();)
// 		cout << *b++ << endl;
// }

// int main(){
// 	vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	printSeq(v);

// }

// #include <iostream>
// using namespace std;
// template<class T>
// class X{
//     typename T::id i;
// public:
// 	void f() { i.g(); cout << "f()" << endl; }	
// };

// class Y{
// public:
// 	class id{
// 	public:
// 		void g() { cout << "g()" << endl; }
// 	};
// };

// int main(){
// 	X<Y> xy;
// 	xy.f();
// }

// #include <iostream>
// #include <list>
// #include <memory>
// #include <vector>
// using namespace std;

// template<class T, template<class U, class = allocator<U> > class Seq>
// class Container{
//     Seq<T> seq;
// public:
// 	void push_back(const T& t){ seq.push_back(t); }	
// 	typename Seq<T>::iterator begin() { return seq.begin(); }
// 	typename Seq<T>::iterator end() { return seq.end(); }
// };

// int main(){

// 	Container<int, vector> vContainer;
// 	vContainer.push_back(1);
// 	vContainer.push_back(2);
// 	for (vector<int>::iterator p = vContainer.begin(); p != vContainer.end(); ++p){
// 		cout << *p << endl;
// 	}
// 	cout << "--------" << endl;
// 	Container<int, list> lContainer;
// 	lContainer.push_back(3);
// 	lContainer.push_back(4);
// 	for (list<int>::iterator p2 = lContainer.begin(); p2 != lContainer.end(); ++p2){
// 		cout << *p2 << endl;
// 	}
// }

// #include <cstddef>
// #include <iostream>
// using namespace std;

// template<class T, size_t N = 10>
// class Array{
//     T data[N];
//     size_t count;
// public:
// 	Array() { count = 0; }
// 	void push_back(const T& t){
// 		if(count < N)
// 			data[count++] = t;
// 	}	
// 	void pop_back(){
// 		if(count > 0)
// 			--count;
// 	}
// 	T* begin() { return data; }
// 	T* end() { return data + count; }
// };

// template<class T, template<class, size_t = 10> class Seq>
// class Container{
//     Seq<T> seq;
// public:
// 	void append(const T& t) { seq.push_back(t); }	
// 	T* begin() { return seq.begin(); }
// 	T* end() { return seq.end(); }
// };

// int main(){
// 	Container<int, Array> container;
// 	container.append(1);
// 	container.append(2);
// 	int* p = container.begin();
// 	while(p != container.end())
// 		cout << *p++ << endl;
// }

// #include <iostream>
// #include <cstddef>
// using namespace std;

// template<class T, size_t N> 
// class Array{
//     T data[N];
//     size_t count;
// public:
// 	Array() { count = 0; }
// 	void push_back(const T& t){
// 		if(count < N)
// 			data[count++] = t;
// 	}
// 	void pop_back(){
// 		if(count > 0)
// 			--count;
// 	}
// 	T* begin() { return data; }
// 	T* end() { return data + count; }
// };

// template<class T, size_t N, template<class, size_t> class Seq>
// class Container{
//     Seq<T, N> seq;
// public:
// 	void append(const T& t) { seq.push_back(t); }
// 	T* begin() { return seq.begin(); }
// 	T* end() { return seq.end(); }
// };

// int main(){
// 	const size_t N = 10;
//     Container<int, N, Array> container;
//     container.append(1);
//     container.append(2);
//     int* p = container.begin();
//     while(p != container.end())
//     	cout << p++ << endl;
// }

// #include <cstddef>
// #include <iostream>
// using namespace std;

// template<class T> 
// class Array{
//     enum { INIT = 10, };
//     T* data;
//     size_t capacity;
//     size_t count;
// public:
// 	Array(){
// 		count = 0;
// 		data = new T[capacity = INIT];
// 	}
// 	~Array() { delete []data; }
// 	void push_back(const T& t){
// 		if (count == capacity){
// 			size_t newCap = 2 * capacity;
// 			T* newData = new T[newCap];
// 			for(size_t i = 0; i < count; ++i)
// 				newData[i] = data[i];
// 			delete []data;
// 			data = newData;
// 			capacity = newCap;
// 		}
// 		data[count++] = t;
// 	}
// 	void pop_back(){
// 		if(count > 0)
// 			--count;
// 	}
// 	T* begin() { return data; }
// 	T* end() { return data + count; }
// };

// template<class T, template<class> class Seq>
// class Container{
//     Seq<T> seq;
// public:
// 	void append(const T& t){ seq.push_back(t); }	
// 	T* begin() { return seq.begin(); }
// 	T* end() { return seq.end(); }
// };

// int main(){
// 	Container<int, Array> container;
// 	container.append(1);
// 	container.append(2);
// 	container.append(3);
// 	int* p = container.begin();
// 	cout << sizeof(&container) << endl;
// 	while(p != container.end())
// 		cout << dec << p++ << endl;
// }

// #include <iostream>
// using namespace std;

// template<class T> T sum(T* b, T* e, T init = T()){
// 	while(b != e)
// 		init += *b++;
// 	return init;
// }

// int main(){
// 	int a[] = { 1, 2, 3, };
// 	cout << sum(a, a + sizeof a / sizeof a[0]) << endl;
// 	int i = int();
// 	cout << i << endl;
// }

// #include <iostream>
// #include "Urand.h"
// using namespace std;
// int main(){
// 	Urand<10> u;
// 	for (int i = 0; i < 20; i++){
// 		cout << u() << ' ';
// 	}
// }