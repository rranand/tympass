#include <iostream>
using namespace std;

class student {
    public:
        char name[50];
        int id;
        int ssc;
        int hsc;
        int cet;
        int avg;
        student *next=NULL;
};

class Wrecord {
    public:
        student *head=new student();
        Wrecord() {
            head=NULL;
        }
        
        student* create();
        student* insert();
};


student* Wrecord::create() {
    student *cur=new student();
    char sname[50];
    int sid,sssc,shsc,scet;
	cout << "Enter Student's name: ";
    cin >> sname;
    cur->name=sname;
    cout << "Enter registeration id: ";
    cin >> sid;
    cur->id=sid;
    cout << "Enter Student's SSC marks: ";
    cin >> sssc;
    cur->ssc=sssc;
    cout << "Enter Student's HSC marks: ";
    cin >> shsc;
    cur->hsc=shsc;
    cout << "Enter Student's CET marks: ";
    cin >> scet;
    cur->cet=scet;
    cur->avg=(sssc+shsc+scet)/3;
	return cur;
};

student* Wrecord::insert() {
    student *temp=create();
    student *cur=head;
    if (head=NULL) {
        head=temp;
    } else {
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
    }
    return temp;
}
    
    

class department {
    public:
        student *Dstudent=new student();
        department() {
            Dstudent=NULL;
        }
        
        void add(student *);
        void search(int);
};

void department::add(student *temp) {
    student *cur=Dstudent;
    if (Dstudent==NULL) {
        Dstudent=temp;
    } else {
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
    }
}

void department::search(int id) {
    student *cur=Dstudent;
    while (cur!=NULL && cur->id!=id) {
            cur=cur->next;
    }
    cur=cur->next;
    if (cur->id!=id) {
        cout << "ID not found!!!";
    } else {
        cout << "Name of Student: " << cur->name << endl;
        cout << "Marks of HSC: " << cur->hsc << endl;
        cout << "Marks of SSC: " << cur->ssc << endl;
        cout << "Marks of CET: " << cur->cet << endl;
    };
};

int main() {
    
    department mech,etx,comp;
    Wrecord ll;
    int key,check,opt;
    
    do {
        cout << "\n1.Enter Student data\n2.Search\nEnter your choice: ";
        cin >>opt;
        switch (opt) {
            case 1:
                do {
                    cout << "Inserting Student list:\n";
                    student *cur=ll.insert();
                    
                    if (cur->avg>=90) {
                        cout << "Congratulation.. you got CS." << endl;
                        comp.add(cur);
                    } else if (cur->avg <90 and cur->avg >=80) {
                        cout << "Congratulation.. you got ETX." << endl;
                        etx.add(cur);
                    }
                    else if (cur->avg <80 and cur->avg >=70) {
                        cout << "Congratulation.. you got MECH." << endl;
                        mech.add(cur);
                    }
                    else {
                        cout << "You are not eligible for this college." << endl;
                    }
                    cout << "Want to insert more press 1\n Enter your choice: ";
                    cin >>check;
                } while (check==1);
                break;
            case 2:
                cout << "Enter registeration id: ";
                cin >> key;
                comp.search(key);
                mech.search(key);
                etx.search(key);
                break;
        }
        
        cout << "If you want to exit, enter 0 else any integer: ";
    	cin >> check;
    } while (check!=0);
    cout << "\nThank You!!!\n";
    return 0;
}
