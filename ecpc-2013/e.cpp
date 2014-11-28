#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

using namespace std;

int main ()
{
  int T;
  freopen("ghanophobia.in","r",stdin);

  cin >> T;

  for (int i=0;i<T;i++)
  {
   // scanf("%c",&c);
    string s;

    cin >> s;
    int j=0,x=0,y=0;

    for (;s[j]!=':';j++)
    {
      x*=10;
      x+=s[j]-'0';
    }

    j++;
    for (; j<s.length();j++)
    {
      y*=10;
      y+=s[j]-'0';
    }
 

  //  cout << score1 << score2 << x << y <<'\n';
    printf("Case %d: ",i+1);
    if (x-y>5)
    {    
        printf("YES\n");
        continue;
    }

    if (x-y<5)
    {
      printf("NO\n");
      continue;
    }

    if (x==5 && y==0)
    {
      printf("YES\n");
    }

    if (x==6 && y==1)
    {
      printf("PENALTIES\n");
    }

    if (x>6)
    {
      printf("NO\n");
    }
    
  }



  return 0;
}
