#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next=NULL;
};

class sl {
    public:
        node *head;
        sl() {
            head=NULL;
        }
        
        node* create();
        void add();
        void display();
        void del();
        void insert();
        void getpos();
};

node* sl::create() {
    
    int temp;
    cout << "Enter a number: " ;
    cin >> temp;
    node *new_node=new node();
    new_node->data=temp;
    new_node->next=NULL;
    return new_node;
};

void sl::add() {
    node *tempo=create();
    if (head==NULL) {
        head=tempo;
    } else {
        node *cur=head;
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=tempo;
    }
};

void sl::display() {
    node *cur=head;
    while (cur!=NULL) {
        cout << "Elements in node: " << cur->data << endl;
        cur=cur->next;
    }
};

void sl::del() {
    node *cur=head;
    node *prev=NULL;
    int k;
    cout << "Enter value which you want to delete: ";
    cin >> k;
    while (cur->data!=k) {
        prev=cur;
        cur=cur->next;
    };
    prev->next=cur->next;
    delete cur;
};

void sl::insert() {
    node *tempo=create();
    int pos;
    cout << "Enter positon where you want to insert: ";
    cin >> pos;
    node *cur=head;
    for (int i=1;i<pos-1;i++) {
        cur=cur->next;    
    }
    tempo->next=cur->next;
    cur->next=tempo;
}

void sl::getpos() {
    int key;
    cout << "Get position of node: ";
    cin >> key;
    int i=0;
    node *cur=head;
    while (cur!=NULL) {
        i++;
        if (cur->data==key) {
            cout << key << " is found at " << i << " position." << endl;
            break;
        }
        cur=cur->next;
    } 
}

int main()
{
  sl ll;
  ll.add();
  ll.add();
  ll.add();
  ll.add();
  ll.add();
  ll.add();
  ll.add();
  
  ll.display();

  cout << "------------Removed Item-----------" << endl;
  ll.del();
  ll.display();
  
  cout << "------------Insert Item-----------" << endl;
  ll.insert();
  ll.display();
  
  cout << "------------Get Position-----------" << endl;
  ll.getpos();


  return 0;
}
