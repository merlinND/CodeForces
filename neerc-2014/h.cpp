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

int main() {

    int i,n;
    stack<char>st;
    stack<int> idA;
    stack<int> ida;
    int ans[5001];
    string s;

    cin >> n >> s;

    int itera=1;
    int iterA=1;

    for (i=0;i<2*n;i++){
     // printf("%c\n",s[i]);

      if(st.empty()){
          st.push(s[i]);
          if (s[i]>='A' && s[i]<='Z')
          idA.push(iterA++);
        else
          ida.push(itera++);

      }

      else if (s[i]>='A' && s[i]<='Z') {
          char c=st.top();
          idA.push(iterA++);
          if((c+'A'-'a')==s[i])
          {
              ans[idA.top()]=ida.top();
              ida.pop();
              idA.pop();
              st.pop();
          }
          else {
          st.push(s[i]);
        }
      }

      else {
          if(st.empty())break;
          char c=st.top();
          ida.push(itera++);
          if((c-'A'+'a')==s[i])
          {
              ans[idA.top()]=ida.top();
              ida.pop();
              idA.pop();
              st.pop();
          }
          else {
          st.push(s[i]);
        }
      }
    }

      if(!st.empty())
        cout<<"Impossible"<<endl;
      else{
        for(i=1;i<n;i++)
          printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
      }
  }
