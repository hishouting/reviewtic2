#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
#include "Trim.h"
#include "../require.h"
using namespace std;

string& stripHTMLTags(string& s){
	static bool inTag = false;
	bool done = false;
	while(!done){
		if(inTag){
			size_t rightPos = s.find('>');
			if(rightPos != string::npos){
				inTag = false;
				s.erase(0, rightPos + 1);
			}
			else{
				done = true;
				s.erase();
			}
		}
		else{
			size_t leftPos = s.find('<');
			if(leftPos != string::npos){
				size_t rightPos = s.find('>');
				if(rightPos == string::npos){
					inTag = done = true;
					s.erase(leftPos);
				}
				else
					s.erase(leftPos, rightPos - leftPos + 1);
			}
			else
				done = true;
		}
	}

	replaceAll(s, "&lt;", "<");
	replaceAll(s, "&gt;", ">");
	replaceAll(s, "&amp;", "&");
	replaceAll(s, "&nbsp;", " ");

	return s;
}

int main(int argc, char const *argv[])
{
    requireArgs(argc, 1, "usage: HTMLStripper InputFile");
	ifstream in(argv[1]);
	assure(in, argv[1]);
	string s;
	while(getline(in, s))
		if(!stripHTMLTags(s).empty() && trim(s).size() > 1)
			cout << trim(s) << endl;
}