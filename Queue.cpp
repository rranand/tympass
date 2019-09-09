#include <iostream>
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
        void check();
        void display();
};

void queue::enqueue() {
    if (check()==5) {
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
    if (check()==4) {
        cout << "Queue is empty" << endl;
    } else {
        front++;
        arr[front]=0;
    }
};

void queue::check() {
    if (rear==max_size) {
        return 5;
    else if (front==-1) {
        return 4;
    }
    return;
};

void queue::display() {
    for (int i=front;i <=rear;i++) {
        cout << "Entered value: " << arr[i] << endl;
    }
};

int main()
{
    queue sl;
    sl.enqueue();
    sl.enqueue();
    sl.enqueue();
    sl.enqueue();
    sl.display();
    return 0;
}
