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
const int mod=1000000007;
int main() {
  ll a,b,i,j,k,n;
  ll dp[2][602];
  cin>> n >> a >> b;
  memset(dp,0,sizeof(dp));
  dp[1][0]=1;
  dp[1][a]=1;
  for(i=2;i<=n;i++)
  {
      ll i1=i%2;
      ll i2=(i+1)%2;

      for(j=0;j<a+b;j++)
        dp[i1][j]=0;

      for(j=0;j<a+b;j++)
        if(j==0)
          for(k=a;k<a+b;k++)
          dp[i1][j]=(dp[i1][j]+dp[i2][k])%mod;
        else if(j<a)
          dp[i1][j]=dp[i2][j-1];
        else if(j==a)
          for(k=0;k<a;k++)
          dp[i1][j]=(dp[i1][j]+dp[i2][k])%mod;
        else
          dp[i1][j]=dp[i2][j-1];

     //   for(j=0;j<a+b;j++)
       //ß   cout << dp[i1][j]<< endl;
  }
  ll ans=0;
  for(j=0;j<a+b;j++)
    ans=(ans+dp[n%2][j])%mod;

  cout << ans<< endl;
}
