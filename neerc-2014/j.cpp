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
struct node{
  int id;
  int v;
}a[1001],b[1001];
bool cmp1(node p,node q)
{
  return p.v<q.v;
}
bool cmp2(node p,node q)
{
  return p.v>q.v;
}
int main() {
  int i,j,k,m,n,sum1,sum2;
  scanf("%d",&n);
  sum1=0;
  sum2=0;
  for(i=1;i<=n;i++)
  {
    scanf("%d",&a[i].v);
    a[i].id=i;
    sum1+=a[i].v;
  }
  for(i=1;i<=n;i++)
  {
    scanf("%d",&b[i].v);
    b[i].id=i;
    sum2+=b[i].v;
  }
  if(sum1>=sum2)
  {
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
  }
  else
  {
    sort(a+1,a+1+n,cmp2);
    sort(b+1,b+1+n,cmp1);
  }
  for(i=1;i<=n;i++)
    printf("%d %d\n",a[i].id,b[i].id);
}
