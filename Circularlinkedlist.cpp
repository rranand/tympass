#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next=NULL;
};

class queue {
    public:
        node *rear= new node();
        node *front= new node();
        queue() {
            rear=NULL;
            front=NULL;
        }
        
        node* create();
        void enqueue();
        void dequeue();
        void display();
        
};

node* queue::create() {
    int num;
    node *cur;
    cout << "Enter a number: ";
    cin >> num;
    cur->data=num;
    return cur;
}

void queue::enqueue() {
    node *cur=create();
    node *temp=rear;
    if (rear==NULL && front==NULL) {
        front=rear=cur;
    } else {
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=cur;
    }
}

void queue::dequeue() {
    front=rear->next;
}

void queue::display() {
    node *cur=front;
    while (front!=NULL) {
        cout << "Entered Number: " << front->data << endl;
        front=front->next;
    }
}

int main() {
    
    queue ll;
    ll.enqueue();
    ll.enqueue();
    ll.enqueue();
    ll.enqueue();
    ll.display();
    ll.dequeue();
    ll.dequeue();
    ll.display();
    return 0;
}
