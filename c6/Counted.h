#ifndef COUNTED_H
#define COUNTED_H 
#include <vector>
#include <iostream>

class Counted{
	static int count;
	char* ident;
public:
	Counted(char* id):ident(id){ ++count; }
	~Counted(){
		std::cout << ident << " count = " << --count << std::endl;
	}
};

class CountedVector : public std::vector<Counted*>{
public:
	CountedVector(char* id){
		for (int i = 0; i < 5; i++){
			push_back(new Counted(id));
		}
	}
};

int Counted::count = 0;
#endif // COUNTED_H