#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;

int main() {
  ll n, l;
  cin >> n >> l;

  vector<ll> lanterns;
  ll position;
  for(ll i = 0; i < n; ++i) {
    cin >> position;
    lanterns.push_back(position);
  }
  sort(lanterns.begin(), lanterns.end());

  // Very first lantern
  ll maxDistance = 2 * lanterns[0];
  for(ll i = 1; i < n; ++i) {
    maxDistance = max(lanterns[i] - lanterns[i-1], maxDistance);
  }
  // Very last street segment
  maxDistance = max(2 * (l - lanterns[n-1]), maxDistance);

  cout << setprecision(10) << fixed;
  cout << (maxDistance / 2.0) << endl;
  return 0;
}
