#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;

using ll = long long int;

enum PHASES {
    LOWER, MIDDLE, UPPER, N_PHASES
};

#define LOG(p) \
  string phase = "LOWER";                    \
  if (p == MIDDLE) phase = "MIDDLE";         \
  else if (p == UPPER) phase = "UPPER";      \
  cerr << phase << ": " << i << "] ";        \
  cerr                                       \

int main() {
  ll n;
  bool valid = true;

  cin >> n;
  ll x, y, xMax = 0, yMax = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> x; cin >> y;
    xMax = max(xMax, x);
    yMax = max(yMax, y);
  }

  const ll L = min(xMax, yMax) + 1;
  /** Diagonal number of the maximum diagonal */
  const ll C = xMax + yMax;
  /** Boundary number used frequently */
  const ll B = (L - 1) * (L - 2) / 2;

  // TODO: pathological cases for L < 2 => (xMax < 1 || yMax < 1)

  const auto phase = [&L, &n, &B](ll i) {
    if (i == 0 || i < B) return LOWER;
    if (i < (n - B)) return MIDDLE;
    return UPPER;
  };

  const std::function<bool(ll, ll)> shouldIncrementDiagonal[N_PHASES] = {
      [](ll const & nElements, ll const & diagonalNumber) {
        return (nElements >= diagonalNumber + 1);
      },
      [&L](ll const & nElements, ll const & diagonalNumber) {
        return (nElements > L);
      },
      [&C](ll const & nElements, ll const & diagonalNumber) {
        return (nElements > (C - diagonalNumber) + 1);
      }
  };

  const std::function<void(ll*, ll*)> updateBounds[N_PHASES] = {
      [](ll * upper, ll * lower) {
        (*upper)++;
        (*lower)--;
      },
      [&xMax, &yMax](ll * upper, ll * lower) {
        if (xMax >= yMax) {  // Fat
          (*upper)--;
          (*lower)--;
        } else {  // Tall
          (*upper)++;
          (*lower)++;
        }
      },
      [](ll * upper, ll * lower) {
        (*upper)--;
        (*lower)++;
      }
  };

  ll w;
  ll diagonalNumber = 0, nElements = 0, wSum = 0;
  ll upperBound = 0, lowerBound = 0;
  vector<ll> solutionX(static_cast<size_t>(n)), solutionY(static_cast<size_t>(n));

  for (ll i = 0; i < n; ++i) {
    const PHASES p = phase(i);

    cin >> w;
    if (w < lowerBound || w > upperBound) {
      valid = false;
      LOG(p) << "Constraint " << w << " cannot be achieved on diagonal " << diagonalNumber
             << ", should be in [" << lowerBound << ", " << upperBound << "]";
      break;
    }
    wSum += w;
    nElements++;

    // Constraint is valid, give it a fresh point from the plane
    // Recall diagonalNumber = x + y and w = y - x
    solutionX[i] = (diagonalNumber - w) / 2;
    solutionY[i] = (diagonalNumber + w) / 2;

    if (shouldIncrementDiagonal[p](nElements, diagonalNumber)) {
      // Constraints should be unique on each diagonal: they add up to the
      // distance between the lower and upper bounds
      if (wSum != (lowerBound + upperBound)) {
        valid = false;
        LOG(p) << "Constraint sum " << wSum<< " on diagonal " << diagonalNumber
               << " doesn't add up to " << lowerBound << " + " << upperBound << endl;
        break;
      }

      diagonalNumber++;
      nElements = 0;
      wSum = 0;
      updateBounds[p](&upperBound, &lowerBound);
    }
  }

  if (!valid) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (ll i = 0; i < n; ++i) {
      cout << solutionX[i] << " " << solutionY[i] << endl;
    }
  }
  return 0;
}