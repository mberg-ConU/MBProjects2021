// M. Bergeron
// E. Bouskila
// Person.h

#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

// definition of class Person (vertices of the graph)

class Person // will be vertices of the graph
{
protected:
    int id;
    static int objectcounter; //counting the number of object used to gerenate new unique id
    string name;
public:
    Person(); // default constructor
    Person(string); // constructor
    Person(const Person&); // copy constructor
    ~Person(); // destructor
    // getters and setters
    int get_id() const;
    string get_name() const;
    void set_name(string);
    string show(); // returns a string with Person info
    friend bool operator==(Person& Left, Person& Right); // overloaded equality operator
    friend bool operator!=(Person& Left, Person& Right); // overloaded inequality operator
};

#endif // PERSON_H
