#include <iostream>
#include <string>
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
  int count;
  string check;
  do {
      cout << "Enter 1 for Adding Elements\nEnter 2 for Displaying Elements\nEnter 3 for Deleting Elements\nEnter 4 for Inserting Elements\nEnter 5 for get position of Element\n";
      cout << "Enter your choice: ";
      cin >> count;
      switch (count) {
        case 1:
            cout << "Adding Elements in list: " << endl;
            cout << "Enter number of Elements to be entered: ";
            cin >> count;
            for(int i=0;i<count;i++) {
                ll.add();
            }
            break;
        case 2:
            cout << "Display Elements in list: " << endl;
            ll.display();
            break; 
        case 3:
            cout << "Deleting Elements in list: " << endl;
            cout << "Number of Elements to be Deleted in list: ";
            cin >> count;
            for(int i=0;i<count;i++) {
                ll.del();
            }
            break; 
        case 4:
            cout << "Inserting Elements in list: " << endl;
            cout << "Number of Elements to be inserted in list: ";
            cin >> count;
            for(int i=0;i<count;i++) {
                ll.insert();
            }
            break;
        case 5:
            cout << "Get position of Elements in list: " << endl;
            ll.getpos();
            break;
        default:
            cout << "Invalid Choice!!! \nTry Again!!!" << endl;
      }
      
      cout << "If you want to exit enter N: ";
      cin >> check; 
      
      
  } while (check!="N");
  
  return 0;
}
