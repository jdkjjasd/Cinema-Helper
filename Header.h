//Header.h: header file for all  
//Programmer: Miao Sun
//Purpose : inventory program for a bike shop
//Class : CS222
//Assignment number 10.
//
#ifndef _HEADER_H_
#define _HEADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<map>
#include<cstring>
#include<iterator>
#include<memory>
#include<set>;

using namespace std;


class Date
{
public:
	Date(int, int, int);
	Date(string);
	//бн.
	// other as appropriate
	bool operator==(Date&);
	friend ostream& operator<<(ostream&, const Date&);
private:
	int day, month, year;
};



class Movie
{
public:
	Movie(string& name, int yyyy, int mm, int dd);
	const Date& getReleaseDate();
	/*int getRating();*/
	// other?
	bool operator== (Movie&);
	Movie& operator++();
	friend ostream& operator<<(ostream&, Movie&);
	friend ostream& operator<<(ostream&, const Movie&);
private:
	Movie();
	const Date releaseDate;
	string name;
	int rating;
};



class Cinema
{
public:
	Cinema();
	Cinema(Cinema&);
	void addMovie(shared_ptr<Movie>, const list<int>&);
	friend ostream& operator<<(ostream&, Cinema&);
	shared_ptr<Movie> operator[](int);
	void movieRunningAt(shared_ptr<Movie>, list<int>&);
	void printShowTimes(const shared_ptr<Movie>);
private:
	list<shared_ptr<Movie>> running_movies;
	map<const shared_ptr<Movie>, list<int> > movie_times;
	map<int, const shared_ptr<Movie>> add_movie_map;
	int index=0;
};



#endif//_HEADER_H_