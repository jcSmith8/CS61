#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char x){
  if(x=="+"||x=="-"||x=="*"||x=="/"){
    return true;
  } else {
  return false;
  }
}

string infix_eval(string infix[], int len){
  stack<string> operands;
  stack<char> operators;
  for(int i=0;i<len;i++){
    if(infix[i]=="("){
      break;
    }
    if(infix[i]==")"){
      int op1=stoi(operands.top());
      operands.pop();
      int op2=stoi(operands.top());
      operands.pop();
      char opt=operators.top();
      operators.pop();
      int res;
      switch(opt){
        case "+":
          res=op2+op1;
        case "-":
          res=op2-op1;
        case "*":
          res=op2*op1;
        case "/":
          res=op2/op1;
      }
      operands.push(to_string)(res));
      break;
    }
    if(isOperator(infix[i])){
      operators.push(infix[i]);
    } else {
      operands.push(infix[i]);
    }
  }
}

int main(){
  string infix[8] = {"(","+","(","19","*","5",")",")"};
  cout<<infix_eval(infix,8)<<endl;
}
