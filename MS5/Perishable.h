// Final Project Milestone 5
//
// Version 1.0
// Date  11/27/2018
// Author Saihong Xiao
// Description
//The final project
/////////////////////////////////////////////////////////////////

#ifndef AID_PERISH_H
#define AID_PERISH_H


#include "Good.h"
#include "Date.h"

namespace aid {

	class Perishable : public Good {
		Date pergooddate;

	public:
		Perishable();
		~Perishable() {}
		std::fstream& store(std::fstream& file, bool newline = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;



	};


}




#endif