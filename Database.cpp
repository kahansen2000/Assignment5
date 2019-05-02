/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include "Database.h"

Database::Database() {
	again=true;
	//sRollbackStack=new GenStack<BinarySearchTree<Student>*>(5);
	//fRollbackStack=new GenStack<BinarySearchTree<Student>*>(5);
}

Database::~Database() {

}
TreeNode<Student>* Database::getStudentRoot() {
  return masterStudent.getRoot();
}

TreeNode<Faculty>* Database::getFacultyRoot() {
  return masterFaculty.getRoot();
}

void Database::printMenu(){
	int choice;
	while(again){
		cout <<"Here are your options:"<<endl;
		cout << "1.  Print students in order of ID number" << endl;
    	cout << "2.  Print faculty in order of ID number" << endl;
    	cout << "3.  Print a student's information'" << endl;
    	cout << "4.  Print a faculty member's information'" << endl;
    	cout << "5.  Print a student's advisor's information''" << endl;
    	cout << "6.  Print a faculty member's advisees' information''" << endl;
    	cout << "7.  Add a new studnt" << endl;
    	cout << "8.  Delete a student" << endl;
    	cout << "9.  Add a faculty member" << endl;
    	cout << "10. Delete a faculty member" << endl;
    	cout << "11. Change a student's advisor'" << endl;
    	cout << "12. Remove an advisee from a faculty member" << endl;
    	cout << "13. Rollback" << endl;
    	cout << "14. Exit" << endl;
    	cout << "\nPlease Select a Menu Option: ";
    
   		cin>>choice;
    	while(choice>14||choice<1){
    		cout <<"Invalid. Choose a valid option"<<endl;
    		cin >>choice;
		}
	
		switch(choice) {
    		case 1:
        		printAllStudents();
        		break;
      		case 2:
        		printAllFaculty();
        		break;
      		case 3:
        		printStudent();
        		break;
      		case 4:
        		printFaculty();
        		break;
      		case 5:
        		printAdvisor();
        		break;
      		case 6:
        		printAdvisee();
        		break;
      		case 7:
        		addStudent();
        		break;
      		case 8:
        		deleteStudent();
        		break;
      		case 9:
        		addFaculty();
        		break;
      		case 10:
        		deleteFaculty();
        		break;
      		case 11:
        		changeAdvisor();
        		break;
      		case 12:
        		removeAdvisee();
        		break;
      		case 13:
        		rollback();
        		break;
      		case 14:
        		exit();
		}
	}
}

