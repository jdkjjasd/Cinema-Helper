//Date.cpp : This file contains the Date class function. 
//Programmer: Miao Sun
//Purpose : inventory program for a bike shop
//Class : CS222
//Assignment number 10.
//


#include "Header.h"
using namespace std;

//Constructor
Date::Date(int _year,int _month, int _day)
{
	day = _day;
	month = _month;
	year = _year;
}

//Constructor(EC)
Date::Date(string _input)
{
	string _split[3] = {};
	int _lenth = _input.length();
	int _counter = 0;

	//find split char
	for (int i = 0; i < _lenth; i++)
	{
		if ((_input[i] == '/' || _input[i] == '-')&&i!=0)
		{
			_counter++;
			//more than three part, input error
			if (_counter > 2)
			{
				exit(-1);
			}
		}
		else
		{
			_split[_counter] += _input[i];
		}
	}

	//conver string to int
	try
	{
		//find order
		if (stoi(_split[0]) > 1000)
		{
			year = stoi(_split[0]);
			month = stoi(_split[1]);
			day = stoi(_split[2]);
		}
		else
		{
			month = stoi(_split[0]);
			day = stoi(_split[1]);
			year = stoi(_split[2]);
		}

	}
	catch (const std::exception&)
	{
		cout << "input date error" << endl;
	}
}


//operator == override
bool Date::operator==(Date& _date)
{
	if (this->day == _date.day && this->month == _date.month && this->year == _date.year)
	{
		return true;
	}
	return false;

}

//operator << override
ostream& operator<<(ostream& _os, const Date& _date)
{
	_os << _date.month << "/" << _date.day << "/" << _date.year;
	return _os;
}