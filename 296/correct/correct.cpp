#include <iostream>
using namespace std;

typedef long long ll;

ll hammingDistance(string a, string b) {
  ll distance = 0;
  for(size_t i = 0; i < a.length(); ++i) {
    if(a[i] != b[i]) {
      distance++;
    }
  }
  return distance;
}


int main() {
  ll length;
  string first, second;
  cin >> length;
  cin >> first >> second;

  // TODO:
  ll minDistance = hammingDistance(first, second);
  ll pos1 = -1, pos2 = -1;

  cout << minDistance << endl << pos1 << " " << pos2 << endl;
  return 0;
}
