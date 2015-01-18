#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define MAX_NODES 101
// Adjacency matrix
#define vi vector<int>
#define adj vector<vi>
#define mcg map<int, adj>

int main() {
  int n, m;
  cin >> n >> m;

  // Map color -> graph
  mcg graphs;
  set<int> colors;

  // Input: graph
  int from, to, color;
  for(int i = 0; i < m; ++i) {
    cin >> from >> to >> color;

    // If this color was never seen before
    if(colors.find(color) == colors.end()) {
      colors.insert(color);

      adj graph;
      // Initialize a new adjacency matrix
      for(int x = 0; x < MAX_NODES; ++x) {
        vi edges;
        graph.push_back(edges);
      }

      graphs[color] = graph;
    }

    // Add edge in the graph of this color
    graphs[color][from].push_back(to);
    graphs[color][to].push_back(from);
  }

  // Input: queries
  int q, source, destination;
  cin >> q;
  for(int k = 0; k < q; ++k) {
    int r = 0;
    cin >> source >> destination;

    // For each color available, try to find a path
    for(set<int>::iterator it = colors.begin(); it != colors.end(); ++it) {
      cout << source << " -> " << destination << " in colors " << (*it) << "?" << endl;
      // if(pathExists(graph, source, destination)) {
      //   r++;
      // }
    }

    cout << r << endl;
  }

  return 0;
}