void Database::printAllStudents(){
	if(masterStudent.isEmpty()){
		cout<<"There are no students to display"<<endl;
	}
	else
		printMasterStudent(masterStudent.getRoot());
}
void Database::printAllFaculty(){
	if(masterFaculty.isEmpty()){
		cout<<"There are no faculty to display"<<endl;
	}
	else
		printMasterFaculty(masterFaculty.getRoot());
}
void Database::printStudent(){
	int id;
	cout <<"What is the id of the student you'd like to print?"<<endl;
	cin >>id;
	masterStudent.find(id)->printStudent();
}
void Database::printFaculty(){
	int id;
	cout <<"What is the id of the faculty member you'd like to print?"<<endl;
	cin >>id;
	masterFaculty.find(id)->printFaculty();
}
void Database::printAdvisor(){
	int stuID;
	if(masterStudent.isEmpty()){
		cout<<"There are no students"<<endl;
	}
	else{
		while(true){
			cout<<"What is the student's ID"<<endl;
			cin>>stuID;
			if(masterStudent.contains(stuID)){
				Student *stu =masterStudent.find(stuID);
				masterFaculty.find(stu->getAdvisor())->printFaculty();
				break;
			}
			else{
				cout<<"Invalid ID. Try again."<<endl;
			}
		}
	}
}
void Database::printAdvisee(){
	int facID;
	if(masterFaculty.isEmpty()){
		cout <<"There are no faculty";
	}
	else{
		while(true){
			cout<<"What is the faculty's ID?"<<endl;
			cin >>facID;
			if(masterFaculty.contains(facID)){
				Faculty *fac = masterFaculty.find(facID);
				for(int i = 0; i < fac->getSize(); ++i) {
            		if(fac->advisees[i] != -1) {
              			masterStudent.find(fac->advisees[i])->printStudent();
              			break;
            		}
            		else {
              			cout << "Faculty has no advisees" << endl;
            		}
          		}
         		break;
			}
			else{
				cout <<"Invalid ID, please try again"<<endl;
			}
		}
	}
	
}
void Database::addStudent(){
	
	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);
	
	
	
	int stuID;
	cout<<"Enter the student's ID"<<endl;
	cin >>stuID;
	
	string name;
	cout<<"Enter the student's name"<<endl;
	cin >>name;
	
	string level;
	cout<<"Enter the student's level"<<endl;
	cin >>level;
	
	string major;
	cout <<"Enter the student's major"<<endl;
	cin >>major;
	
	double gpa=-1;
	while(gpa<0||gpa>4){
		cout<<"Enter valid GPA"<<endl;
		cin >>gpa;
	}
	int facID;
	if(masterFaculty.isEmpty()){
		facID=-1;
	}
	if(facID!=-1){
		while(true){
			cout <<"Enter faculty ID"<<endl;
			cin>>facID;
			if(masterFaculty.contains(facID)){
				Faculty *fac = masterFaculty.find(facID);
          		fac->addAdvisee(stuID);
          		break;
			}
			else{
				cout <<"Invalid ID, try again";
			}
		}
	}
	Student *student = new Student(stuID, name, level, major, gpa, facID);
  	TreeNode<Student> *studentNode = new TreeNode<Student>(student, stuID);
 	masterStudent.insert(studentNode);
 	cout <<"Student added"<<endl;
}
void Database::deleteStudent(){
	
	
	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);
	
	
	int stuID;
	cout <<"Enter the ID of the student you want to delete"<<endl;
	cin >>stuID;
	if(!masterStudent.contains(stuID)){
		cout<<"That was an invalid ID"<<endl;
	}
	else{
		if(masterStudent.find(stuID)->getAdvisor() != -1) {
            masterFaculty.find(masterStudent.find(stuID)->getAdvisor())->removeAdvisee(stuID);
        }
		masterStudent.remove(stuID);
		cout <<"Student removed"<<endl;
	}
	
}
void Database::addFaculty(){
	
	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);
	
	
	int facID;
	cout<<"Enter the faculty's ID"<<endl;
	cin >>facID;
	
	string name;
	cout<<"Enter the faculty's name"<<endl;
	cin >>name;
	
	string level;
	cout<<"Enter the faculty's level"<<endl;
	cin >>level;
	
	string department;
  	cout << "Enter the faculty's department: ";
  	cin >> department;
  	
  	Faculty *faculty = new Faculty(facID, level, name, department);//new faculty starts out with no advisees
  	TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(faculty, facID);
  	masterFaculty.insert(facultyNode);
  	cout <<"Faculty added"<<endl;
}
void Database::deleteFaculty(){

	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);


	int facID;
	int newID;
	cout <<"Enter the ID of the faculty you want to delete"<<endl;
	cin >>facID;
	if(!masterFaculty.contains(facID)){
		cout<<"That was an invalid ID"<<endl;
	}
	else{
		if(masterFaculty.find(facID)->adviseeCount!= 0) {
			for(int i=0;i<masterFaculty.find(facID)->adviseeCount;i++){
            	masterStudent.find(masterFaculty.find(facID)->advisees[i])->setAdvisor(-1);
            }
        }
		masterFaculty.remove(facID);
		cout <<"Faculty removed"<<endl;
	}
}
void Database::changeAdvisor(){
	
	
	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);
	
	
	int stuID;
	int facID;
	cout <<"Enter the id of the student"<<endl;
	cin >>stuID;
	if(!masterStudent.contains(stuID)){
		cout <<"Invalid ID"<<endl;
	}
	else{
		cout <<"Enter the new faculty ID"<<endl;
		cin >>facID;
		if(!masterFaculty.contains(facID)){
			cout <<"Invalid ID"<<endl;
		}
		else{
			masterStudent.find(stuID)->setAdvisor(facID);
    		masterFaculty.find(stuID)->addAdvisee(facID);
		}
	}
}
void Database::removeAdvisee(){
	
	//sRollbackStack->push(masterStudent);
	//fRollbackStack->push(masterFaculty);
	
	int stuID;
	int facID;
	cout <<"Enter the ID of the faculty"<<endl;
	cin>>facID;
	if(!masterFaculty.contains(facID)){
		cout <<"Invalid ID"<<endl;
	}
	else{
		cout <<"Enter the ID of the student"<<endl;
		cin >>stuID;
		if(!masterStudent.contains(stuID)){
			cout <<"Invalid ID"<<endl;
		}
		else{
			for(int i=0;i<masterFaculty.find(facID)->adviseeCount;i++){
            	if(masterStudent.find(masterFaculty.find(facID)->advisees[i])->advisorID==facID)
					masterStudent.find(masterFaculty.find(facID)->advisees[i])->setAdvisor(-1);
            }
		}
	}
}
void Database::rollback(){
	//I couldn't get rollback to work
	
	/*if(!sRollbackStack->isEmpty()) {
		masterStudent = sRollbackStack->pop();
		masterFaculty = fRollbackStack->pop();
	}*/
}
void Database::exit(){
	again=false;
	cout <<"Thank you for using this database"<<endl;
}
void Database::printMasterStudent(TreeNode<Student> *stu){
	if(stu != NULL) {
   		if(stu->left != NULL) {
      	printMasterStudent(stu->left);
    	}
    
    	stu->data->printStudent();
    
    	if(stu->right != NULL) {
      		printMasterStudent(stu->right);
   		}
	}
}
