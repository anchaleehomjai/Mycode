#include<iostream>
#include <bits/stdc++.h>

#include <string>
using namespace std;


int main()
{
  string str;
  cin >> str;
  
  list<char> l;
  list<char>::iterator li;
  
  li = l.begin();

  std::list<char> chars;
    for (int i =0;i<str.size();i++) {
      // cout<<c;
      if(str[i] == '['){
      li=l.begin();
      }
      else if(str[i] ==']'){
        li = l.end();
      }
      else{
      l.insert(li,str[i]);
   
      }
      }

  
  // list<int> l;
  // list<int>::iterator li;
  // li = l.begin();
  // l.insert(li,10);
  // l.insert(li,20);
  // li=l.begin();
  // l.insert(li,30);
  for(auto x:l)
  cout<<x;
  cout<<"\n";
 
  // for(auto x:l)
  // cout<<x<<" ";

  
  
	return 0;
}


