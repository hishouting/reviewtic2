#ifndef BEARCORNER_H
#define BEARCORNER_H 
#include <iostream>
using std::ostream;

class Milk{
public:
	friend ostream& operator<<(ostream& os, const Milk&){
		return os << "Milk";
	}	
};

class CondensedMilk{
public:
	friend ostream& operator<<(ostream& os, const CondensedMilk&){
		return os << "Condensed Milk";
	}
};

class Honey{
public:
	friend ostream& operator<<(ostream& os, const Honey&){
		return os << "Honey";
	}
};

class Cookies{
public:
	friend ostream& operator<<(ostream& os, const Cookies&){
		return os << "Cookies";
	}
};

class Bear{
public:
	friend ostream& operator<<(ostream& os, const Bear&){
		return os << "Theodore";
	}
};

class Boy{
public:
	friend ostream& operator<<(ostream& os, const Boy&){
		return os << "Patrick";
	}
};

template<class Guest> class GuestTraits;

template<>
class GuestTraits<Boy>{
public:
	typedef Milk beverage_type;
	typedef Cookies snack_type;
};

template<>
class GuestTraits<Bear>{
public:
	typedef CondensedMilk beverage_type;
	typedef Honey snack_type;
};

#endif // BEARCORNER_H