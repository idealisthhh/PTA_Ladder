/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define Inf 0x7FFFFFFE

// #define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n, k;
double z, r, tot;

struct pat{
  vector<int> chil;
	int nerniu;
	double times;
} kongfu[MAXN];

void dfs(int id, double power)
{
  if (kongfu[id].nerniu)
  {
    tot += power * kongfu[id].times;
    return;
  }
  int l = kongfu[id].chil.size();
  for (int i=0; i<l; i++)
    dfs(kongfu[id].chil[i], power*(1-r/100));
}

void solve()
{
  cin >> n >> z >> r;

  int x;
  for (int i=0; i<n; ++i)
  {
    cin >> k;

    if (k == 0)
    {
      kongfu[i].nerniu = 1;
      cin >> kongfu[i].times;
    }

    while (k--)
    {
      cin >> x;
      kongfu[i].chil.push_back(x);
      kongfu[x].nerniu = 0;
    }
  }

  dfs(0, z);
  cout << (int)tot << endl;
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

