/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  10005
#define Inf 0x7FFFFFFE

#define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, k;
int fa[MAXN];

int findfa(int x)
{
  if (fa[x] == x)
    return x;
  else
    return fa[x] = findfa(fa[x]);
}

void merge(int x, int y)
{
  int dx = findfa(x);
  int dy = findfa(y);
  if (dx != dy)
    fa[dy] = dx;
}

void solve()
{
  cin >> n;
  int x, fx, q;
  int maxx = -Inf;

  for (int i=1; i<MAXN;++i)
    fa[i] = i;

  for (int i=1; i<=n;++i)
  {
    cin >> k;
    fx = 0;

    for (;k;--k)
    {
      cin >> x;
      maxx = max(maxx, x);

      if(!fx) fx = x;
      merge(fx, x);

    }
  }
  int num = 0;
  for (int i=1; i<=maxx;++i)
    if (fa[i] == i)
      num++;

  cout << maxx << ' ' << num << endl;

  int y;
  cin >> q;
  for (;q;--q)
  {
    cin >> x >> y;
    if (findfa(x) == findfa(y))
      cout << "Y" << endl;
    else
      cout << "N" << endl;
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

