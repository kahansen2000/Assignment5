/*
Katherine Hansen
2326665
Assignment 5
CPSC350-01
*/
#include <iostream>
#include <string>

using namespace std;

template <class T>
class GenStack{
	public:
		GenStack(int size);
		~GenStack();
		
		void push(T toAdd);
		T pop();
		T peek();
		bool isFull();
		bool isEmpty();
		int getSize();
		void addSpace();
		
		int top;
		int maxSize;
		
		T *firstStack;
		T *tempStack;
};

//constructor
template <class T>
GenStack<T>::GenStack(int newSize) {
    firstStack = new T[newSize]; 
    maxSize= newSize;
    top = -1;
    tempStack = new T[maxSize]; 
}

//destructor
template <class T>
GenStack<T>::~GenStack() {
    delete []firstStack; //deallocating the memory from the arrays
    delete []tempStack; 
}

//adding a new object to the stack
template <class T>
void GenStack<T>::push(T toAdd){
	if(isFull()){
		addSpace();//makes sure stack has enough room to add something
	}
	firstStack[++top]=toAdd;
}

//removing and returning latest element
template <class T>
T GenStack<T>::pop(){
	if(isEmpty()){
		cout << "Error: the stack is empty" <<endl;
		return 0;
	}
	else{
		return firstStack[top--];
	}
}

template <class T>
T GenStack<T>::peek(){
	if(isEmpty()){
		cout << "Error: the stack is empty." <<endl;
		return 0;
	}
	else{
		return firstStack[top];
	}
}
//check to see if stack is full
template <class T>
bool GenStack<T>::isFull(){
	if(top==maxSize-1)
		return true;
	return false;
}
//check to see if stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
	if(top==-1)
		return true;
	return false;
}
//adds space to stack as stack fills
template <class T>
void GenStack<T>::addSpace() {
    tempStack = new T[maxSize];

    for (int i = top; i > -1; --i) {
        tempStack[i] = firstStack[i];
    }

    maxSize += 1;
    firstStack = new T[maxSize];

    for (int i = top; i > -1; --i) {
        firstStack[i] = tempStack[i];
    }
}
