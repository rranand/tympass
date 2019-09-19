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
		cout << "Enter customer id: " ;
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

void queue::display() {
	
	if (check()==4) {
		cout << "Queue is empty." << endl;
	} else {
		
		for (int i=front+1;i<=rear;i++) {
			cout << "Customer id: " << cust[i] << endl;
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
	cake_type[0]="Chocolate - Rs 450";
	cake_type[1]="Vanilla - Rs 100";
	cake_type[2]="Pineapple - Rs 250";
	cake_type[3]="strawberry - Rs 350";
	do {
		
		
		cout << "1 for buying cake\n2 for Display customers details\nEnter your choice: ";
		cin >> opt;
		switch (opt) {
			
			case 1:
				cout << "Buying Cake:" << endl;
		        for (int i=0; i<4;i++) {
		            cout << "** " << cake_type[i] << " **" << endl;
		        }
				cout << "Enter number of customers to be entered: " ;
				cin >> count;
				for (int i=1;i<=count ;i++) {
					list.enqueue();
				}
				break;
			
			case 2:
				cout << "Display customers details:" << endl;
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
