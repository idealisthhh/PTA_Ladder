#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE
typedef long long LL;

// #define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n;
int num[MAXN];


void solve()
{
  cin >> n;

  int s = 0, cnt = 0;
  while (s < n)
  {
    s = s*10 + 1;
    cnt++;
  }
  
  int ind = 0;
  while (true)
  {
    num[ind++] = s/n;
    s %= n;
    if (s == 0) break;
    s = s * 10 + 1;
  }
  for (int i=0; i<ind; i++)
    cout << num[i];
  cout << ' ' << ind+cnt-1;
}


int main()
{

#ifdef idealist
	freopen("input.in", "r", stdin);
#endif

	int T;
#ifndef singletest
	cin >> T;
#endif

#ifdef singletest
	T = 1;
#endif

  for(;T;--T)
		solve();
  
  return 0;
}

