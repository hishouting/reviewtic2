
#include <iostream>
#include <new>
#include <cstring>
#include <cstddef>
using namespace std;

class HasPointers{
    struct MyData{
    	const char* theString;
    	const int* theInts;
    	size_t numInts;
    	MyData(const char* pString, const int* pInts, size_t nInts)
    	    : theString(pString), theInts(pInts), numInts(nInts) {}
    }* theData;
    static MyData* clone(const char* otherString, const int* otherInts, size_t nInts){
    	char* newChars = new char[strlen(otherString) + 1];
    	int* newInts;
    	try{
    		newInts = new int[nInts];
    	}catch(bad_alloc&){
    		delete []newChars;
    		throw;
    	}
    	try{
    		strcpy(newChars, otherString);
    		for (size_t i = 0; i < nInts; i++){
    			newInts[i] = otherInts[i];
    		}
    	}catch(...){
    		delete []newInts;
    		delete []newChars;
    		throw;
    	}
    	return new MyData(newChars, newInts, nInts);
    }
    static MyData* clone(const MyData* otherData){
    	return clone(otherData->theString, otherData->theInts, otherData->numInts);
    }
    static void cleanup(const MyData* theData){
        delete []theData->theString;
        delete []theData->theInts;
        delete theData;
    }
public:
	HasPointers(const char* someString, const int* someInts, size_t numInts){
		theData = clone(someString, someInts, numInts);
	}
	HasPointers(const HasPointers& source){
		theData = clone(source.theData);
	}
	HasPointers& operator=(const HasPointers& rhs){
		if (this != &rhs){
			MyData* newData = clone(rhs.theData->theString, rhs.theData->theInts, rhs.theData->numInts);
			cleanup(theData);
			theData = newData;
		}
		return *this;
	}
	~HasPointers(){
		cleanup(theData);
	}
	friend ostream& operator<<(ostream& os, const HasPointers& obj){
		os << obj.theData->theString << ": ";
		for (size_t i = 0; i < obj.theData->numInts; ++i){
			os << obj.theData->theInts[i] << ' ';
		}
		return os;
	}
};

int main(){
	int someNums[] = { 1, 2, 3, 4, };
	size_t someCount = sizeof someNums / sizeof someNums[0];
	int someMoreNums[] = { 5, 6, 7, };
	size_t someMoreCount = sizeof someMoreNums / sizeof someMoreNums[0];
	HasPointers h1("hello", someNums, someCount);
	HasPointers h2("bye", someMoreNums, someMoreCount);
	cout << h1 << endl;
	h1 = h2;
	cout << h1 << endl;
}

// #include <iostream>
// using namespace std;

// class Base{
// public:
// 	class BaseException {};
// 	class DerivedException : public BaseException{};	
// 	virtual void f() throw(DerivedException){
// 		throw DerivedException();
// 	}
// 	virtual void g() throw(BaseException){
// 		throw BaseException();
// 	}
// };

// class Derived : public Base{
// public:
// 	void f() throw(BaseException){
// 		throw BaseException();
// 	}	
// 	virtual void g() throw(DerivedException){
// 		throw DerivedException();
// 	}
// };

// #include <exception>
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// using namespace std;

// class A{};
// class B{};

// void my_thandler(){
// 	cout << "terminate called" << endl;
// 	exit(0);
// }

// void my_uhandler1(){ throw A(); }
// void my_uhandler2(){ throw; }

// void t(){ throw B(); }

// void f() throw(A) { t(); }
// void g() throw(A, bad_exception) { t(); }

// int main(){ 
// 	set_terminate(my_thandler);
// 	set_unexpected(my_uhandler1);
// 	try{
// 		f();
// 	}catch(A&){
// 		cout << "caught an A from f" << endl;
// 	}
// 	set_unexpected(my_uhandler2);
// 	try{
// 		g();
// 	}catch(bad_exception&){
// 		cout << "caught a bad_exception from g" << endl;
// 	}
// 	try{
// 		f();
// 	}catch(...){
// 		cout << "This will never print" << endl;
// 	}
// }

// #include <exception>
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// class Up{};
// class Fit{};
// void g();

// void f(int i) throw(Up, Fit){
// 	switch(i){
// 		case 1: throw Up();
// 		case 2: throw Fit();
// 	}
// 	g();
// }

// // void g(){}
// void g(){ throw 47; }

// void my_unexpected(){
// 	cout << "unexpected exception thrown" << endl;
// 	exit(0);
// }

