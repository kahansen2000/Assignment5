/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include "Student.h"

using namespace std;

Student::Student() {

}

Student::Student(int sID, string sName, string sLevel, string sMajor, double sGPA, int sAdvisorID) {
  id = sID;
  name = sName;
  level = sLevel;
  major = sMajor;
  gpa = sGPA;
  advisorID = sAdvisorID;
}
Student::~Student() {

}

string Student::getMajor() {
  return major;
}

double Student::getGPA() {
  return gpa;
}

void Student::setAdvisor(int sAdvisorID) {
  advisorID = sAdvisorID;
}

int Student::getAdvisor() {
  return advisorID;
}

void Student::printStudent() {
  cout << "Name: " << name << ", ";
  cout << "ID: " << id << ", ";
  cout << "Major: " << major << ", ";
  cout << "GPA: " << gpa << ", ";
  cout << "Grade: " << level << ", ";
  cout << "Advisor: " << advisorID << endl;
}
