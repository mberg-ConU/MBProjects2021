// M. Bergeron
// E. Bouskila
// Friendship.h

#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H
#include "Person.h"

// definition of class Friendship

class Friendship // will be edges of graph (connect people)
{
protected:
    Person* friend1, * friend2; // pointers to corresponding Person objects
    int yrs_friends; // will be weight of edge
public:
    Friendship(); // default constructor
    Friendship(int, Person&, Person&); // takes people and years friends as arguments
    Friendship(const Friendship&); // copy constructor
    // setters and getters
    int get_years() const;
    Person* get_friend1() const;
    Person* get_friend2() const;
    void set_years(int);
    void set_friend1(Person&);
    void set_friend2(Person&);
    friend bool operator==(Friendship& Left, Friendship& Right); // overloaded equality operator
};

#endif // FRIENDSHIP_H
