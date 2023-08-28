#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s) {
  stack<char> Parentheses;
  for(int i = 0; i<s.size();i++){
    if(Parentheses.empty()){
        Parentheses.push(s[i]);
        }
    else if ((Parentheses.top()=='(' && s[i] == ')') || (Parentheses.top() == '{' && s[i] == '}') || (Parentheses.top() == '[' && s[i] == ']')) {
              Parentheses.pop();
    }
    else
        Parentheses.push(s[i]);
    }
    if (Parentheses.empty())
    return true;
  return false;
}

int main() {
  string s;
  cin >> s;
  while (s != "-1") {
    if(isBalanced(s)) {
      cout << "Parentheses are balanced" << endl;
    } else {
      cout << "Parentheses are not balanced" << endl;
    }
    cin >> s;
  }
}