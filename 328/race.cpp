#include <iostream>
#include <math.h>
using namespace std;

using ll = long long int;

ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  for (;;) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}

ll lcm(ll a, ll b) {
  ll temp = gcd(a, b);
  return temp ? (a / temp * b) : 0;
}

int main() {
  ll t, w, b;
  cin >> t; cin >> w; cin >> b;

  ll m = 1;
  ll n = 1;

  // Assuming w >= 1, b >= 1
  if (w != b) {
    // Integer divisions
    ll l = lcm(w, b);
    // Reasons to tie:
    // 1. Length of the track is a multiple of both w and b
    // 2. Length of the track is more than a multiple of w, b but
    //    not by a full w or a full b
    // 3. Length of the track is less than both w and b
    m = (t / l) * min(w, b) + (min(w, b) - 1);
    n = t;
  }

  cout << m << "/" << n;

  return 0;
}