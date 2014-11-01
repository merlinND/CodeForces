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
const int maxn=1001820;
struct treearray{
    long long a[maxn];
    ll n;
    inline ll lowbit(ll p){
      return p&(-p);
    }
    long long getsum(ll p)
    {
      long long ans=0;
      ll i=p;
      while(i!=0){
        ans+=a[i];
        i-=lowbit(i);
      }
      return ans;
    }
    void add(ll p,ll x){
      ll i=p;
      while(i<=n){
        a[i]+=x;
        i+=lowbit(i);
      }
    }
    void init(){
      memset(a,0,sizeof(a));
    }
}tr;
int main() {
  ll int n, c;
  string date, t;
  int month, day, hour, minute;
  // Timestamp in minutes (will be unique)
  ll int timestamp;
  cin >> n;
  tr.init();
  tr.n=maxn;
  ll int mostright=1;
  FOR(i, n) {
    cin >> c;
    scanf("%d.%d %d:%d", &month, &day, &hour, &minute);
    timestamp = month * 44640 + day * 1440 + hour * 60 + minute;
    cout<<"t"<<timestamp<<endl;
    if(c<0&&mostright<timestamp)
      mostright=timestamp;

    tr.add(timestamp,c);
    //cout<<tr.getsum(timestamp)<<endl;
    ll ans=tr.getsum(mostright);

    if(ans>0)ans=0;
    cout<<ans<<endl;
    // Operation: timestamp => amount
  }
}
