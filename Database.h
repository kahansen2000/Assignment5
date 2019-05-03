/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"

using namespace std;

class Database {
	public:
    	BST<Student> masterStudent;
    	BST<Faculty> masterFaculty;
    	
    	GenStack<BST<Student> > *sRollbackStack;
    	GenStack<BST<Faculty> > *fRollbackStack;

    	Database();
    	~Database();
    	
    	TreeNode<Student>* getStudentRoot();
    	TreeNode<Faculty>* getFacultyRoot();

		bool again;
		
    	void printMenu();
    	void importFiles();
    	void exportFiles();
    	void outputStudent(TreeNode<Student> *stu, string fileName);
    	void outputFaculty(TreeNode<Faculty> *fac, string fileName);
    	
    	//the database options
    	void printAllStudents();
    	void printAllFaculty();
    	void printStudent();
    	void printFaculty();
    	void printAdvisor();
    	void printAdvisee();
    	void addStudent();
    	void deleteStudent();
    	void addFaculty();
    	void deleteFaculty();
    	void changeAdvisor();
    	void removeAdvisee();

    	void rollback();//does not work

    	void exit();

		//print tree functions
    	void printMasterStudent(TreeNode<Student> *stu);
    	void printMasterFaculty(TreeNode<Faculty> *fac);
};
