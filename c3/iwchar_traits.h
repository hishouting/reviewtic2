#ifndef IWCHAR_TRAITS_H
#define IWCHAR_TRAITS_H 
#include <cassert>
#include <cwctype>
#include <cmath>
#include <cstddef>
#include <ostream>
#include <string>

using std::allocator;
using std::basic_string;
using std::char_traits;
using std::wostream;
using std::size_t;
using std::wstring;
using std::towupper;
using std::towlower;

struct iwchar_traits : char_traits<wchar_t>{
	static bool eq(wchar_t c1st, wchar_t c2nd){
		return towupper(c1st) == towupper(c2nd);
	}
	static bool ne(wchar_t c1st, wchar_t c2nd){
		return !eq(c1st, c2nd);
	}
	static int compare(const wchar_t* str1, const wchar_t* str2, size_t n){
		for(size_t i = 0; i < n; ++i){
			if(str1 == 0)
				return -1;
			else if(str2 == 0)
				return 1;
			else if(towlower(*str1) < towlower(*str2))
				return -1;
			else if(towlower(*str1) < towlower(*str2))
				return 1;
			assert(towlower(*str1) == towlower(*str2));
			++str1; ++str2;
		}
		return 0;
	}
	static const wchar_t* find(const wchar_t* s1, size_t n, wchar_t c){
		while(n-- > 0)
			if(towupper(*s1) == towupper(c))
				return s1;
			else
				++s1;
		return 0;
	}
};

typedef basic_string<wchar_t, iwchar_traits> iwstring;

inline wostream& operator<<(wostream& os, const iwstring& s){
	return os << wstring(s.c_str(), s.length());
}
#endif