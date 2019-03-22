// Final Project - Milestone 3 - MyGood and Test Modules
// Version 3.4
// Date	2018-11-14
// Good.h
// Author	Frank
/////////////////////////////////////////////////////////////////


#ifndef AID_GOOD_H
#define AID_GOOD_H
#include "iGood.h"
#include "Error.h"

namespace aid {
	

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Good:public iGood {
		char type;
		char good_sku[max_sku_length + 1];
		char good_unit[max_unit_length + 1];
		char * good_name;
		int num_onhand;
		int num_needed;
		double good_price;
		bool taxalbe;
		Error good_error;

	protected:
		void name(const char *);
		const char* name()const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Good(char T = 'N');
		Good(const char * psku, const char * pname, const char * punit, int pnum = 0, bool ptaxable = true, double  pprice = 0.0, int pnumneed = 0);
		Good(const Good&);
		Good& operator=(const Good&);
		virtual ~Good();
		std::fstream& store(std::fstream& file, bool newline = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const;
		int operator+=(int);


	};
	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);


	 

}




#endif // !AID_GOOD_h

