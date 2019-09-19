#include <iostream>
#include <string>
using namespace std;
#define cust_size 100

class queue {
	public:
		int rear;
		int front;
		int cust[cust_size];
		string name[cust_size];	
		int price[cust_size];
		string cake[cust_size];
		queue() {
			
			rear=-1;
			front=-1;
		};
		
		int check();
		void enqueue();
		void dequeue();
		void display();
};

int queue::check() {
	
	if (rear==-1) {
		return 4;
	} else if (rear==cust_size) {
		return 5;
	}
	
	return 1;
}

void queue::enqueue() {
	if (check()==5) {
		
		cout << "Queue is full." << endl;
	} else {
		string c_name;
		int temp;
		rear++;
		cout << "Enter customer number: " ;
		cin >> temp;
		cust[rear]=temp;
		cout << "Enter customer name: ";
		cin >> c_name;
		name[rear]=c_name;
		cout << "Enter cake price: ";
		cin >> temp;
		price[rear]=temp;
		cout << "Enter cake name: ";
		cin >> c_name;
		cake[rear]=c_name;
	}
}

void queue::dequeue() {
	
	if (check()==4) {
		
		cout << "Queue is empty." << endl;
	} 
	
	cout << "order cancellation not allowed!!!" << endl;
	
}

void queue::display() {
	
	if (check()==4) {
		cout << "Queue is empty." << endl;
	} else {
		
		for (int i=front+1;i<=rear;i++) {
			cout << "Entered number: " << cust[i] << endl;
			cout << "Customer name: " << name[i] << endl;
			cout << "Cake price: " << price[i] << endl;
			cout << "Cake name: " << cake[i] << endl;			
		}
	}
}

int main() 
{

	queue list;
	int opt,count;
	string cake_type[4];
	cake_type[0]="Chocolate";
	cake_type[1]="Vanilla";
	cake_type[2]="Pineapple";
	cake_type[3]="strawberry";
	do {
		
		cout << "1 for adding element in queue \n2 for deleting element in queue \n3 for display element in queue \nEnter your choice: ";
		cin >> opt;
		switch (opt) {
			
			case 1:
				cout << "Adding element in queue:" << endl;
				cout << "Enter number of elements to be entered: " ;
				cin >> count;
				for (int i=1;i<=count ;i++) {
					list.enqueue();
				}
				break;
			
			case 2:
				cout << "Deleting element in queue:" << endl;
				cout << "Enter number of elements to be deleted: ";
				cin >> count ;
				for (int i=1;i<=count ;i++) {
					list.dequeue();
				}
				break;
			case 3:
				cout << "Display elements in queue:" << endl;
				list.display();
				break;
			default:
				cout << "Enter valid option.....Try Again!!!" << endl;
				
		}
		
		cout << "\n\n\n";
		cout << "If you want to exit enter 4 else any num: ";
		cin >> opt;
		
	} while (opt!=4);
	
	return 0;
}
