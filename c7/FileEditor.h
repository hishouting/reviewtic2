#ifndef FILEEDITOR_H
#define FILEEDITOR_H 
#include <iostream>
#include <string>
#include <vector>

class FileEditor : public std::vector<std::string>{
public:
	void open(const char* fileName);
	FileEditor(const char* fileName){ open(fileName); }
	FileEditor(){};
	void write(std::ostream& out = std::cout);
};
#endif // FILEEDITOR_H