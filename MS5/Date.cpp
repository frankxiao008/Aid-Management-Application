// Final Project Milestone 1
//
// Version 1.0
// Date  10/27/2018
// Author Saihong Xiao
// Description
//The final project
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Date.h"
using namespace std;

namespace aid {

	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	//The error state function
	//
	void Date::errCode(int errorCode) {

	
		switch (errorCode) {
			case 0:
				error = NO_ERROR;
				break;
			case 1:
				error = CIN_FAILED;
				break;
			case 2:
				error = DAY_ERROR;
				break;
			case 3:
				error = MON_ERROR;
				break;
			case 4:
				error = YEAR_ERROR;
				break;
			case 5:
				error = PAST_ERROR;
				break;
		
		}

	}

	//the default constructor
	//
	Date::Date() {
		year = 0;
		month = 0;
		day = 0;
		error = NO_ERROR;
		comparator = 0;

	}
	//the destructor
	//
	Date::~Date() {};

	//the constructor with three parameters
	//
	Date::Date(int ye, int mo, int da) {
		if (ye<min_year || ye > max_year) {
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (mo < 1 || mo >12) {
			*this = Date();
			errCode(MON_ERROR);

		}else if (da<1 || da > mdays(mo, ye)) {

			*this = Date();
			errCode(DAY_ERROR);
		}
		else if ((ye * 372 + mo * 31 + da )< min_date) {
			*this = Date();
			errCode(PAST_ERROR);
		}else{
			year = ye;
			month = mo;
			day = da;
			comparator = ye * 372 + mo * 31 + da;
			errCode(NO_ERROR);
		}
		
	}

	//The overload == operator
	//
	bool Date::operator==(const Date& rhs) const {
		bool compare;
		if (!bad() && !rhs.bad()) {
			compare = comparator == rhs.comparator;
		}
		else {
			compare = false;
		}
		return compare;
		
	}
	//The  != operator
	//

	bool Date::operator!=(const Date& rhs) const {

		bool compare;
		if (!bad() && !rhs.bad()) {
			compare = comparator != rhs.comparator;
		}
		else {
			compare = false;
		}
		return compare;
	}
	

	//The < comparison operator
	bool Date::operator<(const Date& rhs) const {
		bool compare;
			if (!bad() && !rhs.bad()) {
				compare = comparator < rhs.comparator;
			}
			else {
				compare = false;
			}
			return compare;
	}

	//The > comparison operator
	bool Date::operator>(const Date& rhs) const {
		bool compare;
			if (!bad() && !rhs.bad()) {
				compare = comparator > rhs.comparator;
			}
			else {
				compare = false;
			}
			return compare;
	}
	//The <= comparison operator
	bool Date::operator<= (const Date& rhs) const {
		bool compare;
			if (!bad() && !rhs.bad()) {
				compare = comparator <= rhs.comparator;
			}
			else {
				compare = false;
			}
			return compare;
	}
	//The >= comparison operator
	bool Date::operator>=(const Date& rhs) const {
		bool compare;
			if (!bad() && !rhs.bad()) {
				compare = comparator >= rhs.comparator;
			}
			else {
				compare = false;
			}
			return compare;
	}

	// return the error code value
	//
	int Date::errCode() const {
		return error;
	}
	//return if the error is not NO_ERROR
	//
	bool Date::bad() const {
		return !error == NO_ERROR;
	}

	std::istream& Date::read(std::istream& istr){
		char c;
		int tyear, tmonth, tday;
		
		istr.clear();
		istr >> tyear >> c >> tmonth >> c >> tday;
		
		if (istr.fail())
			errCode(CIN_FAILED);
		else {
			
			*this = Date(tyear, tmonth, tday);

		}		
		return istr;
		
	}
	
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr.fill('0');		
		ostr << year << "/";
		ostr.width(2);
		ostr << month << "/";
		ostr.width(2); 
		ostr << day;
		ostr.fill(' ');
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date ) {
		date.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Date& date) {
		date.read(istr);
		return istr;

	}
}
