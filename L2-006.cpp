/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 

/*
 * 由后序可以确定根节点的位置，然后通过确定该根节点在中序的位置，判断其左右子树，递归判断。
 * 这里使用结构体建树，可以减小空间复杂度，再采用广度优先遍历树。
 */


#include <bits/stdc++.h>
using namespace std;
#define MAXN  10002
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n;
int mid[32];
int post[32];

struct pta
{
  int l, r;
} num[32];


int ans(int ind, int mids, int mide, int posts, int poste)
{
  int i;
  if (posts > poste)
    return -1;
  for (i=mids; i<=mide; ++i)
    if (mid[i] == post[poste])
      break;

  if (posts == poste)
    return posts;

  num[poste].r = ans(2*ind+1, i+1, mide, posts+i-mids, poste-1);
  num[poste].l = ans(2*ind, mids, i-1, posts, posts+i-mids-1);

  return poste;
}

void printtree()
{
  int temp;

  cout << post[n];
  queue<int> rec;
  rec.push(n);

  while (!rec.empty())
  {
    temp = rec.front();
    rec.pop();

    if (num[temp].l > 0)
    {
      cout << ' ' << post[num[temp].l];
      rec.push(num[temp].l);
    }

    if (num[temp].r > 0)
    {
      cout << ' ' << post[num[temp].r];
      rec.push(num[temp].r);
    }
  }
}

void solve()
{
  cin >> n;

  for(int i=1; i<=n; ++i)  
    cin >> post[i];
  for(int i=1; i<=n; ++i)  
    cin >> mid[i];

  ans(1, 1, n, 1, n);

  printtree();

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