// int main(){
// 	set_unexpected(my_unexpected);
// 	for (int i = 0; i <= 3; i++){
// 		try{
// 			cout << "i = " << i << endl;
// 			f(i);
// 		}catch(Up){
// 			cout << "Up caught" << endl;
// 		}catch(Fit){
// 			cout << "Fit caught" << endl;
// 		}
// 	}
// }

// #include <stdexcept>
// #include <iostream>
// using namespace std;

// class MyError : public runtime_error{
// public:
// 	MyError(const string& msg = "") : runtime_error(msg){}
// };

// int main(){
// 	try{
// 		throw MyError("my message");
// 	}catch(MyError& x){
// 		cout << x.what() << endl;
// 	}
// }

// #include <iostream>
// using namespace std;

// int main() try{
// 	throw "main";
// }catch(const char* msg){
// 	cout << msg << endl;
// 	return 1;
// }

// #include <iostream>
// using namespace std;

// class Base{
//     int i;
// public:
// 	class BaseExcept{};
// 	Base(int i) : i(i) { throw BaseExcept(); }	
// };

// class Derived : public Base{
// public:
// 	class DerivedExcept{
//         const char* msg;
//     public:
//     	DerivedExcept(const char* msg) : msg(msg) {}
//     	const char* what() const { return msg; }
// 	};
// 	Derived(int j) try : Base(j){
// 		cout << "This won't print" << endl;
// 	}catch(BaseExcept){
// 		throw DerivedExcept("Base subobject threw");
// 	}	
// };

// int main(){
// 	try{
// 		Derived d(3);
// 	}catch(Derived::DerivedExcept& d){
// 		cout << d.what() << endl;
// 	}
// }

// #include <memory>
// #include <iostream>
// #include <cstddef>
// using namespace std;

// class TraceHeap{
//     int i;
// public:
//     static void* operator new(size_t siz){
//     	void* p = ::operator new(siz);
//     	cout << "allocating TraceHeap object on the heap at address " << p << endl;
//     	return p;
//     }
// 	static void operator delete(void* p){
// 		cout << "deleting TraceHeap object at address " << p << endl;
// 		::operator delete(p);
// 	}
// 	TraceHeap(int i) : i(i) {}
// 	int getVal() const { return i; }
// };

// int main(){
// 	auto_ptr<TraceHeap> pMyObject(new TraceHeap(5));
// 	cout << pMyObject->getVal() << endl;
// }

// #include <iostream>
// #include <cstddef>
// using namespace std;

// template<class T, int sz = 1>
// class PWrap{
//     T* ptr;
// public:
// 	class RangeError{};
// 	PWrap(){
// 		ptr = new T[sz];
// 		cout << "PWrap constructor" << endl;
// 	}
// 	~PWrap(){
// 		delete []ptr;
// 		cout << "PWrap destructor" << endl;
// 	}

// 	T& operator[](int i) throw(RangeError){
// 		if(i >= 0 && i < sz) return ptr[i];
// 		throw RangeError();
// 	}	
// };

// class Cat{
// public:
// 	Cat() { cout << "Cat()" << endl; }
// 	~Cat(){ cout << "~Cat()"<< endl; }
// 	void g() {}
// };

// class Dog{
// public:
// 	void* operator new[](size_t){
//         cout << "allocating a Dog" << endl;
//         throw 47;
// 	}
// 	void operator delete[](void* p){
// 		cout << "deallocating a Dog" << endl;
// 		::operator delete[](p);
// 	}	
// };

// class UseResources{
//     PWrap<Cat, 3> cats;
//     PWrap<Dog> dogs;
// public:
// 	UseResources(){ cout << "UseResources()" << endl; }
// 	~UseResources(){cout << "~UseResources()" << endl; }
// 	void f(){ cats[1].g(); }
// };

// int main(){
//     try{
//     	UseResources ur;
//     }catch(int){
//     	cout << "inside handler" << endl;
//     }catch(...){
//     	cout << "inside catch" << endl;
//     }
// }

// #include <iostream>
// #include <cstddef>
// using namespace std;

// class Cat{
// public:
// 	Cat() { cout << "Cat()" << endl; }
// 	~Cat() { cout << "~Cat()" << endl; }
// };

// class Dog{
// public:
// 	void* operator new(size_t sz){
// 		cout << "allocating a Dog" << endl;
// 		throw 47;
// 	}	
// 	void operator delete(void* p){
// 		cout << "deallocating a Dog" << endl;
// 		::operator delete(p);
// 	}
// };

