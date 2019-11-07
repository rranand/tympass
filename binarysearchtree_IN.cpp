#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left=NULL;
        node* right=NULL;
};

class bst {
    public:
        node *root=new node();
        bst() {
            root=NULL;
        }
        
        node* pass() {
            return root;    
        }
        node* create();
        void insert();
        void display(node *);
        void deleten(node *cur,int);
        node* leastval(node *);
};

node* bst::create() {
    node *temp=create();
    cout << "Enter a number: ";
    cin >> temp->data;
    return temp;
}

void bst::insert() {
    node *temp=create();
    int flag=0;
    while (flag!=1) {
        if (root==NULL) {
            root=temp;
            flag=1;
        } else if (temp->data<=root->data) {
            root=root->left;
        } else {
            root=root->right;
        }
    }
}

void bst::display(node *cur) {
    if (cur==NULL) return;
    display(cur->left);
    cout << cur->data <<endl;
    display(cur->right);
}

node* bst::leastval(node *cur) {
    while (cur->left!=NULL) {
        cur=cur->left;
    }
    return cur;
}

/*void deleten(node *cur,int val) {
    if (cur==NULL) {
        return;
    } else if (val<cur->left) {
        cur->left=deleten(cur->left,val);
    } else if (val>cur->right) {
        cur->right=deleten(cur->right,val);
    } else {
        if (cur->left==NULL and cur->right==NULL) {
            delete cur;
            cur=NULL;
        } else if(cur->left==NULL) {
            node *temp=cur;
            cur=cur->right;
            delete temp;
        } else if(cur->right==NULL) {
            node *temp=cur;
            cur=cur->left;
            delete temp;
        } else {
            node *temp=leastval(cur->right);
            cur->data=temp->right;
            cur->right=deleten(cur->data,temp->data);
        }
    }
}*/

int main() {
    bst ll;
    ll.insert();
    ll.insert();
    ll.insert();
    ll.insert();
    ll.insert();
    ll.display(ll.pass());
    return 0;
}
