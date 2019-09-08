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
        
        void add(node *);
        void display();
        void del(int);
        void insert(int,node *);
        void getpos(int);
};


void sl::add(node *ele) {
    if (head==NULL) {
        head=ele;
    } else {
        node *cur=head;
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=ele;
    }
};

void sl::display() {
    node *cur=head;
    while (cur!=NULL) {
        cout << cur->data << endl;
        cur=cur->next;
    }
};

void sl::del(int k) {
    node *cur=head;
    node *prev=NULL;
    while (cur->data!=k) {
        prev=cur;
        cur=cur->next;
    };
    prev->next=cur->next;
    delete cur;
};

void sl::insert(int pos,node *ele) {
    node *cur=head;
    for (int i=1;i<pos-1;i++) {
        cur=cur->next;    
    }
    ele->next=cur->next;
    cur->next=ele;
}

void sl::getpos(int key) {
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
  node *head=new node();
  node *e1=new node();
  node *e2=new node();
  node *e3=new node();
  node *e4=new node();
  node *e5=new node();
  node *e6=new node();
  node *e7=new node();
  head->data=10;
  e1->data=20;
  e2->data=30;
  e3->data=40;
  e4->data=50;
  e5->data=60;
  e6->data=70;
  e7->data=70;
  
  sl ll;
  ll.add(head);
  ll.add(e1);
  ll.add(e2);
  ll.add(e3);
  ll.add(e4);
  ll.add(e5);
  ll.add(e6);
  
  ll.display();
  
  cout << "------------Removed Item-----------" << endl;
  ll.del(50);
  ll.display();
  
  cout << "------------Insert Item-----------" << endl;
  ll.insert(2,e7);
  ll.display();
  
  cout << "------------Get Position-----------" << endl;
  ll.getpos(40);


  return 0;
}
