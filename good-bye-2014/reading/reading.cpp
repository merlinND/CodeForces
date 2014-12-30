#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;

ll computeCost(vi const & booksOrder, vi const & weights, vi const & readingOrder) {
  ll totalEffort = 0;

  stack<pii> s;
  vector<pii> tmp;
  // Initial stack
  for(int i = 0; i < (int)booksOrder.size(); ++i) {
    s.push(mp(booksOrder[i], weights[booksOrder[i]]));
  }

  for(int i = 0; i < (int)readingOrder.size(); ++i) {
    // Find desired book in stack
    pii p = s.top();
    while(p.first != readingOrder[i]) {
      tmp.push_back(p);
      totalEffort += p.second;
      s.pop();
      if(!s.empty()) {
        p = s.top();
      }
    }

    // Found the book, we'll place it back on top
    // Restore the stack (keeping the order)
    for(int j = 0; j < (int)tmp.size(); ++j) {
      s.push(tmp[j]);
    }

    s.push(p);
    tmp.clear();
  }

  return totalEffort;
}

int main() {
  int nBooks, nDays;
  cin >> nBooks >> nDays;

  vi weights, readingOrder;
  /**
   * i => index of the book in position i in the initial stack
   * (numbered from bottom to top)
   */
  vi booksOrder;
  int c;
  for(int i = 0; i < nBooks; ++i) {
    cin >> c;
    weights.push_back(c);
    booksOrder.push_back(i);
  }
  for(int i = 0; i < nDays; ++i) {
    cin >> c;
    readingOrder.push_back(c - 1);
  }

  // TODO: optimize book order

  cout << computeCost(booksOrder, weights, readingOrder) << endl;
  return 0;
}
