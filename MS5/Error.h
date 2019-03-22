// Final Project - Milestone 3 - MyGood and Test Modules
// Version 3.4
// Error.h
// Date	2018-11-06
// Author	Saihong(Frank) Xiao
//
//
/////////////////////////////////////////////////////////////////

#ifndef AID_ERROR_H
#define AID_ERROR_H
#include <iostream>


namespace aid {
	class Error {
		char * msg;
	public:
		Error();
		explicit Error(const char* errorMessage);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& error);


}

#endif 

