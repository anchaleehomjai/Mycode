#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  int n;
  cin >> n;
  int Array[n];
  int sum;
  int best = 0;

  for(int i=0; i<n; i++) {
    cin>>Array[i];
    best += Array[i];
    if(sum < best)
      sum = best; 
    if (best < 0)
      best = 0; 
   
  }
  cout << sum;
  return 0 ;
}

