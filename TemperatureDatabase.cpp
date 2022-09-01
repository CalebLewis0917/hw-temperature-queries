#include "TemperatureDatabase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {
	records = LinkedList();
}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {

	// TemperatureData Arguments
	string id;
	int year;
	int month;
	double temperature;
	bool isValid = true;
	//

	ifstream inFS;
	istringstream inSS;
	string str;
	inFS.open(filename);
	if(!inFS.is_open()){
		cout << "Error: Unable to open " << filename << endl;
	}
	getline(inFS,str);
	inSS.str(str);
	while(!inFS.eof() && !inFS.fail()){
		inSS >> id;
		inSS >> year;
		inSS >> month;
		inSS >> temperature;
		if(inSS.fail() || !inSS.eof()){
			cout << "Error: Other invalid input" << endl;
			isValid = false;
		}
		inSS.clear();
		if(year<1800 || year>2022){
			cout << "Error: Invalid year " << year << endl;
			isValid = false;
		}
		if(month<1 || month>12){
			cout << "Error: Invalid month " << month << endl;
			isValid = false;
		}
		if((temperature<-50 || temperature>50) && temperature!=-99.99){
			cout << "Error: Invalid temperature " << temperature << endl;
			isValid = false;
		}
		if(isValid){
			records.insert(id,year,month,temperature);
		}
		getline(inFS,str);
		inSS.str(str);
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
	string str = filename;
}
/*
int main(){
	TemperatureDatabase database;
	database.loadData("s050_TX-70s.dat");
	database.outputData("s050_TX-70s.dat");
}
*/
