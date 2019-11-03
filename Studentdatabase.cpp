#include<iostream>
using namespace std;

class node {
    public:
        char name[50];
        int regid;
        int ssc;
        int hsc;
        int cet;
        node* next=NULL;
};

class student {
    public:
        node *head=new node();
        student() {
            head=NULL;
        }
        
        node* create();
        node* insert();
        void display();
        node* pass();
};

node* student::create() {
    node *temp=new node();
    cout << "Enter Student's Name: ";
    cin >> temp->name;
    cout << "Enter registeration id: ";
    cin >> temp->regid;
    cout << "Enter Student's SSC marks: ";
    cin >> temp->ssc;
    cout << "Enter Student's HSC marks: ";
    cin >> temp->hsc;
    cout << "Enter Student's CET marks: ";
    cin >> temp->cet;
    return temp;
}

node* student::insert() {

    node *temp=create();
    if (head==NULL) {
        head=temp;
    } else {
        node *cur=head;
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
    }
    return temp;
}

void student::display() {
    node *cur=head;
    while (cur!=NULL) {
        cout << "\n";
        cout << "Name: " << cur->name << endl;
        cout << "Registeration id: " << cur->regid << endl;
        cout << "Marks of HSC: " << cur->hsc << endl;
        cout << "Marks of SSC: " << cur->ssc << endl;
        cout << "Marks of CET: " << cur->cet << endl;
        cur=cur->next;
    }
}

class department {
    public:
        node *front=new node();
        department() {
            front=NULL;
        }
        
        void add(node *);
        void display();
};

void department::add(node *temp) {
    if (front==NULL) {
        front=temp;
    } else {
        node *cur=front;
        while(cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
    }
}

void department::display() {
    node *cur=front;
    while(cur!=NULL) {
        cout << "\n";
        cout << "Name: " << cur->name << endl;
        cout << "Registeration id: " << cur->regid << endl;
        cout << "Marks of HSC: " << cur->hsc << endl;
        cout << "Marks of SSC: " << cur->ssc << endl;
        cout << "Marks of CET: " << cur->cet << endl;
        cur=cur->next;
    }
}

int main() {
    department mech,etx,comp;
    student ll;
    int key,check,opt,avg,more;
    
    do {
        cout << "\n1.Enter Student data\n2.Search\nEnter your choice: ";
        cin >>opt;
        switch (opt) {
            case 1:
                do {
                    cout << "Inserting Student list:\n";
                    node *cur=ll.insert();
                    avg=((cur->hsc) + (cur->ssc) + (cur->cet)) /3;
                    if (avg>=90) {
                        cout << "Congratulation.. you got CS." << endl;
                        comp.add(cur);
                    } else if (avg <90 and avg >=80) {
                        cout << "Congratulation.. you got ETX." << endl;
                        etx.add(cur);
                    }
                    else if (avg <80 and avg >=70) {
                        cout << "Congratulation.. you got MECH." << endl;
                        mech.add(cur);
                    }
                    else {
                        cout << "You are not eligible for this college." << endl;
                    }
                    
                    cout << "\nInsert more data, press any integer other than 0, Enter ur choice: ";
                    cin >> more;
                } while(more!=0);
                break;
            case 2:
                ll.display();
                cout << "\nDisplaying Mech students:";
                mech.display();
                cout << "\nDisplaying entc students:";
                etx.display();
                cout << "\nDisplaying Comp students:";
                comp.display();
                /*cout << "Enter registeration id: ";
                cin >> key;
                comp.search(key);
                mech.search(key);
                etx.search(key);*/
                break;
        }
        
        cout << "If you want to exit, enter 0 else any integer: ";
    	cin >> check;
    } while (check!=0);
    cout << "\nThank You!!!\n";
    return 0;
}
