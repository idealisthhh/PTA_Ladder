/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1002
#define Inf 0x7FFFFFFE

#define idealist 1
#define singletest 1

/*******************   CODE   *********************/

int n, m;
int x, y;
string str, tmp, pstr;
int heap[MAXN];
int tail = 1;

inline void update(int pos)
{
  while (pos >= 2 && heap[pos/2] > heap[pos])
  {
    swap(heap[pos], heap[pos/2]);
    pos /= 2;
  }
}

int findnode(int val)
{
  int i;
  for (i=1; i<=n; ++i)
    if (heap[i] == val)
      break;
  return i;
}

void solve()
{
  cin >> n >> m;
  int t;
  for (int i=1; i<=n; ++i)
  {
    cin >> t;
    heap[i] = t;
    update(i);
  }

  int t1, t2;

  while (m--)
  {
    cin >> x >> str;
    if (str == "and")
      cin >> y >> tmp >> pstr;
    else
    {
      cin >> tmp >> pstr;
      if (pstr != "root")
        cin >> tmp >> y;
    }
    
    t1 = findnode(x);
    if (pstr != "root")
      t2 = findnode(y);
    
    if (pstr == "root")
      printf((t1==1) ? "T":"F");
    else if (pstr == "siblings")
      printf((t1/2 == t2/2) ? "T":"F");
    else if (pstr == "parent")
      printf((t1 == t2/2) ? "T":"F");
    else
      printf((t1/2 == t2) ? "T":"F");
    printf("\n");
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

