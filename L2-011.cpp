/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  10000005
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, k;
int LNR[32];
int NLR[32];
int node[MAXN];

void setorder(int pos, int preS, int inS, int preE, int inE)
{
  if (inS > inE)  return;
  int f = NLR[preS];
  node[pos] = f;
  int t = inS;
  while (LNR[t] != f) t++;
  int l = t - inS;
  setorder(2*pos+1, preS+1, inS, preE+l, t-1);
  setorder(2*pos, l+preS+1, t+1, preE, inE);
}

void solve()
{
  int x;
  memset(node, 0, sizeof(node));
  cin >> n;
  for (int i=1; i<=n; ++i)
  {
    cin >> x;
    LNR[i] = x;
  }

  for (int i=1; i<=n; ++i)
  {
    cin >> x;
    NLR[i] = x;
  }
  int j = 2;
  setorder(1,1,1,n,n);
  printf("%d", node[1]);
  for (int i=1; i<n; ++i)
  {
    while(node[j]==0) ++j;
    printf(" %d", node[j++]);
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