// class UseResources{
//     Cat* bp;
//     Dog* op;
// public:
// 	UseResources(int count = 1){
// 		cout << "UseResources()" << endl;
// 		bp = new Cat[count];
// 		op = new Dog;
// 	}
// 	~UseResources(){
// 		cout << "~UseResources()" << endl;
// 		delete []bp;
// 		delete op;
// 	}
// };

// int main(){
// 	try{
// 		UseResources ur(3);
// 	}catch(int){
// 		cout << "inside handler" << endl;
// 	}
// }

// #include <iostream>
// using namespace std;

// class Trace{
//     static int counter;
//     int objid;
// public:
// 	Trace(){
// 		objid = counter++;
// 		cout << "constructing Trace #" << objid << endl;
// 		if(objid == 3) throw 3;
// 	}
// 	~Trace(){
// 		cout << "destructing Trace #" << objid << endl;
// 	}	
// };

// int Trace::counter = 0;

// int main(){
// 	try{
// 		Trace n1;
// 		Trace array[5];
// 		Trace n2;
// 	}catch(int i){
// 		cout << "caught " << i << endl;
// 	}
// }

// #include <exception>
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// void terminator(){
// 	cout << "I'll be back!" << endl;
// 	exit(0);
// }

// void (*old_terminate)() = set_terminate(terminator);

// class Botch{
// public:
// 	class Fruit{};
// 	void f(){
// 		cout << "Botch::f()" << endl;
// 		throw Fruit();
// 	}
// 	~Botch(){ 
// 		//throw 'c'; 
// 	}
// };

// int main(){
// 	try{
// 		Botch b;
// 		b.f();
// 	}catch(...){
// 		cout << "inside catch(...)" << endl;
// 	}
// }

// #include <iostream>
// using namespace std;

// class X{
// public:
// 	class Trouble{};
// 	class Small : public Trouble{};
//     class Big : public Trouble{};
//     void f() { throw Big(); }
// };

// int main(){
// 	X x;
// 	try{
// 		x.f();
// 	}catch(X::Big&){
// 		cout << "caught Big Trouble" << endl;
// 	}catch(X::Small&){
// 		cout << "caught Small Trouble" << endl;
// 	}catch(X::Trouble&){
// 		cout << "caught Trouble" << endl;
// 	}
// }

// #include <iostream>
// using namespace std;
// class Expect1{};
// class Expect2{
// public:
// 	Expect2(const Expect1&) {}
// };

// void f() { throw Expect1(); }

// int main(){
// 	try{
// 		f();
// 	}catch(Expect2&){
// 		cout << "inside catch(Expect2)" << endl;
// 	}catch(Expect1&){
// 		cout << "inside catch(Expect1)" << endl;
// 	}
// }

// #include <iostream>
// using namespace std;

// class Rainbow{
// public:
// 	Rainbow() { cout << "Rainbow()" << endl; }
// 	~Rainbow() { cout << "~Rainbow()" << endl; }
// };

// void oz(){
// 	Rainbow rb;
// 	for (int i = 0; i < 3; i++){
// 		cout << "hkdkne" << endl;
// 	}
// 	throw 47;
// }

// int main(){
// 	try{
// 		cout << "ayioue" << endl;
// 		oz();
// 	}catch(int){
// 		cout << "hhhhhhh" << endl;
// 	}
// }

// class MyError{
// 	const char* const data;
// public:
// 	MyError(const char* const msg = 0) : data(msg) {}
// };

// void f(){
// 	throw MyError("Something bad happened");
// }

// int main(){
// 	try{
// 		f();
// 	}catch(MyError){}
// 	// f();
// }

// #include <iostream>
// #include <csetjmp>
// using namespace std;

// class Rainbow{
// public:
// 	Rainbow() { cout << "Rainbow()" << endl; }
// 	~Rainbow() { cout << "~Rainbow()" << endl; }
// };

// jmp_buf kansas;

// void oz(){
// 	Rainbow rb;
// 	for (int i = 0; i < 3; i++){
// 		cout << "there's no place like home" << endl;
// 	}
// 	longjmp(kansas, 47);
// 	cout << "not pritn" << endl;
// }

// int main(){
// 	// cout << setjmp(kansas) << endl;
// 	int i = setjmp(kansas);
// 	cout << i << endl;// << sizeof kansas << endl;
// 	if (i == 0){
// 		// int i = setjmp(kansas);
// 		// cout << i << endl;
// 		cout << "tornado, witch, munchkins..." << endl;
// 		oz();
// 	}else{
// 		cout << "Auntie Em! I had the strangest dream..." << endl;
// 	}
// 	// cout << setjmp(kansas) << endl; 
// }