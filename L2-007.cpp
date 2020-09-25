/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 

/*
 *  并查集例题
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN  10002
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, k;
int fa[MAXN];
int vis[MAXN];
int hnum[MAXN];
int harea[MAXN];
int nhnum[MAXN];
int nharea[MAXN];
int cn[MAXN];

struct pta
{
  int id;
  double avh, ava;
};
vector<pta> rec;

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
    fa[max(dx, dy)] = min(dx, dy);
}

int cmp(pta a, pta b)
{
  if (a.ava == b.ava)
    return a.id < b.id;
  return a.ava > b.ava;
}

void solve()
{
  for (int i=0; i<MAXN; ++i)
    fa[i] = i;

  cin >> n;
  int id, pid1, pid2, k, cid;

  for (int i=0; i<n; ++i)
  {
    cin >> id >> pid1 >> pid2 >> k;
    vis[id] = 1;
    if (pid1 != -1) { vis[pid1] = 1; merge(id, pid1);}
    if (pid2 != -1) { vis[pid2] = 1; merge(id, pid2);}

    for (;k;--k)
    {
      cin >> cid;
      merge(id, cid);
      vis[cid] = 1;
    }
    cin >> hnum[id] >> harea[id];
  }

  int l = 0;
  for (int i=0; i<MAXN; ++i)
  {
    if (vis[i])
    {
      id = findfa(i);
      nhnum[id] += hnum[i];
      nharea[id] += harea[i];
      cn[id]++;
      // cout << i << " : " << id << endl;
      if (id == i)
        l++;
    }
  }

  for (int i=0; i<MAXN; ++i)
  {
    if (vis[i] && fa[i] == i)
    {
      pta temp;
      temp.id = i;
      temp.avh = 1.0 * nhnum[i] / cn[i];
      temp.ava = 1.0 * nharea[i] / cn[i];
      rec.push_back(temp);
    }
  }
  cout << l << endl;
  sort(rec.begin(), rec.end(), cmp);

  for (int i=0; i<l; ++i)
  {
    id = rec[i].id;
    printf("%04d %d %.3lf %.3lf\n", id, cn[id], rec[i].avh, rec[i].ava);
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

