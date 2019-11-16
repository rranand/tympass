#include <iostream>
#define max 65536
using namespace std;

class Node
{
  public:
    int key;
    Node *left = NULL;
    Node *right = NULL;
    bool lthread, rthread;
};


class ThreadedBinarySearchTree
{

  public:

    Node *root = new Node();

    ThreadedBinarySearchTree()
    {
      root->right = root->left = root;
      root->lthread = true;
      root->key = max;
    }

    void makeEmpty();
    void insert(int);
    bool search(int);
    void Delete(int);
    void printTree();

};

void ThreadedBinarySearchTree::makeEmpty() {
  root->right = root->left = root;
  root->lthread = true;
  root->key = max;
}

void ThreadedBinarySearchTree::insert(int key) {
  Node *cur = root;
  for (;;)
  {
    if (cur->key < key)
    {
      if (cur->rthread)
        break;
      cur = cur->right;
    }
    else if (cur->key > key)
    {
      if (cur->lthread)
        break;
      cur = cur->left;
    }
    else
    {
      return;
    }
  }
  Node *temp = new Node();
  temp->key = key;
  temp->rthread = temp->lthread = true;
  if (cur->key < key)
  {
    /* insert to right side */
    temp->right = cur->right;
    temp->left = cur;
    cur->right = temp;
    cur->rthread = false;
  }
  else
  {
    temp->right = cur;
    temp->left = cur->left;
    cur->left = temp;
    cur->lthread = false;
  }
}

bool ThreadedBinarySearchTree::search(int key) {
  Node *temp = root->left;
  for (;;)
  {
    if (temp->key < key)
    {
      if (temp->rthread)
        return false;
      temp = temp->right;
    }
    else if (temp->key > key)
    {
      if (temp->lthread)
        return false;
      temp = temp->left;
    }
    else
    {
      return true;
    }
  }
}


void ThreadedBinarySearchTree::Delete(int key) {
  Node *dest = root->left, *p = root;
  for (;;)
  {
    if (dest->key < key)
    {
      if (dest->rthread) {
        return;
      }
      p = dest;
      dest = dest->right;
    } else if (dest->key > key) {
      if (dest->lthread) {
        return;
      }
      p = dest;
      dest = dest->left;
    } else {
      break;
    }
  }
  Node *target = dest;
  if (!dest->rthread && !dest->lthread) {
    p = dest;
    target = dest->left;
    while (!target->rthread) {
      p = target;
      target = target->right;
    }
    dest->key = target->key;
  }
  if (p->key >= target->key)
  {
    if (target->rthread && target->lthread)
    {
      p->left = target->left;
      p->lthread = true;
    }
    else if (target->rthread)
    {
      Node *largest = target->left;
      while (!largest->rthread)
      {
        largest = largest->right;
      }
      largest->right = p;
      p->left = target->left;
    }
    else
    {
      Node *smallest = target->right;
      while (!smallest->lthread)
      {
        smallest = smallest->left;
      }
      smallest->left = target->left;
      p->left = target->right;
    }
  }
  else
  {
    if (target->rthread && target->lthread)
    {
      p->right = target->right;
      p->rthread = true;
    }
    else if (target->rthread)
    {
      Node *largest = target->left;
      while (!largest->rthread)
      {
        largest = largest->right;
      }
      largest->right =  target->right;
      p->right = target->left;
    }
    else
    {
      Node *smallest = target->right;
      while (!smallest->lthread)
      {
        smallest = smallest->left;
      }
      smallest->left = p;
      p->right = target->right;
    }
  }
}

void ThreadedBinarySearchTree::printTree() {
  Node *tmp = root, *p;
  for (;;)
  {
    p = tmp;
    tmp = tmp->right;
    if (!p->rthread)
    {
      while (!tmp->lthread)
      {
        tmp = tmp->left;
      }
    }
    if (tmp == root)
      break;
    cout << tmp->key << "   ";
  }
  cout << endl;
}


int main()
{
  ThreadedBinarySearchTree tbst;
  char ch;
  int choice,val,n;
  do
  {
    cout << "\nThreadedBinarySearchTree Operations\n";
    cout << "1. Insert\n2. Delete\n3. Search\n4. Clear\nEnter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
      case 1 :
        cout << "Number of elements, you want to store: ";
        cout << n;
        for (int i=0;i<n;i++) {
            cout << "Enter integer element to insert: ";
            cin >> val;
            tbst.insert(val);
        }
        break;
      case 2 :
        cout << "Enter integer element to delete: ";
        cin >> val;
        tbst.Delete(val);
        break;
      case 3 :
        cout << "Enter integer element to search: ";
        cin >> val;
        if (tbst.search(val) == true)
          cout << "Element " << val << " found in the tree" << endl;
        else
          cout << "Element " << val << " not found in the tree" << endl;
        break;
      case 4 :
        cout << "\nTree Cleared\n";
        tbst.makeEmpty();
        break;
      default :
        cout << "Wrong Option \n ";
        break;
    }
    cout << "\nElements = ";
    tbst.printTree();
    cout << "\nDo you want to continue (Type y or n): ";
    cin >> ch;
  }
  while (ch == 'Y' || ch == 'y');
  return 0;
}
