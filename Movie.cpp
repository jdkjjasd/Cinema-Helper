//Movie.cpp : This file contains the Movie class function. 
//Programmer: Miao Sun
//Purpose : inventory program for a bike shop
//Class : CS222
//Assignment number 10.
//

#include "Header.h"

//Constructor
Movie::Movie(string& name, int yyyy, int mm, int dd):
	releaseDate(yyyy,mm,dd)
{
	this->name = name;
	rating = 0;
}

//get date
const Date& Movie::getReleaseDate()
{
	return releaseDate;
}

//override operator ++ as increase rating
Movie& Movie::operator++()
{
	this->rating++;
	return *this;
}


//int Movie::getRating()
//{
//	return rating;
//}

//override operator == as compare rating
bool Movie::operator== (Movie& _movie)
{
	return this->rating == _movie.rating ? true : false;
}

//override operator == to output movie info
ostream& operator<<(ostream& _os, Movie& _movie)
{
	_os << "Movie Name: " << _movie.name << " release date: " << _movie.releaseDate;
	return _os;
}

//override operator == to output movie info
ostream& operator<<(ostream& _os, const Movie& _movie)
{

	return _os;
}