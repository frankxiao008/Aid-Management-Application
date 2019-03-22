// Final Project Milestone 5
//
// Version 1.0
// Date  11/27/2018
// Author Saihong Xiao
// Description
//The final project
/////////////////////////////////////////////////////////////////

#include "Perishable.h"


namespace aid {

	//The dafault constructor
	//
	Perishable::Perishable() :Good('P') {
		isClear();
	}
	//Store into the file record for the current Perishable object
	//
	std::fstream& Perishable::store(std::fstream& file, bool newline) const {
		Good::store(file, false);
		file << "," << pergooddate;
		if (newline)
			file << std::endl;
		return file;
	}

	////Function that read a record from file store it in current object.
	//
	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file);
		pergooddate.read(file);
		file.ignore();
		return file;
	}
	//The function that output the current object data into to the stand output object.
	//
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {


		Good::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear)
				pergooddate.write(os);
			else {

				os << std::endl << " Expiry date: ";
				pergooddate.write(os);
			}


		}

		return os;
	}

	//A modifier function take data from istream object
	//and set it into the current object.
	std::istream& Perishable::read(std::istream& is) {
		is.clear();
		Good::read(is);
		if (isClear()) {
			//Date tempdate;
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> pergooddate;
		}
		if (pergooddate.bad()) {
			is.setstate(std::ios::failbit);
			switch (pergooddate.errCode()) {
			case CIN_FAILED:
				this->message("Invalid Date Entry");
				break;
			case YEAR_ERROR:
				message("Invalid Year in Date Entry");
				break;
			case MON_ERROR:
				message("Invalid Month in Date Entry");
				break;
			case DAY_ERROR:
				message("Invalid Day in Date Entry");
				break;
			case PAST_ERROR:
				message("Invalid Expiry in Date Entry");
			}
		}
		return is;
	}

	//Query function return the expiry date of 
	//the perishable good
	const Date& Perishable::expiry() const {
		return pergooddate;
	}


}



