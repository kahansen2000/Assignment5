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
void Database::importFiles(){
	cout <<"Importing files"<<endl;
	ifstream sFile;
	ifstream fFile;
	string input="";
	int sCount=0;
	int stepCount=1;
	
	//variables of students and faculty
	int sID = 0;
 	string sName = "";
 	string sLevel = "";
	string sMajor = "";
  	double gpa = 0.0;
  	int sAdvisorID = 0;
  	int fID = 0;
  	string fName = "";
  	string fLevel = "";
  	string department = "";
  	int adviseeID = 0;
  	
  	sFile.open("studentTable.txt");
//opening and importing student file
  if(sFile.is_open()) {
    try {
      getline(sFile, input);

      if(input != "") {
        sCount = atoi(input.c_str());
        sCount*=7;
      }
    }
    catch(exception e) {
      cout << "File is not in correct format, it cannot be read" << endl;
    }

    for(int i = 0; i < sCount; i++) {
      getline(sFile, input);

      switch(stepCount) {
        case 1: {
          if(input != "~") {//the space saver between elements of the tree
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 2: {
          try {
            sID = atoi(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 3: {
          sName = input;
          break;
        }
        case 4: {
          sLevel = input;
          break;
        }
        case 5: {
          sMajor = input;
        }
        case 6: {
          try {
            gpa = atof(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 7: {
          try {
            sAdvisorID = atoi(input.c_str());

            Student *stu = new Student(sID, sName, sLevel, sMajor, gpa, sAdvisorID);
            TreeNode<Student> *sNode = new TreeNode<Student>(stu, sID);
            masterStudent.insert(sNode);
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        default:
          break;
      }

      stepCount++;
      stepCount%=7; //makes cases repeat after each student
      
    }
    cout <<"Students Filled"<<endl;
  }
 
  else {
    cout << "Creating empty student tree" << endl;
  }
  sFile.close();
  
  //opening and importing faculty file
  stepCount=1;
  int fCount=0;
  fFile.open("facultyTable.txt");
  if(fFile.is_open()) {
    try {
      getline(fFile, input);

      if(input != "") {
        fCount = atoi(input.c_str());
        fCount*=7;
      }
    }
    catch(exception e) {
      cout << "File is not in correct format, it cannot be read" << endl;
    }

    for(int i = 0; i < fCount; i++) {
      getline(fFile, input);

      switch(stepCount) {
        case 1: {
          if(input != "~") {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 2: {
          try {
            fID = atoi(input.c_str());
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 3: {
          fName = input;
          break;
        }
        case 4: {
          fLevel = input;
          break;
        }
        case 5: {
          department = input;
        }
        case 6: {
          try {
            cout<<"";
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        case 7: {
          try {
            adviseeID = atoi(input.c_str());

            Faculty *fac = new Faculty(fID, fLevel, fName, department);
            TreeNode<Faculty> *fNode = new TreeNode<Faculty>(fac, fID);
            masterFaculty.insert(fNode);
          }
          catch(exception e) {
            cout << "File is not in correct format, it cannot be read" << endl;
          }
          break;
        }
        default:
          break;
      }

      stepCount++;
      stepCount%=7; //makes cases repeat after each student
      
    }
    cout <<"Faculty Filled"<<endl;
  }
 
  else {
    cout << "Creating empty faculty tree" << endl;
  }
	fFile.close();

	
}
void Database::exportFiles(){
	//saving student tree
	TreeNode<Student> *stu = masterStudent.getRoot();
	string fileName="studentTable.txt";
	outputStudent(stu, fileName);
	
	
	//saving faculty tree
	TreeNode<Faculty> *fac = masterFaculty.getRoot();
	fileName="facultyTable.txt";
	outputFaculty(fac, fileName);
}
void Database::outputStudent(TreeNode<Student> *stu, string fileName){
	ofstream out;
	
	//for student tree:
	out.open(fileName.c_str());
	if(out.is_open()){
		if(stu != NULL) {
   			out << "~" << endl;
    		out << stu->data->getID() << endl;
    		out << stu->data->getName() << endl;
    		out << stu->data->getLevel() << endl;
    		out << stu->data->getMajor() << endl;
    		out << stu->data->getGPA() << endl;
    		out << stu->data->getAdvisor() << endl;

    		if(stu->left != NULL) {
      			outputStudent(stu->left, fileName);
    		}

    		if(stu->right != NULL) {
      			outputStudent(stu->right, fileName);
    		}
  		}
	}
	out.close();
	cout <<"Students saved"<<endl;
}
void Database::outputFaculty(TreeNode<Faculty> *fac, string fileName){
	ofstream out;
	
	//for faculty tree:
	out.open(fileName.c_str());
	if(out.is_open()){
		if(fac != NULL) {
   			out << "~" << endl;
    		out << fac->data->getID() << endl;
    		out << fac->data->getName() << endl;
    		out << fac->data->getLevel() << endl;
    		out << fac->data->getDepartment() << endl;
    		out << " "<< endl;
    		out << fac->data->getAdviseeID() << endl;

    		if(fac->left != NULL) {
      			outputFaculty(fac->left, fileName);
    		}

    		if(fac->right != NULL) {
      			outputFaculty(fac->right, fileName);
    		}
  		}
	}
	out.close();
	cout <<"Faculty saved"<<endl;
}
void Database::printMenu(){
	importFiles();
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
	if(masterStudent.isEmpty()){
		cout<<"There are no students"<<endl;
	}
	else{
		int id;
		cout <<"What is the id of the student you'd like to print?"<<endl;
		cin >>id;
		masterStudent.find(id)->printStudent();
	}
}
void Database::printFaculty(){
	if(masterStudent.isEmpty()){
		cout<<"There are no faculty members"<<endl;
	}
	else{
		int id;
		cout <<"What is the id of the faculty member you'd like to print?"<<endl;
		cin >>id;
		masterFaculty.find(id)->printFaculty();
	}
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
				cout << "Advisor: ";
				cout << stu->getAdvisor();
				cout << endl;
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
			int count=0;
			if(masterFaculty.contains(facID)){
				Faculty *fac = masterFaculty.find(facID);
				for(int i = 0; i < fac->getSize(); ++i) {
            		if(fac->advisees[i] != -1) {
              			Student *stu=masterStudent.find(fac->advisees[i]);
              			int sID=stu->getID();
              			cout <<"ID: ";
              			cout <<sID;
              			cout <<", "<<endl;
              			count++;
            		}
          		}
          		if(count==0){
          			cout<< "Faculty has no advisees"<<endl;
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
	/*BST<Student> studentCopy=masterStudent;
	sRollbackStack->push(masterStudent);
	//fRollbackStack->push(new BST<Faculty>(masterFaculty));*/
	
	
	
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
	
	
	//sRollbackStack->push(new BST(masterStudent));
	//fRollbackStack->push(new BST(masterFaculty);
	
	
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
	
	//sRollbackStack->push(new BST(masterStudent));
	//fRollbackStack->push(new BST(masterFaculty);
	
	
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

	//sRollbackStack->push(new BST(masterStudent));
	//fRollbackStack->push(new BST(masterFaculty);


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
	
	
	//sRollbackStack->push(new BST(masterStudent));
	//fRollbackStack->push(new BST(masterFaculty);
	
	
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
			masterStudent.find(stuID)->setAdvisor(facID);//seg fault
    		masterFaculty.find(stuID)->addAdvisee(facID);//seg fault
		}
	}
}
void Database::removeAdvisee(){
	
	//sRollbackStack->push(new BST(masterStudent));
	//fRollbackStack->push(new BST(masterFaculty);
	
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
	cout <<"Rollback unavailable at this time"<<endl;
	//I couldn't get rollback to work
	
	/*if(!sRollbackStack->isEmpty()) {
		masterStudent = sRollbackStack->pop();
		masterFaculty = fRollbackStack->pop();
	}*/
}
void Database::exit(){
	exportFiles();
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
