#ifndef DATE_H
#define DATE_H 
#include <string>
#include <stdexcept>
#include <iosfwd>

class Date{
	int year, month, day;
	int compare(const Date&) const;
	static int daysInPrevMonth(int year, int mon);
public:
	struct Duration{
		int years, months, days;
		Duration(int y, int m, int d) : years(y), months(m), days(d){}
	};
	struct DateError : public std::logic_error{
		DateError(const std::string& msg = "") : std::logic_error(msg) {}
	};
	Date();
	Date(int year, int month, int day) throw(DateError);
	Date(const std::string&) throw(DateError);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	std::string toString() const;
	friend bool operator<(const Date&, const Date&);
	friend bool operator>(const Date&, const Date&);
	friend bool operator<=(const Date&, const Date&);
	friend bool operator>=(const Date&, const Date&);
	friend bool operator==(const Date&, const Date&);
	friend bool operator!=(const Date&, const Date&);	
	friend Duration duration(const Date& ,const Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator>>(std::istream&, Date&);
};
#endif // DATE_H