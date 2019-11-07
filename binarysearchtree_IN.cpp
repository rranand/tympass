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
        
        node* create();
        void insert();
        void display(node *);
        void deleten(node *,int);
        node* leastval();
};

node* bst::create() {
    node *temp=create();
    cout << "Enter a number: ";
    cin >> temp->data;
    return temp;
}

void bst::insert() {
    node *temp=create();
    while (true) {
        if (root==NULL) {
            root=temp;
            break;
        } else if (val<=root->data) {
            root=root->left;
        } else {
            root=root->right;
        }
    }
}

void bst::display(node *cur) {
    if (cur==NULL) return;
    diplay(cur->left);
    cout << cur->data <<endl;
    display(cur->right);
}

node* bst::leastval() {
    node *cur=root;
    while (cur->left!=NULL) {
        cur=cur->left;
    }
    return cur;
}

void deleten(node *cur,int val) {
    if (cur==NULL) return;
    else if (val<cur->left) cur->left=deleten(cur->left,val);
    else if (val>cur->right) cur->right=deleten(cur->right,val);
    else {
        
    }
}
int main() {
    
}
    
