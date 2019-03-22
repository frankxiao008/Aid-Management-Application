// Final Project - Milestone 3 - MyGood and Test Modules
// Version 3.4
// Date	2018-11-14
// Good.cpp
// Author	Saihong(Frank) Xiao
//
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Good.h"


using namespace std;

namespace aid {

	//The name setting function
	//
	void Good::name(const char * pname) {
		
		if (pname != nullptr) {
			if(good_name !=nullptr)
			delete[] good_name;
			good_name = new char[max_name_length + 1];
			strcpy(good_name, pname);
			good_name[max_name_length] = '\0';
		}
		else {
			if (good_name != nullptr) {

				delete[] good_name;
			good_name = nullptr;
			}
		}

	}

	//query function to return the address of good name
	//
	const char* Good::name()const {
		return good_name;
	}
	//Query function to return the address of sku
	//
	const char* Good::sku() const {
		return good_sku;
	}
	//query returns the address of unit name string
	//
	const char* Good::unit() const {

		return good_unit;
	}

	//Taxable query function
	//
	bool Good::taxed() const {
		return taxalbe;
	}
	//Single good item price query function
	//
	double Good::price() const {
		return good_price;
	}
	//Query function a single item total cost(include price)
	//
	double Good::cost() const {
		return taxalbe ? good_price * (1 + tax_rate) : good_price;
	}
	//Set the error message recieved into good_error object in current object.
	//
	void Good::message(const char* pmsg) {
		good_error.message(pmsg);
	}
	//Return if the good_error object is has message or not
	//
	bool Good::isClear() const {
		return good_error.isClear();
	}
	//The default constructor
	//
	Good::Good() {
		type = 'N';
		good_sku[0] = '\0';
		good_unit[0] = '\0';
		good_name=nullptr;
		num_onhand = 0;
		num_needed = 0;
		good_price = 0;
		taxalbe = true;
	}
	//The default constructor
	//
	Good::Good(char T) {
		type = 'P';
		good_sku[0] = '\0';
		good_unit[0] = '\0';
		good_name = nullptr;
		num_onhand = 0;
		num_needed = 0;
		good_price = 0;
		taxalbe = true;
	}

