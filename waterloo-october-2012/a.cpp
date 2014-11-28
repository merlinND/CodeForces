#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(it,t) for (__typeof(t.begin()) it = t.begin(); it != t.end(); ++it)
#define fi first
#define se second

// Maximum value for the cost
#define INF (1<<30)
// Edge: (to, (cost, isInside))
#define pib pair<int, pair<int, bool> >
// Node: (index, (time spend outside, total time spent))
#define node pii
// Adjacency list
#define adj vector<vector<pib> >

#define NOT_FOUND pii(-1, -1)

/**
 * Custom priority ordering: cheapest nodes first
 */
struct comparator {
  bool operator() (pii const & a, pii const & b) {
    return a.se > b.se;
  }
};

/**
 * `adjacency`: graph in the form of an adjacency list (node numbered form 0 to n-1)
 * @return A pair (time spent inside, total length of the shortest path)
 *         or (-1, -1) if no path exists.
 */
pii dijkstra(adj const & adjacency, int source, int destination) {
  int n = adjacency.size();
  bool visited[n];
  // TODO: take into account outside cost
  int cost[n];
  // TODO: custom comparator
  priority_queue<pii> q;

  FOR(i, n) {
    visited[i] = false;
    cost[i] = INF;
  }

  q.push(mp(source, 0));
  cost[source] = 0;

  while(!q.empty()) {
    int current = q.top().fi;
    q.pop();

    if(visited[current])
      continue;

    // cout << "Visiting " << current << endl;
    visited[current] = true;

    FOR(j, SZ(adjacency[current])) {
      pib const & neighbor = adjacency[current][j];
      int next = neighbor.fi;
      // cout << "Considering " << current << " -> " << next << " cost: " << neighbor.se.fi << endl;

      if(visited[next])
        continue;

      int alt = cost[current] + neighbor.se.fi;
      if(alt < cost[next]) {
        cost[next] = alt;
        q.push(mp(next, cost[next]));
      }
    }
  }

  // TODO: return best cost found
  return mp(cost[destination], -1);
}

int main () {
  int n, m, nTrips;
  cin >> n >> m >> nTrips;

  adj adjacency;
  FOR(i, n) {
    // For each node, list of edges leading to another node
    adjacency.pb(vector<pib>());
  }

  // TODO: change cost to `long long` if values may be too large
  int from, to, cost;
  char isInside;
  FOR(i, m) {
    cin >> from >> to >> cost >> isInside;

    adjacency[from].pb( mp(to, mp(cost, (isInside == 'I'))) );
    adjacency[to].pb( mp(from, mp(cost, (isInside == 'I'))) );
  }

  // We have `nTrips` queries to answer
  // TODO: precompute if needed
  int source, destination;
  FOR(i, nTrips) {
    cin >> source >> destination;

    pii result = dijkstra(adjacency, source, destination);

    if(result == NOT_FOUND) {
      cout << "IMPOSSIBLE" << endl;
    }
    else {
      cout << result.fi << "  " << result.se << endl;
    }
  }


  return 0;
}
