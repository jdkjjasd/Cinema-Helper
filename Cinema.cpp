//Cinema.cpp : This file contains the Cinema class function. 
//Programmer: Miao Sun
//Purpose : inventory program for a bike shop
//Class : CS222
//Assignment number 10.
//

#include "Header.h"

//Constructor
Cinema::Cinema() {}

//copy Constructor
Cinema::Cinema(Cinema& _cinema)
{
	this->movie_times = _cinema.movie_times;
	this->running_movies = _cinema.running_movies;
}

//add movie and show_time to movie_times
void Cinema::addMovie(shared_ptr<Movie> _movie_ptr, const list<int>& _show_time)
{
	//copy _show_time
	list<int> _time= _show_time;
	_time.sort();
	//check first time add this movie
	if (movie_times.count(_movie_ptr) == 0)
	{
		movie_times[_movie_ptr] = _time;

		//and add to map for index serch
		add_movie_map.insert(pair<int, shared_ptr<Movie>>(index, _movie_ptr));
		index++;
	}
	else
	{
		//repeat movie, only add time and delete repeat show time
		cout << "Repeat Movie, only add time" << endl;
		movie_times[_movie_ptr].merge(_time);
		movie_times[_movie_ptr].unique();
	}
}

//override operator<< to output all movies and movie_times info
ostream& operator<<(ostream& _os, Cinema& _cinema)
{
	map<const shared_ptr<Movie>, list<int> >::iterator _map_it = _cinema.movie_times.begin();
	list<int>::iterator _list_it;

	//loop output
	while (_map_it != _cinema.movie_times.end())
	{
		_os << *(_map_it->first) << endl;
		_os << "Show Time: " << endl;


		for (_list_it = _map_it->second.begin(); _list_it != _map_it->second.end(); _list_it++)
		{
			_os << *_list_it << endl;
		}

		_map_it++;
	}


	return _os;
}

//print show times for given movie
void Cinema::printShowTimes(const shared_ptr<Movie> _movie_ptr)
{
	map<const shared_ptr<Movie>, list<int> >::iterator _map_it = movie_times.find(_movie_ptr);
	list<int>::iterator _list_it;
	if (_map_it != movie_times.end())
	{
		cout << *_map_it->first<< endl;
		cout << "show time:" << endl;
		for (_list_it = _map_it->second.begin(); _list_it != _map_it->second.end(); _list_it++)
		{
			cout << *_list_it << endl;
		}
	}
	else
	{
		cout << "movie not found" << endl;
	}
}

//find the show time intersection of two list<int>(EC)
void Cinema::movieRunningAt(shared_ptr<Movie> _movie_ptr, list<int>& _target_list)
{

	if (movie_times.count(_movie_ptr) == 0)
	{
		cout << "movie not found" << endl;
		return;
	}
	
	//output
	list<int> _inter_list;

	//use set to test intersection
	set<int> _test_set;


	list<int>::iterator _list_it;

	//add first list to set
	for (_list_it = _target_list.begin(); _list_it != _target_list.end(); _list_it++)
	{
		_test_set.insert(*_list_it);
	}
	
	//add second list to set and check intersection and add into new list
	for (_list_it = movie_times[_movie_ptr].begin(); _list_it != movie_times[_movie_ptr].end(); _list_it++)
	{
		if (_test_set.insert(*_list_it).second == false)
		{
			_inter_list.push_back(*_list_it);
		}
	}

	if (_inter_list.empty())
	{
		cout << "no intersection" << endl;
		return;
	}
	else
	{
		cout << "Movie Running At: " << endl;
	}

	for (_list_it = _inter_list.begin(); _list_it != _inter_list.end(); _list_it++)
	{
		cout << *_list_it << endl;
	}

	_target_list = _inter_list;
}


//use red-black tree(Map serch) to return movie at index (EC)
//O(log n)
shared_ptr<Movie> Cinema::operator[](int _index)
{
	map<int, const shared_ptr<Movie>>::iterator _map_it;

	_map_it = add_movie_map.find(_index);

	if (_map_it != add_movie_map.end())
	{
		return _map_it->second;
	}
	else
	{
		cout << "index not found" << endl;
		exit(-1);
	}

}