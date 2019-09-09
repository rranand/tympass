#include <iostream>
#include <string>
using namespace std;

# define max_size 100 

class queue {
    public:
        int arr[max_size];
        int rear;
        int front;
        
        queue() {
            rear=-1;
            front=-1;
        }
        
        void enqueue();
        void dequeue();
        int check();
        void display();
        void getpos();
};

void queue::enqueue() {
    
    if (check()==4) {
        cout << "Queue is full" << endl;
    } else {
        int temp;
        cout << "Enter number to be entered: ";
        cin >> temp;
        rear++;
        arr[rear]=temp;
    }
};

void queue::dequeue() {
    
    if (check()==5) {
        cout << "Queue is empty" << endl;
    } else {
        front=front+1;
    }
};

int queue::check() {
    if (rear==-1) {
        return 5;
    }
    else if (rear==max_size) {
        return 4;
    }
    return 1;
};

void queue::display() {
    for (int i=front+1;i <=rear;i++) {
        cout << "Entered value: " << arr[i] << endl;
    }
};

void queue::getpos() {
    int temp;
    cout << "Enter number to be found: ";
    cin >> temp;
    for (int i=front+1;i <=rear;i++) {
        if (temp==arr[i]) {
            cout << temp << " is found at " << i << " position." << endl;
            break;
        }
    }
};

int main()
{
    queue ll;
    int count;
    string check;
    do {
      cout << "Enter 1 for Adding Elements\nEnter 2 for Displaying Elements\nEnter 3 for Deleting Elements\nEnter 4 for get position of Element\n";
      cout << "Enter your choice: ";
      cin >> count;
      switch (count) {
        case 1:
            cout << "Adding Elements in list: " << endl;
            cout << "Enter number of Elements to be entered: ";
            cin >> count;
            for(int i=0;i<count;i++) {
                ll.enqueue();
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
                ll.dequeue();
            }
            break;
        case 4:
            cout << "Get position of Elements in list: " << endl;
            ll.getpos();
            break;
        default:
            cout << "Invalid Choice!!! \nTry Again!!!" << endl;
      }
      
      cout << "\n";
      cout << "If you want to exit enter N: ";
      cin >> check; 
      cout << "\n\n\n";
      
  } while (check!="N");
  
  return 0;
}