	//The constructor that recieves seven parameters
	//
	Good::Good(const char * psku, const char * pname, const char * punit, int pnum, bool ptaxable, double  pprice, int pnumneed) {
		bool notNull = psku != nullptr && pname != nullptr && punit != nullptr;
		if (notNull) {

			strncpy(good_sku, psku, max_sku_length);
			good_sku[max_sku_length] = '\0';
			strncpy(good_unit, punit, max_unit_length);
			good_unit[max_unit_length] = '\0';
			good_name = nullptr;
			name(pname);
			num_onhand = pnum;
			taxalbe = ptaxable;
			good_price = pprice;
			num_needed = pnumneed;

		}
		else
			*this = Good('N');
	}
	//Copy constructor for Good class
	//
	Good::Good(const Good& g) {
		good_name = nullptr;
		*this = g;
	}
	//Copy assignment operator for Good class
	//
	Good& Good::operator=(const Good& g) {
		if (this != &g) {
			if (g.type == 'N' || g.type == 'P') {
				type = g.type;

			}
			strcpy(good_sku, g.good_sku);
			strcpy(good_unit, g.good_unit);
			name(g.good_name);
			num_onhand = g.num_onhand;
			taxalbe = g.taxalbe;
			good_price = g.good_price;
			num_needed = g.num_needed;
			message(g.good_error.message());
		}
		return *this;
	}
	//The destructor
	//
	Good::~Good() {
		delete[] good_name;
	}
	//The function to store the current object into the file.
	//
	std::fstream& Good::store(std::fstream& file, bool newline) const {
		//P,1234,water,liter,0,1.5,1,5
		char comma = ',';
		file << type << comma << good_sku << comma << (good_name==nullptr? "":good_name )<< comma << good_unit << comma << taxalbe << comma << good_price <<
			comma << num_onhand << comma << num_needed;
		if (newline == true)
			file << endl;
		return file;
	}
	//Function that read a record from file store it in current object.
	//
	std::fstream& Good::load(std::fstream& file) {

		Good temp;
		temp.good_name = new char[max_name_length + 1];
		if (file.is_open()) {

			//file >> temp.type;
			//file.ignore();
			file.getline(temp.good_sku, max_sku_length + 1, ',');
			//file.ignore();
			file.getline(temp.good_name, max_name_length + 1, ',');
			//file.ignore();
			file.getline(temp.good_unit, max_unit_length + 1, ',');

			file >> temp.taxalbe;
			file.ignore();
			file >> temp.good_price;
			file.ignore();
			file >> temp.num_onhand;
			file.ignore();
			file >> temp.num_needed;
			file.ignore();

			*this = temp;
		}


		return file;
	}
	//The function that output the current object data into to the stand output object.
	//
	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (!isClear()) {
			os << good_error.message();
		}
		else if (linear) {

			os.setf(std::ios::fixed);
			os << setw(max_sku_length) << left << good_sku << "|"
				<< setw(20) << left << good_name << "|"
				<< setw(7) << right << setprecision(2) << cost() << "|"
				<< setw(4) << right << num_onhand << "|"
				<< setw(10) << left << good_unit << "|"
				<< setw(4) << right << num_needed << "|";
		}
		else {
			os << " Sku: " << good_sku << endl;
			os << " Name (no spaces): " << good_name << endl;
			os << " Price: " << good_price << endl;
			os << " Price after tax: ";
			if (taxalbe)
				os << cost() << endl;
			else
				os << " N/A" << endl;
			os << " Quantity on Hand: " << num_onhand << " " << good_unit << endl;
			os << " Quantity needed: " << num_needed;
		}
		return os;
	}
	//A modifier function take value from the stand input
	//and set it into the current object.
	std::istream& Good::read(std::istream& is) {

		char temp_sku[max_sku_length + 1];
		char temp_name[max_name_length + 1];
		char temp_unit[max_unit_length];
		char temp_taxed;
		bool temp_taxable;
		double temp_price;
		int temp_num_onhand;
		int temp_num_needed;

		cout << " Sku: ";
		is >> temp_sku;

		cout << " Name (no spaces): ";
		is >> temp_name;
		cout << " Unit: ";
		is >> temp_unit;
		cout << " Taxed? (y/n): ";
		is >> temp_taxed;
		if (temp_taxed != 'y' && temp_taxed != 'Y'&& temp_taxed != 'n' && temp_taxed != 'N') {
			is.setstate(std::ios::failbit);
			good_error.message("Only (Y)es or (N)o are acceptable");
		}
		else {
			if (temp_taxed == 'y' || temp_taxed == 'Y')
				temp_taxable = true;
			else
				temp_taxable = false;
		}

		if (!is.fail()) {
			cout << " Price: ";
			is >> temp_price;
			if (is.fail())
				good_error.message("Invalid Price Entry");
		}

		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> temp_num_onhand;
			if (is.fail())
				good_error.message("Invalid Quantity Entry");
		}

		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> temp_num_needed;
			if (is.fail())
				good_error.message("Invalid Quantity Needed Entry");

		}

		if (!is.fail())
			*this = Good(temp_sku, temp_name, temp_unit, temp_num_onhand, temp_taxable, temp_price, temp_num_needed);
	
		is.ignore(2000, '\n');
		return is;
	}
	//Compare the string recieved to the current object sku
	//
	bool Good::operator==(const char* psku) const {

		return strcmp(good_sku, psku) == 0;
	}

	//Query function that return the total cost of good on hand
	//taxes included.
	double Good::total_cost() const {
		return cost() * num_onhand;
	}
	//reset the number of goods on hand to a recieved value.
	//
	void Good::quantity(int new_num) {
		if (new_num > 0) {
			num_onhand = new_num;
		}
	}
	//query function for the safe empty state of the object.
	bool Good::isEmpty() const {
		return good_sku[0] == '\0'&&good_unit[0] == '\0'&& good_name == nullptr;
	}
	//qeury function for the quantity needed.
	//
	int Good::qtyNeeded() const {
		return num_needed;
	}
	//query function for the qqantity on hand
	int Good::quantity() const {
		return num_onhand;
	}
	//
	bool Good::operator>(const char* psku) const {
		return strcmp(good_sku, psku) > 0;
	}


	//compare the current object good_name with the recieved  object's good_name
	bool Good::operator>(const iGood& g) const {
		return strcmp(good_name, g.name());
	}
	//overloaded ++ to add the number to num_onhand.
	//
	int Good::operator+=(int numadded) {
		if (numadded > 0) {
			num_onhand += numadded;
		}
		return num_onhand;
	}
	//Helper function to output the object recieved.
	//
	std::ostream& operator<<(std::ostream& os, const iGood& g) {
		g.write(os, true);
		return os;
	}

	//The helper function to store data from the standard input device 
	//to a object.
	std::istream& operator>>(std::istream& is, iGood& g) {
		g.read(is);
		return is;
	}
	//Add the total cost of current object to 
	//double recieved.
	double operator+=(double& pcost, const iGood& g) {
		pcost += g.total_cost();
		return pcost;
	}


}


