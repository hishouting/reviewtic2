#ifndef SORTABLE_H
#define SORTABLE_H 
#include <cstring>
#include <cstddef>
#include <string>
#include <vector>
using std::size_t;

template<class T>
class Sortable : public std::vector<T>{
public:
	void sort();	
};

template<class T>
void Sortable<T>::sort(){
	for(size_t i = this->size(); i > 0; --i)
		for(size_t j = 1; j < i; ++j)
			if(this->at(j - 1) > this->at(j)){
				T t = this->at(j - 1);
				this->at(j - 1) = this->at(j);
				this->at(j) = t;
			}
}

template<class T>
class Sortable<T*> : public std::vector<T*>{
public:
	void sort();	
};

template<class T>
void Sortable<T*>::sort(){
	for(size_t i = this->size(); i > 0; --i)
		for(size_t j = 1; j < i; ++j)
			if(*this->at(j - 1) > *this->at(j)){
				T* t = this->at(j - 1);
				this->at(j - 1) = this->at(j);
				this->at(j) = t;
			}
}

template<>
inline void Sortable<char*>::sort(){
	for(size_t i = this->size(); i > 0; --i)
		for(size_t j = 1; j < i; ++j)
			if(std::strcmp(this->at(j - 1), this->at(j)) > 0){
				char* t = this->at(j - 1);
				this->at(j - 1) = this->at(j);
				this->at(j) = t;
			}
}
#endif // SORTABLE_H