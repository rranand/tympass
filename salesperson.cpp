#include <iostream>
using namespace std;

class NTEL {
    public:
        char name[50];
        long int msidn;
        int recharge;
        int internet_browsing=0;
        int sim_vailidity[3];
        char working_state[20];
        
        void accept();
        void display();
};

void NTEL::accept() {
    cout<<"Enter Customer's Name: ";
    cin>> name;
    cout << "Enter mobile number: ";
    cin >> msidn;
    cout << "Enter last recharged amount: ";
    cin >> recharge;
    cout<< "Enter Sim validity's date: ";
    cin>> sim_vailidity[0];
    cout << "Enter Sim validity's month: ";
    cin >> sim_vailidity[1];
    cout << "Enter sim validity's year: ";
    cin >> sim_vailidity[2];
    cout << "Enter working area of region: ";
    cin >> working_state;
}

void NTEL::display() {
    cout << "Detail of mobile number: " << msidn << endl;
    if (recharge>=10) {
        internet_browsing=1;
        cout << "Your internet connection is active." << endl;
    }
    else {
        cout << "Balance is low, please recharge!!!" << endl;
    }
}

int main() {
    
    long int temp;
    cout << "Enter number of users: ";
    cin>> temp;
    NTEL user[temp];
    for (int i=0;i<temp;i++) {
        user[i].accept();
        cout << endl;
    }
    for (int i=0;i<temp;i++) {
        user[i].display();
        cout << endl;
    }
    return 0;
}
