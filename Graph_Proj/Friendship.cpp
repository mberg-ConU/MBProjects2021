// M. Bergeron
// E. Bouskila
// Friendship.cpp

#include "Friendship.h"

// implementaion of Friendship member functions


Friendship::Friendship() // default constructor
{
    Person* f1, * f2;
    f1 = nullptr;
    f2 = nullptr;
    friend1 = f1;
    friend2 = f2;
    yrs_friends = 0;
}

Friendship::Friendship(int yrs, Person& f1, Person& f2) // constructor
{
    yrs_friends = yrs;
    friend1 = &f1;
    friend2 = &f2;
}


Friendship::Friendship(const Friendship& other) // copy constructor
{
    yrs_friends = other.yrs_friends;
    friend1 = other.friend1;
    friend2 = other.friend2;
}

// setters and getters

int Friendship::get_years() const
{
    return yrs_friends;
}

Person* Friendship::get_friend1() const
{
    return friend1;
}

Person* Friendship::get_friend2() const
{
    return friend2;
}

void Friendship::set_years(int yrs)
{
    yrs_friends = yrs;
}

void Friendship::set_friend1(Person& f1)
{
    friend1 = &f1;
}

void Friendship::set_friend2(Person& f2)
{
    friend2 = &f2;
}

