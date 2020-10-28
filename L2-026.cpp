#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE
typedef long long LL;

// #define idealist 1
#define singletest 1

/******
 *  简单的 DFS 问题
******/


/*******************   CODE   *********************/

int n;
vector<int> rec[MAXN];
int maxo = -Inf;
vector<int> maxid;

void dfs(int id, int para)
{
  int l = rec[id].size();
  if (maxo < para)
  {
    maxo = para;
    maxid.clear();
  }
  if (maxo == para)
    maxid.push_back(id);
  for (int i=0; i<l; ++i)
    dfs(rec[id][i], para+1);
}

void solve()
{
  cin >> n;
  int x, r;
  for (int i=1; i<=n; ++i)
  {
    cin >> x;
    if (x == -1)
    {
      r = i;
      continue;
    }
    rec[x].push_back(i);
  }
  dfs(r, 1);
  cout << maxo << endl;
  sort(maxid.begin(), maxid.end());
  cout << maxid[0];
  int l = maxid.size();
  for (int i=1; i< l; i++)
    cout << ' ' << maxid[i];

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

