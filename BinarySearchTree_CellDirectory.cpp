  
#include<iostream>                                              //Importing input-output library
#include<string.h>                                              //Importing string library
using namespace std;                                            //Importing standard functions from input-output library

class node {                                                    //Defining class
	public:                                                     //Access Specifier
    	char number[11];                                        //Declaring a variable
    	char name[30];                                          //Declaring a variable
    	node* left=NULL;                                        //Creating a null object
    	node* right=NULL;                                       //Creating a null object
};

class tree {                                                    //Creating a class
	public:                                                     //Access specifier
    	node *root=new node();                                  //Creating an object
    	tree() {                                                //Constructor
        	root=NULL;                                          //Storing null in object
    	}
   	 
    	node* create();                                         //Creating a function to create object which returns object
    	void insert();                                          //Creating a function to insert elements
    	void display(node*);                                    //Creating a function to display elements having a parameter which takes object
    	void del();                                             //Creating a function to delete elements
    	void search();                                          //Creating a function to search instance
    	void min();                                             //Creating a function to find the minimum elements
   	 
    	node* pass() {                                         //Creating a function to return first object i.e. root
        	return root;                                       //Returing root
    	};
};

node* tree::create() {                                          //Declaring an inclass function using scope resolution outside the class
	node *temp=new node();										//Creating a new node
	cout << "Enter Name: ";										//printing
	cin >> temp->name;											//Storing user input in object's variable called name
	cout << "Enter mobile number: ";							//printing
	cin >> temp->number;										//Storing user input in object's variable
	return temp;												//Returing object
}

void tree::insert() {											//Declaring an inclass function using scope resolution outside the class
	node *temp=create();										//Creating an object with required inputs from the user
	node *cur=root;												//Assigning root node in cur node
	if (root==NULL) {											//Checking if root is null or empty
    	root=temp;												//if null then, storing temp node in root else
	} else {
    	while (temp!=NULL) {									//Checking for the null nodes in all objects
        	if (strcmp(temp->name,cur->name)<0) {				//comparing string and checking if it less than zero if less
            	if (root->left==NULL) {							//Checking for if root object has empty left node if found
                	root->left=temp;							//Storing temp in the left node of temp object
                	temp=NULL;									//Stroing null in the temp
            	} else {										//if above condition is not satsified
                	root=root->left;   							//Storing left node in the root from the root object
            	}
        	} else {
            	if (root->right==NULL) {						//Checking for if root object has empty right node if found
                	root->right=temp;							//Storing temp in the right node of temp object
                	temp=NULL;									//Stroing null in the temp
            	} else {
                	root=root->right;	    					//Storing left node in the root from the root object
            	}
        	}
    	}
	}
}

/*

In below function, we will display all elements stored in the root here we will pass a pointer node here
Firstly, Checking if the node is null or not if null, then run the below statements.
Calling the display function recursively for the left nodes to print left node afterwards it will print the stored elements and similarly it will do for right nodes

*/
void tree::display(node* cur) {
	if (cur!=NULL) {
    	display(cur->left);
    	cout << "Name: " << cur->name << endl;
    	cout << "Number: " << cur->number << endl;
    	display(cur->right);
	}
}

/*
In below function, we will search desire element stored in the root 
For counting its position variable 'c' is created and what to be search will store in the variable call 's_name'
Afterwards, storing the root in the pointer 'cur' variable
Now, searching for the key until the nodes reach to last one node by using while loop
In if condition we are comparing key with the names stored in the instances of the object if no difference is found, will print the position at which name was found as well as its name and number will exit from the loop
*/

void tree::search() {
	int c=0;
	char s_name[30];
	cout << "Enter name to searched: " << endl;
	cin>> s_name;
	node *cur=root;
	while (cur!=NULL) {
    	if (strcmp(s_name,cur->name)==0) {
        	cout << "Name found at this position: " << c << endl;
			cout << "Name: " << cur->name << endl;
			cout << "Number: " << cur->number << endl;
        	return;
    	} else if (strcmp(s_name,cur->name)<0) {
        	cur=cur->left;
    	} else {
        	cur=cur->right;
    	}   
    	c++;
	}
	cout << "Name not found in the directory" << endl;
}

/*
In below function, we will delete desire element stored in the root 
what to be deleted will store in the variable call 'dele' and get input from the user
Afterwards, storing the root in the pointer 'cur' variable
Now, searching for the key until the nodes reach to last one node by using while loop
It will compare for the element to be deleted with all names stored in the directory 
Afterwards, it will delete the object by storing it in the temp variable.
*/

void tree::del() {
	node *temp;
	char dele[30];
	cout << "Enter element to be deleted: ";
	cin >> dele;
	node *cur=root;
	while (cur!=NULL) {
    
    	if (cur==NULL) {
        	cout << "Empty node";
    	}  else if (strcmp(dele,cur->name)<0) {
        	cur=cur->left;
    	} else {
        	cur=cur->right;
    	}
   	 
    	if (cur->left==NULL && cur->right==NULL) {
        	temp=cur;
        	delete temp;
    	} else if (cur->left==NULL) {
        	temp=cur;
        	delete temp;
        	cur=cur->right;
        } else if (cur->right==NULL) {
        	temp=cur;
        	delete temp;
        	cur=cur->left;
    	}
	}
}

/*
In below function, we will find minimum of all element stored in the root 
storing the root in the pointer 'cur' variable
Now, transversing for the last key until the nodes reach to last one node by using while loop
Stroing the left node in the 'cur' variable as lower value store in the left
Finally print the stored values in the elements
*/

void tree::min() {
	node *cur=root;
	while (cur->left!=NULL) {
    	cur=cur->left;
	}
	cout << "Minimum: " << endl;
	cout << "Name: " << cur->name << endl;
	cout << "Number: " << cur->number << endl;
}    

/*
First, we created an object of tree and several variables to store different inputs
By using switch statement, we get input from the user what he or she want to do 
*/
int main() {
	tree ll;
	int m,opt,check;
	do {
    	cout << "\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Minimum\nEnter option: ";
    	cin >> opt;
    	switch(opt) {
        	case 1:
            	cout << "\nEnter Elements to be inserted: ";
            	cin >> m;
            	for (int i=0; i<m; i++ ) {
                	ll.insert();
            	}
            	break;
        	case 2:
            	ll.display(ll.pass());
            	break;
        	case 3:
            	cout << "\nEnter Elements to be deleted: ";
            	cin >> m;
            	for (int i=0; i<m; i++ ) {
                	ll.del();
            	}
            	break;
        	case 4:
            	ll.search();
            	break;
        	case 5:
            	ll.min();
            	break;
        	default:
            	cout << "\nEnter valid option!!!\n";
    	}
    	cout << "If you want to exit, enter 0 else any integer: ";
    	cin >> check;
	} while (check!=0);
	cout << "\nThank You!!!\n";
	return 0;    
}

/*
OUTPUT:
1.Insert
2.Display
3.Delete
4.Search
5.Minimum
Enter option: 1
Enter Elements to be inserted: 3
Enter Name: Rohit
Enter mobile number: 123
Enter Name: Anand
Enter mobile number: 456
Enter Name: Sonu
Enter mobile number: 789
If you want to exit, enter 0 else any integer: 1
1.Insert
2.Display
3.Delete
4.Search
5.Minimum
Enter option: 2
Name: Anand
Number: 456
Name: Rohit
Number: 123
Name: Sonu
Number: 789
If you want to exit, enter 0 else any integer: 0
Thank You!!!
*/
