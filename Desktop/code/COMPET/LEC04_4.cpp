#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    cout << long(floor(sqrt(n))) - 1;
  } else {
    cout << long(floor(sqrt(n)));
  }
  return 0;
}