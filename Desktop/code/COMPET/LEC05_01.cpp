#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
  long long sum = 0;
  cin >> n;
  std::vector<int> array(n);

  //input
	for( int i =0; i < n ; i++){
    cin >> array[i];
    sum+= array[i];
  }
  long long count = sum / n;
  int step = 0;

  for(int j = 0;j<n;j++){
    while(array[j] < count){
        step++;
        array[j]++;
        // cout <<array[j] ;
      }
    }
  cout << step;
  
  
	return 0;
}
