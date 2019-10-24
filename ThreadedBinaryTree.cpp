#include <iostream>

using namespace std;

class node {
    public:
        int data;
        bool lT,rT;
        node* left=NULL,right=NULL;
};

class ThreadBinaryTree {
    public:
        node *root=new node();
        ThreadBinaryTree() {
            root=NULL;
        }
        
        node* create();
        void insert();
        void delete();
        void search();
        void display(node*);
};
