/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  10002
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int N, K;

struct pta
{
  int no;
  int num;
  float money;
} bbb[MAXN];


bool compare(pta a, pta b)
{
  if (a.money == b.money)
  {
    if (a.num == b.num)
      return a.no < b.no;
    else
      return a.num > b.num;
  }
  return a.money > b.money;
}

void solve()
{
  int nk;
  float pk;
  memset(bbb, 0, sizeof(bbb));

  cin >> N;

  for (int i=1; i<=N; ++i)
  {
    bbb[i].no = i;
    cin >> K;
    for (int j=0; j<K; ++j)
    {
      cin >> nk >> pk;
      bbb[nk].num++;
      bbb[nk].money += pk;
      bbb[i].money -= pk;
    }
  }

  sort(bbb+1, bbb+N+1, compare);

  for (int i=1; i<=N; ++i)
    printf("%d %.2f\n", bbb[i].no, bbb[i].money/100);
  
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

