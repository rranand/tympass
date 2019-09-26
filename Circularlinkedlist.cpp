#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next=NULL;
};

class queue {
    public:
        node *head= new node();
        queue() {
            head=NULL;
        }
        
        node* create();
        void enqueue();
        void dequeue();
        void display();
        
};
