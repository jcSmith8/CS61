#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

bool isOperator(string x){
  if(x=="+"||x=="-"||x=="*"||x=="/"){
    return true;
  }
  return false;
}

string postfix_to_prefix(string postfix[], int len){
  stack<string> s;
  for(int i=0;i<len;i++){
    if(isOperator(postfix[i])){ //operator
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      string equation = postfix[i]+" "+op2+" "+op1;
      s.push(equation);
    } else { //operand
      s.push(postfix[i]);
    }
  }
  return s.top();
}

int main(){
  string postfix1[11] = {"3","9","-","16","+","25","3","2","*","-","+"};
  cout<<postfix_to_prefix(postfix1,11)<<endl;
}
