/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include "Person.h"

using namespace std;

Person::Person() {

}

Person::~Person() {

}

void Person::setID(int idNum) {
  id = idNum;
}

int Person::getID() {
  return id;
}

string Person::getName() {
  return name;
}

void Person::setName(string newName) {
  name = newName;
}

void Person::setLevel(string newLevel) {
  level = newLevel;
}

string Person::getLevel() {
  return level;
}
