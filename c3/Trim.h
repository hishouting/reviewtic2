#ifndef TRIM_H
#define TRIM_H 
#include <string>
#include <cstddef>

inline std::string trim(const std::string& s){
	if(s.length() == 0)
		return s;
	std::size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");

	/*  
		/a:蜂鸣，响铃
		/b:回退：向后退一格 
		/f:换页 
		/n:换行，光标到下行行首 
		/r:回车，光标到本行行首 
		/t:水平制表 
		/v:垂直制表  
	*/

	std::size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
	if(beg == std::string::npos)
		return "";
	return std::string(s, beg, end - beg + 1);
}
#endif // TRIM_H