/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person {
	public:
    	string major;
    	double gpa;
    	int advisorID;

    	Student();
    	~Student();
    	Student(int ID_, string name_, string level_, string major_, double gpa_, int advisorID_);

    	string getMajor();
    	double getGPA();

    	void setAdvisor(int advisorID_);
    	int getAdvisor();

    	void printStudent();

    bool operator == (const Student &stu) {
    	return(this->id == stu.id);
    }
    bool operator != (const Student &stu) {
    	return(this->id != stu.id);
    }
    bool operator <= (const Student &stu) {
      	return(this->id <= stu.id);
    }
    bool operator >= (const Student &stu) {
      	return(this->id >= stu.id);
    }
    bool operator < (const Student &stu) {
      	return(this->id < stu.id);
    }
    bool operator > (const Student &stu) {
      	return(this->id > stu.id);
    }
};
