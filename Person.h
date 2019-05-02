/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include <iostream>
#ifndef included
#define included

using namespace std;

class Person{
    public:
        int id;
        string name;
        string level;

        Person();
        ~Person();

        string getName();
        void setName(string newName);
        string getLevel();
        void setLevel(string newLevel);
        int getID();
        void setID(int value);

};

#endif
