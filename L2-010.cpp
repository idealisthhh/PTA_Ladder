/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  102
#define Inf 0x7FFFFFFE

// #define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n, m, k;
int fa[MAXN];
set<int> hater[MAXN];

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
  for (int i=1; i<MAXN;++i)
    fa[i] = i;

  cin >> n >> m >> k;
  int g1, g2, ra;

  for (int i=0; i<m; ++i)
  {
    cin >> g1 >> g2 >> ra;

    if (ra == 1)
      merge(g1, g2);
    
    if (ra == -1)
    {
      hater[g1].insert(g2);
      hater[g2].insert(g1);
    }
  }

  while (k--)
  {
    cin >> g1 >> g2;

    if (hater[g1].count(g2) != 0)
    {
      if (findfa(g1) == findfa(g2))
        cout << "OK but..." << endl;
      else
        cout << "No way" << endl;
      continue;
    }

    if (findfa(g1) == findfa(g2))
    {
      cout << "No problem" << endl;
      continue;
    }

    cout << "OK" << endl;
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

