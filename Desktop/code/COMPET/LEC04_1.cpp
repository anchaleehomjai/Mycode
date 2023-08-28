#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >>  str;
  transform(str.begin(), str.end(), str.begin(), ::toupper);
  int size =str.length() ;
  int i = 0;
  long long count = 1;
  while(size != 1 ){

    if(str[i+1] <= str[i]){
     int c =1;
    }
    else{
      count++;
      
    }
    i++;
     size--;
  }
  cout << count;
  return 0;
  
}