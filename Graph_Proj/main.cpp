// M. Bergeron
// E. Bouskila
// main.cpp

#include <iostream>
#include "Person.h"
#include "Friendship.h"
#include "Graph.h"
#include "UGraph.h"
#include "DGraph.h"
#include <limits>


// in class demo

using namespace std;


int main()
{
    // 1
    cout << "PART 1 \nIt will be shown: A graph can be empty with no vertex or edge." << endl;
    cout << "A graph with 5 max edges and 5 max friendships will be created, but will not be populated with edges or vertices." << endl;
    UGraph a_graph(5, 5);
    cout << "When we use the display functions to show the edges and vertices of this graph, it shows (should be nothing): ";
    a_graph.display();
    cout << endl;

    // 2
    cout << "\n\nPART 2 \nIt will be shown: A graph can be added in vertices and edges." << endl;
    cout << "To show this, an undirected graph will be created and populated with vertices and edges." << endl;
    cout << "If each add function successfully adds Vertex or Edge objects, it returns true." << endl;
    UGraph u_graph(10, 10);
    Person b1{ "Sue" }, b2{ "Carmelo" }, b3("Damian"), b4("Oliver"), b5{"Patrick"};
    Friendship b_e1(10, b1, b3);
    Friendship b_e2(30, b3, b2);
    Friendship b_e3(5, b1, b5);
    cout << "Add 5 Vertex objects: (return value of calls of addVertex will be shown here) " << endl;
    cout << u_graph.addVertex(b1) << endl;
    cout << u_graph.addVertex(b2) << endl;
    cout << u_graph.addVertex(b3) << endl;
    cout << u_graph.addVertex(b4) << endl;
    cout << u_graph.addVertex(b5) << endl;

    cout << " Add 3 Edge objects: (return value of calls of addEdge will be shown here)" << endl;
    cout << u_graph.addEdge(b_e1) << endl;
    cout << u_graph.addEdge(b_e2) << endl;
    cout << u_graph.addEdge(b_e3) << endl;
    cout << "Now, all vertices and edges will be printed so we can see they have been added properly" << endl;
    u_graph.showVerts();
    u_graph.showEdges();

    // 3
    cout << "\n\nPART 3 \nIt will be shown: A graph can be either a directed graph or an undirected graph." << endl;
    cout << "A directed graph will be created, and we already have created an undirected graph. The edges will be printed for each." << endl;
    DGraph d_graph(15, 15);
    cout << "Enter a name for the last element of the directed graph: " << endl;
    string userinput;
    getline(cin, userinput);
    Person d1{ "Dirk" }, d2{ "Tony" }, d3{ "Joel" }, d4{ "Hakeem" }, d5{ userinput };
    Friendship fd1{ 18, d1, d2 }, fd2{ 4, d4, d5 }, fd3(11, d3, d2);
    d_graph.addVertex(d1);
    d_graph.addVertex(d2);
    d_graph.addVertex(d3);
    d_graph.addVertex(d4);
    d_graph.addVertex(d5);
    d_graph.addEdge(fd1);
    d_graph.addEdge(fd2);
    d_graph.addEdge(fd3);

    cout << "Printing the edges of undirected graph: " << endl;
    u_graph.showEdges();
    cout << "Printing the edges of directed graph: " << endl;
    d_graph.showEdges();


    // 4
    cout << "\n\nPART 4\nIt has already been shown that: A vertex of a graph can contain values." << endl;
    cout << "In our case, the values are strings, because they are names of people in a social network." << endl;
    cout << "For example, show the value of a Vertex object:" << endl;
    cout << d1.get_name() << endl;


    // 5
    cout << "\n\nPART 5 \nIt will be shown: A graph can be displayed by listing all the possible paths, each linking vertices." << endl;
    cout << "Show all possible paths of directed graph created earlier:" << endl;
    d_graph.display();
    cout << "\nShow all possible paths of (second) undirected graph created earlier:" << endl;
    u_graph.display();

    // 6
    cout << "\n\nPART 6 \nIt will be shown: A graph can be queried by given a starting vertex, listing the path this vertex leads." << endl;
    cout << "We will print the paths that contain the vertex " << b1.show() << " in the UGraph created earlier:" << endl;
    cout << "We are dealing with the graph containing Damian, Sue, Carmelo, etc." << endl;
    vector<bool>vis2(u_graph.get_number_of_people(), false);
    u_graph.call_UGraph_display(b1, vis2);


    // 7
    cout << "\n\nPART 7 \nIt will be shown: A graph can be queried by given an edge, if this edge exists in the graph." << endl;
    cout << "We will use the undirected graph created earlier (containing Damian, Sue, Carmelo, etc.)" << endl;
    cout << "When we check if an edge of weight 2 exists from Sue to Damian, the function outputs:" << endl;
    u_graph.display(b_e1);
    cout << "\nNow, when we check if an edge of weight 100 exists from Damian to Oliver, the function outputs:" << endl;
    Friendship testfs(100, b3, b4);
    u_graph.display(testfs);

    // 8
    cout << "\n\nPART 8 \nIt will be shown: A graph can be queried if a value is contained by any of its vertex." << endl;
    cout << "We will simply use the undirected graph created earlier in part 2 (containing Damian, Sue, Carmelo, etc.) as a reminder its edges will be outputted:" << endl;
    u_graph.showEdges();
    cout << "Now input a string and the search function will print the paths including that vertex if any of the vertices have this value" << endl;
    string to_search;
    getline(cin, to_search);
    cout << "Searching for this value, the function prints \n";
    u_graph.query_by_value(to_search);

    //OPTION FROM THE USER


    cout << "\n----------------------------------------------" << endl;
    cout << "MENU TO ALLOW THE USER TO TEST FUNCTIONS: " << endl;
    cout << "Make use of: " << endl;
    cout << "Original dgraph: contains Dirk, Tony, etc." << endl;
    cout << "Original ugraph: contains Damian, Sue, etc." << endl;
    cout << "1. Show all paths of dgraph" << endl;
    cout << "2. Show all paths of ugraph" << endl;
    cout << "3. Display the edges and vertices of the dgraph" << endl;
    cout << "4. Display the edges and vertices of the ugraph" << endl;
    cout << "5. Search ugraph for vertex by value and output paths." << endl;
    cout << "6. Add vertex to dgraph." << endl;
    cout << "7. Add vertex to ugraph." << endl;
    cout << "8. Add edge to dgraph." << endl;
    cout << "9. Add edge to ugraph." << endl;
    cout << "------------------------------------------------" << endl;

    int choice;
    cout << "Please enter the number of the option you would like to test (press -1 to exit): ";
    cin >> choice;
    while (choice != -1)
    {

        cin.clear();
        if (choice == 1)
        {
            d_graph.display();
        }
        if (choice == 2)
        {
            u_graph.display();
        }
        if (choice == 3)
        {
            cout << "DGraph edges:" << endl;
            d_graph.showEdges();
            cout << endl;
            cout << "DGraph vertices:" << endl;
            d_graph.showVerts();
        }
        if (choice == 4)
        {
            cout << "UGraph edges:" << endl;
            u_graph.showEdges();
            cout << endl;
            cout << "UGraph vertices:" << endl;
            u_graph.showVerts();
        }
        if(choice == 5)
        {
            cin.ignore();
            cout << "Enter string to search for in graph:" << endl;
            string getInput;
            getline(cin, getInput);
            u_graph.query_by_value(getInput);
        }
        if(choice == 6)
        {
            cin.ignore();
            try{
            cout << "\nEnter name of Person to add: " << endl;
            string name;
            getline(cin, name);
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(string::npos != name.find_first_of("0123456789"));
                throw "Name should not contain numbers.";
            }
            Person toAdd{name};
            d_graph.addVertex(toAdd);
            }
            catch(const char* message)
            {
                cin.clear();
                cout << message << endl;
            }
        }
        if(choice == 7)
        {
            cin.ignore();
            try{
            cout << "\nEnter name of Person to add: " << endl;
            string name;
            getline(cin, name);
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(string::npos != name.find_first_of("0123456789"));
                throw "Name should not contain numbers.";
            }
            Person toAdd{name};
            u_graph.addVertex(toAdd);
            }
            catch(const char* message)
            {
                cin.clear();
                cout << message << endl;
            }
        }
        if(choice == 8)
        {
            cin.ignore();
            try{
            string name1, name2;
            int yrs;
            cout << "\nEnter name of first person in friendship." << endl;
            getline(cin, name1);
            Person fr1 = d_graph.return_Person(name1);
            cout << "\nEnter name of second person in friendship." << endl;
            getline(cin, name2);
            Person fr2 = d_graph.return_Person(name2);
            cout << "Enter years friends (weight of edge)" << endl;
            cin >> yrs;
            if(cin.fail())
            {
                cin.clear();
                throw "Years must be of type int.";
            }
            Friendship toAdd(yrs, fr1, fr2);
            d_graph.addEdge(toAdd);
            }
            catch(const char* message)
            {
                cin.clear();
                cout << message << endl;
            }
        }
        if(choice == 9)
        {
            cin.ignore();
            try{
            string name1, name2;
            int yrs;
            cout << "\nEnter name of first person in friendship." << endl;
            getline(cin, name1);
            Person fr1 = u_graph.return_Person(name1);
            cout << "\nEnter name of second person in friendship." << endl;
            getline(cin, name2);
            Person fr2 = u_graph.return_Person(name2);
            cout << "Enter years friends (weight of edge)" << endl;
            cin >> yrs;
            if(cin.fail())
            {

                throw "Years must be of type int.";
            }
            Friendship toAdd(yrs, fr1, fr2);
            u_graph.addEdge(toAdd);
            }
            catch(const char* message)
            {
                cout << message << endl;
            }
        }
    cout << endl << "Please enter the number of the option you would like to test (press -1 to exit): ";
    cin >> choice;



}

return 0;}

