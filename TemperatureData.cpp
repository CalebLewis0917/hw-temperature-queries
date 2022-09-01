/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
#include <iostream>
using namespace std;

TemperatureData::TemperatureData():
	id(""), year(-1), month(-1), temperature(-99.99)
{} //initialize everything

TemperatureData::TemperatureData(string id, int year, int month, double temperature): 
	id(id), year(year), month(month), temperature(temperature)
{} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	if(this->id < b.id){
		return true;
	}
	else if(this->id == b.id){
		if(this->year < b.year){
			return true;
		}
		else if(this->year == b.year){
			if(this->month < b.month){
				return true;
			}
		}
	}
	return false;
}

