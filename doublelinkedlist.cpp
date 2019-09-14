#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next=NULL;
        node* prev=NULL;
};

class dll {
    public:
        node *head=new node();
        dll() {
            head=NULL;
        }
        
        node* create();
        void add();
        
        node* pass() {
            return head;
        }
};

node* dll::create() {
    
    int temp;
    cout << "Enter element: " ;
    cin >> temp;
    node *new_node=new node();
    new_node->data=temp;
    return new_node;
}

void dll::add() {
    node *temp=create();
    node *cur=head;
    if (head==NULL) {
        head=temp;
    } else {
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
}

int main() {
    dll ll;
    ll.add();
    ll.add();
    ll.add();
    node *cur=ll.pass();
    node *prev_node;
    int i=1;
    while (cur!=NULL) {
        prev_node=cur;
        cout << cur->data << endl;
        cur=cur->next;
        i++;
    }
    cout << "--------------------------------"<< i << endl;
    while (prev_node!=NULL) {
        cout << prev_node->data << endl;;
        prev_node=prev_node->prev;
    }
}
    
    
