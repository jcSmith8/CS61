#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
public:
  string data;
  Node* left;
  Node* right;
  Node(string d) : data(d), left(nullptr), right(nullptr) { };
};

bool isOperator(string x){
  if(x=="+"||x=="-"||x=="*"||x=="/"){
    return true;
  }
  return false;
}
/*
Node* ParsePrefix(const vector<string>& expr, int& ind){
  stack<string> operands;
  Node* root = new Node(expr[0]);
  Node* currNode = root;
  for(int i=1;i<expr.size();i++){
    if(isOperator(expr[i])){
      if(operands.size()>0){
        Node* newOperator = new Node(expr[i]);
        Node* newOperand = new Node(operands.top());
        operands.pop();
        currNode->right = newOperand;
        if(currNode->left==nullptr){
          currNode->left = newOperator;
        } else {
          currNode->left = newOperator;
          currNode = currNode->left;
        }
      } else {
        Node* nn = new Node(expr[i]);
        currNode->left=nn;
        }
    } else {
        operands.push(expr[i]);
        }
      }
  while(!(operands.empty())){
    if((currNode->left)==nullptr){
      currNode->left = new Node(operands.top());
      operands.pop();
    } else {
      currNode->right = new Node(operands.top());
      operands.pop();
    }
  }
  return root;
}
*/

bool isLeaf(Node* n){
  if((n->left==nullptr)&&(n->right==nullptr)){
    return true;
  } else {
    return false;
  }
}

Node* ParsePrefix(const vector<string>& expr, int& ind){
  Node* root = nullptr;
  stack<Node*> s;
  for(int i=expr.size(); i>=ind; i--){
    if(isOperator(expr[i])){
      Node* nn = new Node(expr[i]);
      root = nn;
      nn->left = s.top();
      s.pop();
      nn->right = s.top();
      s.pop();
      s.push(nn);
    } else {
      Node* nn = new Node(expr[i]);
      s.push(nn);
    }
  }
  return root;
}

void PrintPrefix(Node* t){
  if(t==nullptr){
    return;
  } else {
    cout<<t->data<<" ";
    PrintPrefix(t->left);
    PrintPrefix(t->right);
  }
}

void PrintPostfix(Node* t){
  if((isLeaf(t->left))&&(isLeaf(t->right))){
    cout<<t->left->data<<" "<<t->right->data<<" "<<t->data<<" ";
  } else if(isLeaf(t->left)){
    cout<<t->left->data<<" ";
    PrintPostfix(t->right);
    cout<<t->data<<" ";
  } else if(isLeaf(t->right)){
    PrintPostfix(t->left);
    cout<<t->right->data<<" "<<t->data<<" ";
  } else{
    PrintPostfix(t->left);
    PrintPostfix(t->right);
    cout<<t->data<<" ";
    }
}

void PrintInfix(Node* t){
  if((isLeaf(t->left))&&(isLeaf(t->right))){
    cout<<"("<<t->left->data<<" "<<t->data<<" "<<t->right->data<<") ";
  }
  else if(isLeaf(t->left)){
    cout<<"("<<t->left->data<<" "<<t->data<<" ";
    PrintInfix(t->right);
    cout<<")";
  } else if(isLeaf(t->right)){
    cout<<"(";
    PrintInfix(t->left);
    cout<<t->data<<" "<<t->right->data<<")"<<" ";
  } else {
    PrintInfix(t->left);
    cout<<t->data<<" ";
    PrintInfix(t->right);
  }
}

int main() {
  vector<string> expr; // = { "+", "-", "3", "2", "/", "*", "5", "7", "8" };
  expr.push_back("+");
  expr.push_back("-");
  expr.push_back("3");
  expr.push_back("2");
  expr.push_back("/");
  expr.push_back("*");
  expr.push_back("5");
  expr.push_back("7");
  expr.push_back("8");
  int index = 0;
  Node* t = ParsePrefix(expr, index);
  PrintPrefix(t);
  cout<<endl;
  PrintPostfix(t);
  cout<<endl;
  PrintInfix(t);
  cout << endl;
  return 0;
}


/* + - 3 2 / * 5 7 8
3 2 - 5 7 * 8 / +
( ( 3 - 2 ) + ( ( 5 * 7 ) / 8 ) )
 */
