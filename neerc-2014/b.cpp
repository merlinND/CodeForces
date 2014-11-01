#include "bits/stdc++.h"
using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp nake_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for(__typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second
int value[100001];
bool vis[100001];
bool notsober[100001];
vector<int> node[100001];
void dfs(int u)
{
  for(int i=0;i<node[u].size();i++)
    if(!vis[node[u][i]])
    {
         notsober[node[u][i]]=1;
         vis[node[u][i]]=1;
         dfs(node[u][i]);
    }
}
int main() {
  int i,j,k,m,n,v;


  memset(vis,0,sizeof(vis));
  memset(notsober,0,sizeof(notsober));
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&m);
    for(j=0;j<m;j++){
      scanf("%d%d",&value[i],&v);
      node[i].push_back(v);
    }
  }
  for(i=1;i<=n;i++)
    if(node[i]>0&&!vis[i])
    {
      vis[i]=1;
      dfs(i);
    }
  cout << "Hello world" << endl;
}
