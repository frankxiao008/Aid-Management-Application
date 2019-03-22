// Final Project - Milestone 3 - MyGood and Test Modules
// Version 3.4
// Error.cpp
// Date	2018-11-06
// Author	Saihong(Frank) Xiao
//
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include"Error.h"

using namespace std;

namespace aid {
	Error::Error() {
		msg = nullptr;
	}

	Error::Error(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0')
			msg = nullptr;
		else {
			msg = new char[strlen(errorMessage) + 1];
			strcpy(msg, errorMessage);
		}


	 }
	 

	

	//deallocates  memory allocated to the current object.
	//
	 Error::~Error() {
		delete[] msg;
		
	}

	//clears any message stored by the current object 
	//
	void Error::clear() {
		delete[] msg;
		msg = nullptr;
	}

	//query function for the state of the current object.
	//
	bool Error::isClear() const {
		return msg == nullptr;
	}

	//stores a copy of the C - style string passed by a pointer
	//
	void Error::message(const char* str) {
		clear();
		if (str == nullptr || str[0] == '\0')
			msg = nullptr;
		else {
			msg = new char[strlen(str) + 1];
			strcpy(msg, str);
			msg[strlen(str)] = '\0';
		}
	}

	//query function to return the address of the message in current object.
	//
	const char* Error::message() const {		
			return msg;
	}

	//Overloaded operator of <<
	//
	ostream& operator<<(ostream& os, const Error& error){
		if (!error.isClear()) {
			os << error.message();
		}
		return os;
	}

};



