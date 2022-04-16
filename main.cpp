//main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer: Miao Sun
//Purpose : inventory program for a bike shop
//Class : CS222
//Assignment number 10.
//

#include"Header.h"


int main()
{
    //Debug use
    Date new_date(1, 2, 5);
    cout << new_date << endl;

    Date date1("2020-05-15");
    cout << date1 << endl;

    Date date2("08/24/2019");
    cout << date2 << endl;

    string moname = "123";
    string newname = "asdfasdf";
    Movie mymovie(moname, 2020, 8, 28);
    Movie mymovie2(newname, 2019, 7, 21);
    /*cout << mymovie.getRating() << endl;*/
    ++mymovie;
    /*cout << mymovie.getRating() << endl;*/

    shared_ptr<Movie> myMovie_ptr = make_shared<Movie>(mymovie);
    shared_ptr<Movie> myMovie2_ptr = make_shared<Movie>(mymovie2);

    Cinema myCinema;

    list<int> show;
    show.push_back(1700);
    show.push_back(1800);
    show.push_back(1900);
    show.push_back(1500);

    list<int> show2;
    show2.push_back(1703);
    show2.push_back(1803);
    show2.push_back(1903);
    show2.push_back(1503);

    myCinema.addMovie(myMovie_ptr,show);

    cout << myCinema;

    myCinema.addMovie(myMovie_ptr, show2);
    myCinema.addMovie(myMovie2_ptr, show);

    cout << myCinema;

    myCinema.printShowTimes(myMovie_ptr);

    myCinema.movieRunningAt(myMovie_ptr, show);

    cout << *myCinema[1];



    return 0;
}


