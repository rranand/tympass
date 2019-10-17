#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class node {
	public:
    	char number[11];
    	char name[30];
    	node* left=NULL;
    	node* right=NULL;
};

class tree {
	public:
    	node *root=new node();
    	tree() {
        	root=NULL;
    	}
   	 
    	node* create();
    	void insert();
    	void display(node*);
    	void del();
    	void search();
    	void min();
   	 
    	node* pass() {
        	return root;
    	};
};

node* tree::create() {
	node *temp=new node();
	cout << "Enter Name: ";
	cin >> temp->name;
	cout << "Enter mobile number: ";
	cin >> temp->number;
	return temp;
}

void tree::insert() {
	node *temp=create();
	node *cur=root;
	if (root==NULL) {
    	root=temp;
	} else {
    	while (temp!=NULL) {
        	if (strcmp(temp->name,cur->name)<0) {
            	if (root->left==NULL) {
                	root->left=temp;
                	temp=NULL;
            	} else {
                	root=root->left;   
            	}
        	} else {
            	if (root->right==NULL) {
                	root->right=temp;
                	temp=NULL;
            	} else {
                	root=root->right;	 
            	}
        	}
    	}
	}
}

void tree::display(node* cur) {
	if (cur!=NULL) {
    	display(cur->left);
    	cout << "Name: " << cur->name << endl;
    	cout << "Number: " << cur->number << endl;
    	display(cur->right);
	}   
}

void tree::search() {
	int c=0;
	char s_name[30];
	cout << "Enter name to searched: " << endl;
	cin>> s_name;
	node *cur=root;
	while (cur!=NULL) {
    	if (strcmp(s_name,cur->name)==0) {
        	cout << "Name found at this position: " << c << endl;
        	return;
    	} else if (strcmp(s_name,cur->name)<0) {
        	cur=cur->left;
    	} else {
        	cur=cur->right;
    	}   
	}
c++;
	cout << "Name not found in the directory" << endl;
}

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

void tree::min() {
	node *cur=root;
	while (cur!=NULL) {
    	cur=cur->left;
	}
	cout << "Minimum: " << endl;
	cout << "Name: " << cur->name << endl;
	cout << "Number: " << cur->number << endl;
}    

int main() {
	tree ll;
	int m,opt,check=1;
	while (check!=0) {
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
	}
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
