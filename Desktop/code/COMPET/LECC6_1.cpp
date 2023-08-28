#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long array[n];
   priority_queue<int,vector<int>,greater<int>> q;
  // long long arrcost[n];
  //input
	for( int i =0; i < n ; i++){
    cin >> array[i];
    q.push(array[i]);
    
    }

  long long  sum = 0;
  while(q.size() > 1 ){
    int valu = q.top();
    q.pop();
    sum += q.top() + valu;
    q.pop();
    q.push(sum);
  
  }
  cout << sum;


  return 0;
}