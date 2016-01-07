#ifndef GENERATORS_H
#define GENERATORS_H 
#include <cstring>
#include <set>
#include <cstdlib>

class SkipGen{
    int i;
    int skp;
public:
	SkipGen(int start = 0, int skip = 1):i(start), skp(skip){}
	int operator()(){
		int r = i;
		i += skp;
		return r;
	}
};

class URandGen{
    std::set<int> used;
    int limit;
public:
	URandGen(int lim) : limit(lim){}
	int operator()(){
		while(true){
			int i = int(std::rand()) % limit;
			if (used.find(i) == used.end()){
				used.insert(i);
				return i;
			}
		}
	}	
};

class CharGen{
    static const char* source;
    static const int len;
public:
	char operator()(){
		return source[std::rand() % len];
	}	
};
#endif // GENERATORS_H