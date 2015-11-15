#include <iostream>
#include <math.h>
using namespace std;

using ll = long long int;

int main() {
  ll n, d;
  ll previous = 0;
  ll ops = 0;

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> d;
    ops += abs(d - previous);
    previous = d;
  }
  cout << ops << endl;
  return 0;
}