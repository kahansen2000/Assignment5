/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include <iostream>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty : public Person {
	public:
    	string department;

   		int adviseeCount;
    	int maxSize;//max number of students the faculty member can have

    	int *advisees;

    	Faculty();
    	Faculty(int fID, string fLevel, string fName, string fDepartment);
    	~Faculty();

    	void printFaculty();
    	void printAllAdvisees();
    	

    	string getDepartment();

    	int getAdviseeID();
    	void addAdvisee(int adviseeID);
    	bool removeAdvisee(int adviseeID);

    	int getSize();


	//redefining boolean operators
	//done by comparing their ids
    bool operator == (const Faculty &fac) {
      return(this->id == fac.id);
    }
    bool operator != (const Faculty &fac) {
      return(this->id != fac.id);
    }
    bool operator <= (const Faculty &fac) {
      return(this->id <= fac.id);
    }
    bool operator >= (const Faculty &fac) {
      return(this->id >= fac.id);
    }
    bool operator < (const Faculty &fac) {
      return(this->id < fac.id);
    }
    bool operator > (const Faculty &fac) {
      return(this->id > fac.id);
    }

};
