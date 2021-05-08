// M. Bergeron
// E. Bouskila
// Person.cpp

#include "Person.h"
#include <string>

// implementaion of Person member functions

int Person::objectcounter = 100; // generates unique IDs

Person::Person() // default constructor
{
    id = ++objectcounter; // assign Id
    name = "";
}

Person::Person(string nom)
{
    id = ++objectcounter;
    name = nom;
}

Person::Person(const Person& other) // copy constructor
{
    id = other.id;
    name = other.name;
}

Person::~Person() // destructor
{
    // no memory to clean up
}

// setters and getters

int Person::get_id() const
{
    return id;
}

string Person::get_name() const
{
    return name;
}

void Person::set_name(string nom)
{
    name = nom;
}


string Person::show() // output a string with Person info clearly formatted
{
    string to_ret;
    to_ret += name;
    to_ret += "(";
    to_ret.append(to_string(id));
    to_ret += ")";
    return to_ret; // return a string showing the info of the object
}

bool operator==(Person& Left, Person& Right) // operator overloading to make it easier to compare objects
{
    // return true if the two Person objects have the same ID

    if(Left.get_id() == Right.get_id())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(Person& Left, Person& Right) // operator overloading to make it easier to compare objects
{
    // return true if IDs are not equal

    if(Left.get_id() == Right.get_id())
    {
        return false;
    }
    else
    {
        return true;
    }
}
