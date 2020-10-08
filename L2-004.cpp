/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  1002
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n;
vector<int> pre, post;
int mirror = 0;

void getpost(int root, int tail)
{
  if (root > tail)  return;
  int i = root + 1, j = tail;
  if (mirror)
  {
    while(i <= tail && pre[i] >= pre[root])  ++i;
    while(j > root && pre[j] < pre[root]) --j;
  }
  else
  {
    while(i <= tail && pre[i] < pre[root]) ++i;
    while(j > root && pre[j] >= pre[root])  --j;
  }
  if (i - j != 1) return;
  getpost(root+1, j);
  getpost(i, tail);
  post.push_back(pre[root]);
}

void printpost()
{
  cout << post[0];
  for(int i=1;i<n;++i)
    cout << ' ' << post[i];
  cout << endl;
}

void solve()
{
	cin >> n;

  pre.resize(n);

	for (int i=0; i<n; ++i)
		cin >> pre[i];

  getpost(0, n-1);
  if (post.size() != n)
  {
    mirror = 1;
    post.clear();
    getpost(0, n-1);
    if (post.size() != n)
      cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      printpost();
    }
  }
  else
  {
    cout << "YES" << endl;
    printpost();
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
