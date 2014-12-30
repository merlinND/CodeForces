#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int n, destination;
  cin >> n >> destination;

  vector<int> portals;
  vector<bool> visited;

  // To accomodate for 1-based indexing
  portals.push_back(-1);
  visited.push_back(false);

  int a;
  for(int i = 1; i <= n - 1; ++i) {
    cin >> a;
    int portal = i + a;
    portals.push_back(portal);
    visited.push_back(false);
  }

  // No portal on the nth cell
  portals.push_back(-1);
  visited.push_back(false);

  int current = 1;
  while(current != destination && !visited[current] && portals[current] > 0) {
    visited[current] = true;
    current = portals[current];
  }

  if(current == destination) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}
