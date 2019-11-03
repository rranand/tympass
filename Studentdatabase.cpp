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
        void search(int);
};

void department::add(node *temp) {
    if (front==NULL) {
        front=temp;
    } else {
        while(front->next!=NULL) {
            front=front->next;
        }
        front->next=temp;
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

void department::search(int key) {
    int flag=0;
    node *cur=front;
    while(front!=NULL) {
        if (key==cur->regid) {
            flag=1;
            cout << "Name: " << cur->name << endl;
            cout << "Registeration id: " << cur->regid << endl;
            cout << "Marks of HSC: " << cur->hsc << endl;
            cout << "Marks of SSC: " << cur->ssc << endl;
            cout << "Marks of CET: " << cur->cet << endl;
        }
        cur=cur->next;
    }
    if (flag==0) {
        cout << "\nStudent not found!!!\n";
    }
}

int main() {
    department mech,etx,comp;
    student ll;
    int check,opt,avg,more;
    
    do {
        cout << "\n1.Enter Student data\n2.Display\n3.Search\nEnter your choice: ";
        cin >>opt;
        switch (opt) {
            case 1:
                do {
                    cout << "Inserting Student list:\n";
                    node *cur=ll.insert();
                    avg=((cur->hsc) + (cur->ssc) + (cur->cet)) /3;
                    if (avg>=90) {
                        comp.add(cur);
                        cout << "Congratulation.. you got CS." << endl;
                    } else if (avg <90 and avg >=80) {
                        etx.add(cur);
                        cout << "Congratulation.. you got ETX." << endl;
                    }
                    else if (avg <80 and avg >=70) {
                        mech.add(cur);
                        cout << "Congratulation.. you got MECH." << endl;
                    }
                    else {
                        cout << "You are not eligible for this college." << endl;
                    }
                    
                    cout << "\nInsert more data, press any integer other than 0, Enter ur choice: ";
                    cin >> more;
                } while(more!=0);
                break;
            case 2:
                cout << "\n1.Display Whole list\n2.Display Mech Students\n3.Display ETX students\n4.Display CS students\nEnter your choice: ";
                cin >> avg;
                switch (avg) {
                    case 1:
                        ll.display();
                        break;
                    case 2:
                        mech.display();
                        break;
                    case 3:
                        etx.display();
                        break;
                    case 4:
                        comp.display();
                        break;
                    default:
                        cout << "Entered option is invalid!!!";  
                }
                break;
            case 3:
                cout << "Enter registeration id: ";
                cin >> more;
                cout << "\n1.Search in Mech Students\n2.Search in ETX students\n3.Search in CS students\nEnter your choice: ";
                cin >> avg;
                switch (avg) {
                    case 1:
                        mech.search(more);
                        break;
                    case 2:
                        etx.search(more);
                        break;
                    case 3:
                        comp.search(more);
                        break;
                    default:
                        cout << "Entered option is invalid!!!";  
                }
                break;
            default:
                cout << "Entered option is invalid!!!";
        }
        
        cout << "If you want to exit, enter 0 else any integer: ";
    	cin >> check;
    } while (check!=0);
    cout << "\nThank You!!!\n";
    return 0;
}
