
#include <iostream>
#include <fstream>
#include "../require.h"
using namespace std;

#define TRACEON
#include "Trace.h"

int main(){
	ifstream f("Tracetst.cpp");
	assure(f, "Tracetst.cpp");
	cout << f.rdbuf();
}