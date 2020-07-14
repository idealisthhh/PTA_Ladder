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

#define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, x;
set<int> road;

void solve()
{
  cin >> n;
  road.insert(MAXN);
  for (int i=0; i<n; i++)
  {
    cin >> x;
    if (x < *road.rbegin())
      road.erase(*road.upper_bound(x));
    road.insert(x);
  }

  cout << road.size() << endl;
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

