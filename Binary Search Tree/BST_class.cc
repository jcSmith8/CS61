//Cooper Smith
//Data Structures Week 8

#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node(int n) : data(n), left(nullptr), right(nullptr) {};
};

void Insert(Node*& tree, int n) {
  if (tree == nullptr) {
    tree = new Node(n);
    return;
  } else if (tree->data == n) {
    return;
  } else if (tree->data < n) {
    Insert(tree->right, n);
    return;
  } else {
    Insert(tree->left, n);
    return;
  }
}

// Recursive function to delete largest value in binary tree
int RemoveLargest(Node*& tree) {
  if (tree->right == nullptr) {
    int d = tree->data;
    tree = tree->left;
    return d;
  } else {
    return RemoveLargest(tree->right);
  }
}

// Recursive function to delete smallest value in binary tree
int RemoveSmallest(Node*& tree) {
  if (tree->left == nullptr) {
    int d = tree->data;
    tree = tree->right;
    return d;
  } else {
    return RemoveSmallest(tree->left);
  }
}

// Removes node in binary tree with the value n (no repeat values in tree)
void Remove(Node*& tree, int n) {
  if (tree == nullptr) {
    return;
  } else if (tree->data == n) {
    if (tree->left == nullptr) {
      cout << "left is null" << endl;
      Node* todelete = tree;
      tree = tree->right;
      delete todelete;
    } else if (tree->right == nullptr) {
      cout << "right is null" << endl;
      Node* todelete = tree;
      tree = tree->left;
      delete todelete;
    } else {
      cout << "need to remove largest" << endl;
      int i = RemoveLargest(tree->left);
      tree->data = i;
    }
    return;
  } else if (tree->data < n) {
    Remove(tree->right, n);
    return;
  } else {
    Remove(tree->left, n);
    return;
  }
}

void Print(Node* tree) {
  if (tree == nullptr) return;
  Print(tree->left);
  cout << tree->data << " ";
  Print(tree->right);
}

bool Find(Node* tree, int n) {
  if (tree == nullptr) {
    return false;
  } else if (tree->data == n) {
    return true;
  } else if (tree->data < n) {
    return Find(tree->right, n);
  } else {
    return Find(tree->left, n);
  }
}

// Given a sorted array as argument,
// returns a balanced binary search tree.
Node* BalancedTreeFromArray(int arr[], int first, int last) {
  if(first>last) return nullptr;
  int mid = ((first+last)/2);
  Node* root = new Node(arr[mid]);
  root->left = BalancedTreeFromArray(arr,first,mid-1);
  root->right = BalancedTreeFromArray(arr,mid+1,last);
  return root;
}

// Returns depth of a tree. Empty tree has depth 0.
// Tree with only one node has depth 1.
int FindDepth(Node* tree) {
  int depth = 0;
  if(tree==nullptr) return 0;
  int ldepth = FindDepth(tree->left)+1;
  int rdepth = FindDepth(tree->right)+1;
  if(ldepth>rdepth){
    return ldepth;
  } else {
    return rdepth;
  }
}

// Returns # of entities within a tree
int NumNodes(Node* t){
  if(t==nullptr) return 0;
  return 1 + NumNodes(t->left) + NumNodes(t->right);
}

// Returns true if tree is balanced, false otherwise.
// Tree is balanced if the number of nodes on left tree differs from the
// number of nodes on right tree by no more than 1,
// and both children (branches) are also balanced trees.
bool IsBalanced(Node* tree) {
  if(tree==nullptr){
    return 1;
  }
  int lDepth = NumNodes(tree->left);
  int rDepth = NumNodes(tree->right);
  if((abs(lDepth-rDepth) <= 1)&&(IsBalanced(tree->left))&&(IsBalanced(tree->right))){
      return true;
  }
  return false;
}

// Swaps nodes recursively in order to make the binary tree Balanced
// Does not use another intermediate data structure,
void BalanceTree(Node*& tree) {
  if(tree==nullptr) return;
  int lDepth = NumNodes(tree->left);
  int rDepth = NumNodes(tree->right);
  while( rDepth > lDepth+1){
    lDepth = NumNodes(tree->left);
    rDepth = NumNodes(tree->right);
    int largest = RemoveLargest(tree->right);
    Remove(tree,largest);
    int prevTop = tree->data;
      tree->data = largest;
    Insert(tree,prevTop);
  }
  while( lDepth > rDepth+1){
    lDepth = NumNodes(tree->left);
    rDepth = NumNodes(tree->right);
    int largest = RemoveLargest(tree->left);
    Remove(tree,largest);
    int prevTop1 = tree->data;
    tree->data = largest;
    Insert(tree,prevTop1);
  }
  BalanceTree(tree->left);
  BalanceTree(tree->right);
}


int main() {

  int arr[] = { 2, 5, 7, 9, 10, 11, 16, 18 };
  Node* tree1 = BalancedTreeFromArray(arr, 0, 7);
  Print(tree1);
  cout<<endl;

  if (IsBalanced(tree1)) {
    cout << "Tree is balanced" << endl;
  } else {
    cout<< "wrong" <<endl;
  }

  Node* tree = nullptr;
  Insert(tree, 13);
  Insert(tree, 12);
  Insert(tree, 6);
  Insert(tree, 7);
  Insert(tree, 8);
  Insert(tree, 5);
  Insert(tree, 6);
  Insert(tree, 4);
  Insert(tree, 3);

  if (IsBalanced(tree)) {
    cout << "Tree is balanced." << endl;
  } else {
    cout << "Tree is not balanced." << endl;
  }
  BalanceTree(tree);


  Print(tree);

  return 0;
}

/*

2 5 7 9 10 11 16 18
Tree is balanced
Tree is not balanced.
Tree is balanced.
3 4 5 6 7 8 12 13

*/
