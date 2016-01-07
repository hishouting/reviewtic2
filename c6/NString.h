#ifndef NSTRING_H
#define NSTRING_H 
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<std::string, int> psi;

bool operator==(const psi& l, const psi& r){
	return l.first == r.first;
}

class NString{
	std::string s;
	int thisOccurence;
	typedef std::vector<psi> vp;
	typedef vp::iterator vpit;
	static vp words;
	void addString(const std::string& x){
		psi p(x, 0);
		vpit it = std::find(words.begin(), words.end(), p);
		if(it != words.end())
			thisOccurence = ++it->second;
		else{
			thisOccurence = 0;
			words.push_back(p);
		}
	}
public:
	NString() : thisOccurence(0){}
	NString(const std::string& x) : s(x){ addString(x); }
	NString(const char* x) : s(x){ addString(x); }
	friend std::ostream& operator<<(std::ostream& os, const NString& ns){
		return os << ns.s << " [" << ns.thisOccurence << "]";
	}
	friend bool operator<(const NString& l, const NString& r){
		return l.s < r.s;
	}
	friend bool operator==(const NString& l, const NString& r){
		return l.s == r.s;
	}
	friend bool operator>(const NString& l, const NString& r){
		return l.s > r.s;
	}
	operator const std::string&() const{ return s; }
};
NString::vp NString::words;
#endif // NSTRING_H