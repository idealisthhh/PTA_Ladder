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

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, m, k;
int city[MAXN];
pair<int, int> edge[MAXN];

void solve()
{
  memset(city, 0, sizeof(city));
  cin >> n >> m;
  int x, y;
  for (int i=0; i<m; ++i)
  {
    cin >> x >> y;
    city[x] = city[y] = 1;
    edge[i] = make_pair(x, y);
  }

  cin >> k;
  int j;
  for (int i=0; i<k; ++i)
  {
    vector<int> rec;
    cin >> x;
    for (j=0; j<x; ++j)
    {
      cin >> y;

      if (city[y])
        rec.push_back(y);

      city[y] = 0;
    }

    for (j=0; j<m; ++j)
    {
      if (city[edge[j].first] == 1 && city[edge[j].second] == 1)
      {
        cout << "NO" << endl;
        break;
      }
    }
    if (j == m)
      cout << "YES" << endl;

    int l = rec.size();
    for(j=0; j<l; ++j)
      city[rec[j]] = 1;
    rec.clear();
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

