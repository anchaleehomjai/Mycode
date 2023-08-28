
#include <bits/stdc++.h>
using namespace std;
 
void SieveOfEratosthenes(int a,int b)
{  int count = 0;
    bool prime[ b + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= b ; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= b; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= b; p++){
        if (prime[p]){
          // cout << p << " "; 
          if(p >= a && p <= b)
          count++;
          }
      }
    cout << count << " ";     
}
 
// Driver Code
int main()
{    
  ios::sync_with_stdio(0);
  cin.tie(0);  
    int a, b;
    cin >> a >> b;


    SieveOfEratosthenes(a,b);
    return 0;
}