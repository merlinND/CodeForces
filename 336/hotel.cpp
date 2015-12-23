#include <iostream>
using namespace std;

using ll = long long int;

int main() {
  ll n, s;
  cin >> n; cin >> s;

  // Time passed
  ll t = s;

  ll arrival, floor;
  for (ll i = 0; i < n; ++i) {
    cin >> floor; cin >> arrival;

    t = max(s, max(t, floor + arrival));
  }

  cout << t << endl;
  return 0;
}