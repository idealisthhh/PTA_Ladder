/*
 * @Author: GoneWithWind 
 * @Date: 2020-10-28 21:31:15 
 * @Last Modified by: GoneWithWind
 * @Last Modified time: 2020-10-28 21:38:56
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN  12
#define Inf 0x7FFFFFFE
typedef long long LL;

// #define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n, m;
int maps[MAXN][MAXN];
int vis1[MAXN];
int vis2[MAXN];

void dfs(int x)
{
  cout << x << ' ';
  vis1[x] = 1;
  for (int i=0; i<n; ++i)
    if (!vis1[i] && (maps[x][i] || maps[i][x]))
      dfs(i);
}

void bfs(int s)
{
  queue<int> rex;
  rex.push(s);
  vis2[s] = 1;
  int t;
  while(!rex.empty())
  {
    t = rex.front();
    rex.pop();
    cout << t << ' ';
    for (int i=0; i<n; ++i)
      if (!vis2[i] && (maps[t][i] || maps[i][t]))
      {
        vis2[i] = 1;
        rex.push(i);
      }
  }
}

void solve()
{
  cin >> n >> m;
  int x, y;
  for (int i=0; i<m;++i)
  {
    cin >> x >> y;
    maps[y][x] = maps[x][y] = 1;
  }

  for (int i=0; i<n; ++i)
    if (!vis1[i])
    {
      cout << "{ ";
      dfs(i);
      cout << "}" << endl;
    }
  
  for (int i=0; i<n; ++i)
  if (!vis2[i])
  {
    cout << "{ ";
    bfs(i);
    cout << "}" << endl;
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

