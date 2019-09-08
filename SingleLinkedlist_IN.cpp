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
        
        void add(node *ele);
        void display();
};


void sl::add(node *ele) {
    if (head==NULL) {
        head=ele;
    } else {
        node *cur=head;
        while (cur->next!=NULL) {
            cout << cur->data << endl;
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

int main()
{
  node *head=new node();
  node *e1=new node();
  node *e2=new node();
  node *e3=new node();
  head->data=10;
  e1->data=20;
  e2->data=30;
  e3->data=40;
  
  sl ll;
  ll.add(head);
  ll.add(e1);
  ll.add(e2);
  ll.add(e3);
  
  ll.display();
  
  return 0;
}
