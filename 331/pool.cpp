#include <iostream>
#include <math.h>
using namespace std;

using ll = long long int;

int main() {
  const int SIDES = 4;

  ll n;
  ll x[SIDES], y[SIDES];

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> x[i];
    cin >> y[i];
  }

  if (n <= 1 || (n == 2) && (x[0] == x[1] || y[0] == y[1])) {
    cout << "-1" << endl;
    return 0;
  }
  ll area;
  if (n == 2) {
    area = abs(y[1] - y[0]) * abs(x[0] - x[1]);
  } else {
    const auto isCorner = [&x, &y](int idx) {
      int b = (idx + 1) % (SIDES - 1);
      int c = (b + 1) % (SIDES - 1);
      ll x1 = x[idx] - x[b];
      ll y1 = y[idx] - y[b];
      ll x2 = x[c] - x[idx];
      ll y2 = y[c] - y[idx];
      return (x1 * x2 + y1 * y2) == 0;
    };

    if (isCorner(0)) {
      area = (abs(x[1] - x[0]) + abs(y[1] - y[0]))
           * (abs(x[0] - x[2]) + abs(y[0] - y[2]));
    } else if (isCorner(1)) {
      area = (abs(x[0] - x[1]) + abs(y[0] - y[1]))
             * (abs(x[1] - x[2]) + abs(y[1] - y[2]));
    } else {
      area = (abs(x[0] - x[2]) + abs(y[0] - y[2]))
           * (abs(x[2] - x[1]) + abs(y[2] - y[1]));
    }
  }

  cout << area << endl;
  return 0;
}