#include <iostream>
#define max 65536
using namespace std;

/*
Creating nodes for storing data in ThreadedBinarySearchTree
*/

class Node
{
  public:
    int key;
    Node *left = NULL;
    Node *right = NULL;
    bool lthread, rthread;
};

/*
To perform several functions in ThreadedBinarySearchTree class created such as insert,delete,search, etc along with with instructor to initialize parent nodes as well as child nodes 
*/

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

    void reset();
    void insert(int);
    bool search(int);
    void Delete(int);
    void printTree();

};

/*
To delete all the values in the tree reset function is created
*/

void ThreadedBinarySearchTree::reset() {
  root->right = root->left = root;
  root->lthread = true;
  root->key = max;
}

/*
Firstly key value will checked it is less or more than root value until it found for lthread or rthread is True or it will exit from funtion.
If lthread or rthread is found true then, a new node is created to store the value of key and it will check for key is less or more from root's key 
if less store in left side (if condition satisfies ) else will store in the right node.
*/
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

/*
It almost work as a insert function only the difference is it will not store any value, only search the value if found return True else False.
Here we initialize temp from root->left because as we know in threaded binary search tree not any node is found empty because it has reference of successor node
*/

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

/*
At first it will search for the key to be deleted if found, found node will store in the 'p' node.
Afterwards, if the lthread and rthread is found false it means none of any threaded node is store
*/

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

/*
To print elements in tree, print function is called
In this it will check the lthread and rthread is false or not if found false it break the loop and return to the main function.
*/

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

/*Below this statement, an object is created and different function is performed by using switch statement*/
int main()
{
  ThreadedBinarySearchTree ll;
  char ch;
  int choice,val,n;
  do
  {
    cout << "1. Insert\n2. Delete\n3. Search\n4. Clear\nEnter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
      case 1 :
        cout << "Number of elements, you want to store: ";
        cin >> n;
        for (int i=0;i<n;i++) {
            cout << "Enter integer element to insert: ";
            cin >> val;
            ll.insert(val);
        }
        break;
      case 2 :
        cout << "Enter integer element to delete: ";
        cin >> val;
        ll.Delete(val);
        break;
      case 3 :
        cout << "Enter integer element to search: ";
        cin >> val;
        if (ll.search(val) == true)
          cout << "Element " << val << " found in the tree" << endl;
        else
          cout << "Element " << val << " not found in the tree" << endl;
        break;
      case 4 :
        cout << "\nTree Cleared\n";
        ll.reset();
        break;
      default :
        cout << "Wrong Option \n ";
        break;
    }
    cout << "\nElements = ";
    ll.printTree();
    cout << "\nDo you want to continue (Type y or n): ";
    cin >> ch;
  }
  while (ch == 'Y' || ch == 'y');
  return 0;
}


/*
OUTPUT:-

1. Insert
2. Delete
3. Search
4. Clear
Enter Your Choice: 1
Number of elements, you want to store: 5
Enter integer element to insert: 1
Enter integer element to insert: 9
Enter integer element to insert: 5
Enter integer element to insert: 2
Enter integer element to insert: 6

Elements = 1   2   5   6   9   

Do you want to continue (Type y or n): y
1. Insert
2. Delete
3. Search
4. Clear
Enter Your Choice: 3
Enter integer element to search: 5
Element 5 found in the tree

Elements = 1   2   5   6   9   

Do you want to continue (Type y or n): y
1. Insert
2. Delete
3. Search
4. Clear
Enter Your Choice: 2
Enter integer element to delete: 2

Elements = 1   5   6   9   

Do you want to continue (Type y or n): y
1. Insert
2. Delete
3. Search
4. Clear
Enter Your Choice: 4

Tree Cleared

Elements = 

Do you want to continue (Type y or n): n
*/
