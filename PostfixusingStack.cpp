#include <iostream>
#include <string>
using namespace std;

class stack {
    int top;
    public:
        stack() {
            top=-1;
        }
        int a[50];
        void push(int);
        int pop();
        int check();
};

void stack::push(int x) {
    if (check()==1) {
        cout << "Stack is full" << endl;
    } else {
        top++;
        a[top]=x;
    }
}

int stack::pop() {
    if (check()==0) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return a[top--];
    
};

int stack::check() {
    if (top==49) {
        return 1;
    } else if (top==-1) {
        return 0;
    }
    return -1;
};

int main()  
{
   
    stack s;
    int a,b,c;
    string st;
    cout << "Enter expression: " ;
    getline(cin,st);
   
    for(int i=0;i<st.length();i++) {

        char temp=st.at(i);
        int ascii=int(temp);
        
        if (ascii >=48 and ascii <=57) {
            s.push(ascii-48);
        }

        if (st.at(i)=='+' or st.at(i)=='-' or st.at(i)=='*' or st.at(i)=='/') {

        a=s.pop();
        b=s.pop();

        if (st.at(i)=='+') {
            c=a+b;
        }

        else if (st.at(i)=='-') {
            c=a-b;
        }

        else if (st.at(i)=='*') {
            c=a*b;
        }

        else if (st.at(i)=='/') {
            c=a/b;
        }
        else {
            cout << "Invalid operator!!!" << endl;
        }
    
        s.push(c);
        }
    }
   
    cout << "Value of expression is " << s.pop() << endl;
    return 0;
}
