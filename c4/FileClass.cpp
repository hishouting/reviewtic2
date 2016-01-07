#include "FileClass.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

FileClass ::FileClass(const char* fname, const char* mode){
	if((f = fopen(fname, mode)) == 0)
		throw FileClassError("Error opening file");
}

FileClass::~FileClass(){ fclose(f); }

FILE* FileClass::fp() { return f; }