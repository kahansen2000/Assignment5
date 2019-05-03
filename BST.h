/*
*Katherine Hansen
*2326665
*kahansen@chapman.edu
*CPSC350-01
*Assignment 5: Database
*/
#include <iostream>

using namespace std;

template <class T>
class TreeNode {
  public:
    int key;
    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T* d, int k);
     ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode() {
  key = -1;
  data = T();
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* d, int k) {
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {
  delete data;
  delete left;
  delete right;
}



//BST

template <class T>
class BST {
  public:
  	TreeNode<T> *root;
    int size;
  	
    BST();
    //copy constructor
    BST<T>(const BST<T>&);
    virtual ~BST();

    bool contains(int k);//done
    T* find(int k);//done
    void insert(TreeNode<T> *node);//done

    TreeNode<T>* getSuccessor(TreeNode<T> *d);//done
    bool remove(int k);//done

    void printTree(TreeNode<T> *node);//call root as node

    TreeNode<T>* getRoot();
    int getSize();
    bool isEmpty();
};
  

template <class T>
  BST<T>::BST() {
    root = NULL;
    size = 0;
  }
  
//the copy constructor will be used for rollback
template <class T>
BST<T>::BST(const BST<T> &copied){
	*this=copied;
}

  template <class T>
  BST<T>::~BST() {

  }
//returns true if tree contains element k, false otherwise
template <class T>
bool BST<T>::contains(int k) {
	if(root == NULL) {
      return false;
    }

    TreeNode<T> *curr = root;

    while(curr->key != k) {
      if(k < curr->key) {
        curr = curr->left;
      }
      else {
        curr = curr->right;
      }

      if(curr == NULL) {
        return false;
      }
    }
    return true;
}

//finds data given id and returns the data
template <class T>
  T* BST<T>::find(int k) {
    if(root == NULL) {
      return NULL;
    }

    if(contains(k)) {
      TreeNode<T> *curr = root;

      while(curr->key != k) {
        if(k < curr->key) {
          curr = curr->left;
        }
        else {
          curr = curr->right;
        }

        if(curr == NULL) {
          return NULL;
        }
      }
      return curr->data;
    }
    else {
      return NULL;
    }
}
//inserts a new node in the correct location  
template <class T>
void BST<T>::insert(TreeNode<T> *node) {
    if(root == NULL) {
      root = node;
    }
    else {
      TreeNode<T> *curr = root;
      TreeNode<T> *parent;

      while(true) {
        parent = curr;
        if(node->key < curr->key) {
          curr = curr->left;
          if(curr == NULL) {
              parent->left = node;
              break;
          }
        }
        else {
          if(node->key > curr->key) {
            curr = curr->right;
            if(curr == NULL) {
              parent->right = node;
              break;
            }
          }
        }
      }
    }
    size++;
  }
  
  
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d) {
	TreeNode<T>* parent = d;
	TreeNode<T>* successor = d;
	TreeNode<T>* curr = d->right;
	while(curr != NULL) {                             
		parent = successor;
		successor = curr;
		curr = curr->left;
	}
	
	if(successor != d->right) {
		parent->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}


template <class T>
bool BST<T>::remove(int k) {
    if(root == NULL) {
        return false;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(curr->key != k) {//finding the node we want to delete
      parent = curr;

      if(k < curr->key) {
        isLeft = true;
        curr = curr->left;
      }
      else {
        isLeft = false;
        curr = curr->right;
      }

      if(curr == NULL) {
        return false;
      }
    }
    
    //after we find the correct node, deletion depends on the number and type of children

    //When there are no children
    if(curr->left == NULL && curr->right == NULL) {
      if(curr == root) {
        root = NULL;
      }
      else if(isLeft) {
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }
    }
    
    
    //A single left child
    else if(curr->right == NULL) {
      	if(curr == root) {
        	root = curr->left;
      	}
      	else if(isLeft) {
       		parent->left = curr->left;
     	}
      	else {
        	parent->right = curr->right;
      	}
    }
    
    //A single right child
    else if(curr->left == NULL) {
    	if(curr == root) {
        	root = curr->right;
      	}
      	else if(isLeft) {
        	parent->left = curr->right;
      	}
     	else {
        	parent->right = curr->right;
      	}
    }
    
    //2 children
    else {
    	TreeNode<T> *successor = getSuccessor(curr);

    	if(curr == root) {
        	root = successor;
      	}
      	else if(isLeft) {
        	parent->left = successor;
      	}
      	else {
        	parent->right = successor;
      	}
      	successor->left = curr->left;
    }
    
	size--;
    return true;//we have deleted something, so we return true
}


template <class T>
void BST<T>::printTree(TreeNode<T> *node) {
	if(node == NULL) {
    	return;
    }
	//prints out id
    printRecursive(node->left);
    cout << node->key << endl;
    printRecursive(node->right);
}


template <class T>
TreeNode<T>* BST<T>::getRoot() {
	return root;
}

template <class T>
int BST<T>::getSize() {
	return size;
}

template <class T>
bool BST<T>::isEmpty() {
	return(size == 0);
}
