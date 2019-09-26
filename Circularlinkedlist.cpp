#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next=NULL;
};

class queue {
    public:
        node *rear;
        node *front;
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
    node *cur=new node();
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
    if (rear==NULL) {
        cout << "Queue is empty\n";
    } else {
        front=front->next;
    }
}

void queue::display() {
    while (front!=NULL) {
        cout << "Entered Number: " << front->data << endl;
        front=front->next;
    }
}

int main() {
    
    queue ll;
    int i,count;
    do {
        
        cout << "\nEnter 1 for Adding Elements\nEnter 2 for Removing Elements\nEnter 3 for displaying Elements\n\n";
        cout << "Enter your choice: ";
        cin >> i;
        cout << "\n";
        
        switch (i) {
            case 1:
                cout << "Adding elements in queue: \n";
                cout << "Enter number of elements to be stored: ";
                cin >> count;
                for (int j=0;j<count;j++) {
                    ll.enqueue();
                }
                break;
                
            case 2:
                cout << "Removing elements in queue: \n";
                cout << "Enter number of elements to be deleted: ";
                cin >> count;
                for (int j=0;j<count;j++) {
                    ll.dequeue();
                }
                break;
                
            case 3:
                cout << "Displaying elements:\n";
                ll.display();
                break;
                
            default:
                cout << "Invalid Option choosed.....Try again!!!\n\n";
        }
        
            cout << "\nIf you want to exit, Press '0' else any to remain in the loop: ";
            cin >> i;
            
    } while (i!=0);
    
    return 0;
}


/*OUTPUT:


Enter 1 for Adding Elements
Enter 2 for Removing Elements
Enter 3 for displaying Elements

Enter your choice: 1

Adding elements in queue: 
Enter number of elements to be stored: 4
Enter a number: 1
Enter a number: 2
Enter a number: 3
Enter a number: 4

If you want to exit, Press '0' else any to remain in the loop: 1

Enter 1 for Adding Elements
Enter 2 for Removing Elements
Enter 3 for displaying Elements

Enter your choice: 2

Removing elements in queue: 
Enter number of elements to be deleted: 2

If you want to exit, Press '0' else any to remain in the loop: 1

Enter 1 for Adding Elements
Enter 2 for Removing Elements
Enter 3 for displaying Elements

Enter your choice: 3

Displaying elements:
Entered Number: 3
Entered Number: 4

If you want to exit, Press '0' else any to remain in the loop: 0

*/
