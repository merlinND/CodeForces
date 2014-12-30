#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

bool canSwap(vector<vb> const & allowed, int source, int destination) {
  if(source == destination) {
    return false;
  }
  else if(allowed[source][destination]) {
    return true;
  }

  // Still, we might find a path (using transitivity of swaps)
  // Explore using breadth-first search
  int n = allowed.size();
  vb seen;
  for(int i = 0; i < n; ++i) {
    seen.push_back(false);
  }

  queue<int> candidates;
  candidates.push(source);
  int current;
  while(!candidates.empty()) {
    current = candidates.front();
    candidates.pop();
    seen[current] = true;

    if(current == destination) {
      return true;
    }

    // Add neighbors
    for(int j = 0; j < n; ++j) {
      if(allowed[current][j] && !seen[j]) {
        candidates.push(j);
        seen[j] = true;
      }
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  vi permutation;
  int p;
  for(int i = 0; i < n; ++i) {
    cin >> p;
    permutation.push_back(p);
  }

  vector<vb> allowed;
  char a;
  for(int i = 0; i < n; ++i) {
    allowed.push_back(vb());
    for(int j = 0; j < n; ++j) {
      cin >> a;
      allowed[i].push_back(a == '1');
    }
  }

  // Extend paths using transitivity
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i != j && !allowed[i][j]) {
        allowed[i][j] = canSwap(allowed, i, j);
      }
    }
  }

  // We're trying to minimize the lexiographical order.
  // Since n <= 300, we can run exhaustive search
  bool changed;
  do {
    changed = false;

    // For each element
    for(int i = 0; i < n; ++i) {
      // Find the best available "prettier" position
      int j = 0;
      while(j < n && (permutation[j] < permutation[i] || !allowed[i][j])) {
        j++;
      }
      // Found a suitable position
      if(j < i) {
        changed = true;
        swap(permutation[i], permutation[j]);
      }
    }
  } while(changed);


  cout << permutation[0];
  for(int i = 1; i < n; ++i) {
    cout << " " << permutation[i];
  }
  cout << endl;

  return 0;
}
