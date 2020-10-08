/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE

// #define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n;
set<int> num[52];

void solve()
{
  cin >> n;
  int x, m, k;

  for (int i=1; i<=n; ++i)
  {
    cin >> m;
    while (m--)
    {
      cin >> x;
      num[i].insert(x);
    }
  }

  cin >> k;
  int a, b;

  while (k--)
  {
    cin >> a >> b;
    double ans = 0, tot = 0;
    set<int>::iterator it;
    for (it=num[b].begin(); it!=num[b].end(); it++)
      if (num[a].find(*it) != num[a].end())
        ans++;
    tot = num[a].size() + num[b].size() - ans;

    printf("%.2lf%%\n", ans*100 / tot);
  }
  
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

