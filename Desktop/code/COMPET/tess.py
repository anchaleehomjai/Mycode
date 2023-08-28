#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  long m;
   cin >> n;
  cin >> m;
  long  array[n];
  long sumArr[m];

  for (int i = 0; i<n;i++){
    cin >> array[i];
  }
  long a;
  long b;
  for(int i =0;i<m;i++){
    cin>> a;
    cin >> b;
    int k = 0;
    for(int j = a; j<= b; j++ ){
      sumArr[k] += array[j] ;
    }
    cout << sumArr[k];
    k++;
    }
  


  return 0;
}