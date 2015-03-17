#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Cut {
  char type;
  ll distance;
};

int main() {
  ll width, length, n;
  cin >> width >> length >> n;

  char type;
  ll d;
  Cut c;
  vector<Cut> cuts;
  for(ll i = 0; i < n; ++i) {
    cin >> type >> d;
    c.type = type;
    c.distance = d;
    cuts.push_back(c);
  }

  cout << cuts.size() << endl;
  return 0;
}
