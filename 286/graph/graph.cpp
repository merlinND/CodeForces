#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MAX_NODES 101
// Adjacency matrix
#define vi vector<int>
#define adj vector<vi>
#define mcg map<int, adj>

bool pathExists(adj const & graph, int source, int destination) {
  // Breadth-first search
  bool visited[MAX_NODES];
  queue<int> q;

  // Init
  for(int i = 0; i < MAX_NODES; ++i) {
    visited[i] = false;
  }
  visited[source] = true;
  q.push(source);

  int current;
  while(!q.empty()) {
    current = q.front();
    q.pop();

    if(current == destination) {
      return true;
    }

    for(int i = 0; i < graph[current].size(); ++i) {
      // For each new neighbor
      int neighbor = graph[current][i];
      if(!visited[neighbor]) {
        if(neighbor == destination) {
          return true;
        }

        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }

  return false;
}

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
      // Initialize a new adjacency list
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
      if(pathExists(graphs[*it], source, destination)) {
        r++;
      }
    }

    cout << r << endl;
  }

  return 0;
}
