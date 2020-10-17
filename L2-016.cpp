/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define Inf 0x7FFFFFFE

#define idealist 1
#define singletest 1

/*******************   CODE   *********************/

pair<int, int> p[MAXN];
int sex[MAXN];
int flag[MAXN];
int n, k, res;

void dfs(int id, int l)
{
  if (l >= 5)
    return ;

  if (id == -1 || id == 0)
    return;

  if (flag[id])
  {
    res = 1;
    return;
  }

  flag[id] = 1;
  dfs(p[id].first, l+1);
  dfs(p[id].second, l+1);

}


void solve()
{
  cin >> n;

  int id, fid, mid;
  char c;

  for (int i=0; i<n; ++i)
  {
    cin >> id >> c >> fid >> mid;
    sex[id] = (c == 'M') ? -1 : 1;
    p[id] = make_pair(fid, mid);
    if(fid != -1) sex[fid] = -1;
    if(mid != -1) sex[mid] = 1;
  }

  cin >> k;

  for (int i=0; i<k; ++i)
  {
    memset(flag, 0, sizeof(flag));
    res = 0;

    cin >> fid >> mid;
    
    if (sex[fid] == sex[mid])
      cout << "Never Mind" << endl;
    else
    {
      dfs(fid, 0);
      dfs(mid, 0);
      if (res)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
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

