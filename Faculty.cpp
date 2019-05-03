/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include "Faculty.h"

using namespace std;

Faculty::Faculty() {
	name="";
}

Faculty::~Faculty() {
  
}

Faculty::Faculty(int fID, string fLevel, string fName, string fDepartment) {
  id = fID;
  name = fName;
  level = fLevel;
  department = fDepartment;

  advisees = new int[15];
  adviseeCount = 0;
  maxSize = 15;

  for(int i = 0; i < 15; i++) {
    advisees[i] = -1;
  }
}

string Faculty::getDepartment() {
  return department;
}

int Faculty::getAdviseeID() {
  return adviseeCount;
}

void Faculty::addAdvisee(int ID) {
  if(adviseeCount != maxSize) {
    int curr = 0;

    for(int i = 0; i < maxSize; i++) {
      if(advisees[i] == id) {//checks to see if advisee is already under this faculty member
        curr = maxSize;
      }
    }

    while(curr < maxSize) {
      if(advisees[curr] == -1) {//finds an open spot
        advisees[curr] = id;
        adviseeCount++;
        break;
      }

      curr++;
    }
  }
  else {
    if(adviseeCount == maxSize) {
      int *tempArr = new int[adviseeCount];

      for(int i = 0; i < adviseeCount; i++) {
        tempArr[i] = advisees[i];
      }

      advisees = new int[adviseeCount + 1];
      maxSize = adviseeCount + 1;

      for(int i = 0; i < adviseeCount; ++i) {
        advisees[i] = tempArr[i];
      }

      for(int i = adviseeCount; i < adviseeCount + 1; i++) {
        advisees[i] = -1;
      }

      advisees[++adviseeCount] = id;
    }
  }
}

bool Faculty::removeAdvisee(int adviseeID) {
  bool removed = false;

  for(int i = 0; i < maxSize; ++i) {//checks to see if advisee exists
    if(advisees[i] == adviseeID) {
      advisees[i] = -1;//resets the id location
      adviseeCount--;
      removed = true;
      cout <<"Removed"<<endl;
    }

    return removed;//if removed returns true, else returns false
  }
}

void Faculty::printFaculty() {
  cout << "Name:  ";
  cout << "";
 /* cout << "ID: " << id << ", ";
  cout << "Level: " << level << ", ";
  cout << "Department: " << department << ", ";
  cout << "Advisees: ";*/
  //printAllAdvisees();
}
//prints out the students of the faculty member
void Faculty::printAllAdvisees() {
  if(adviseeCount == 0) {
    cout << "None";
  }
  else {
    for(int i = 0; i < maxSize; ++i) {
      if(advisees[i] != -1) {
        //cout << advisees[i];//prints out the advisee id
        if(i < adviseeCount - 1) {
          cout  << ", ";
        }
      }
    }
  }
  cout << endl;
}

int Faculty::getSize() {
  return maxSize;
}
