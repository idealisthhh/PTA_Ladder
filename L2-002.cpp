/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, sid, sdid;
int nid[MAXN];
int val[MAXN];
int id1[MAXN];
int id2[MAXN];
int del[MAXN];

int rec[10002];

void solve()
{
  sdid = -1;
  int tid, va, id;
  cin >> sid >> n;

  for (int i=0; i<n; ++i)
  {
    cin >> tid >> va >> id;
    nid[tid] = id;
    val[tid] = va;
    rec[abs(va)] = 1;
  }

  tid = sid;
  while (tid != -1)
  {
    va = abs(val[tid]);
    if (rec[va] != 1)
      del[tid] = 1;
    else
      rec[va]--;
    tid = nid[tid];
  }

  tid = sid;
  int rid = nid[tid];
  int rrid = -1;

  while (tid != -1)
  {
    while (rid != -1 && del[rid] == 1)
    {
      if (sdid == -1)
        sdid = rid;

      if (rrid != -1)
        id2[rrid] = rid;
      rrid = rid;
      rid = nid[rid];
    }
    
    id1[tid] = rid;
    tid = rid;
    if (rid != -1)
      rid = nid[tid];
  }
  id2[rrid] = -1;
  // tid = sdid;
  // rid = tid;
  // int rrid = -1;
  // while (tid != -1)
  // {
  //   while (del[rid] == 1)
  //   {
  //     rrid = rid;
  //     rid = nid[rid];
  //   }

  // }

  tid = sid;
  while (tid != -1)
  {
    if (id1[tid] != -1)
      printf("%05d %d %05d\n", tid, val[tid], id1[tid]);
    else
      printf("%05d %d %d\n", tid, val[tid], id1[tid]);
    tid = id1[tid];
  }


  tid = sdid;
  while (tid != -1)
  {
    if (id2[tid] != -1)
      printf("%05d %d %05d\n", tid, val[tid], id2[tid]);
    else
      printf("%05d %d %d\n", tid, val[tid], id2[tid]);
    tid = id2[tid];
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

