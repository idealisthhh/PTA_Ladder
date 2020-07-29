/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  102
#define Inf 0x7FFFFFFE

// #define idealist 1

#define singletest 1

/*******************   CODE   *********************/

struct pta
{
  string name;
  int label;
  double aver;
} user[MAXN];

int n, k, x;
set<int> cache;

bool cmp(pta a, pta b)
{
  if (a.label == b.label)
    return a.aver > b.aver;
  
  return a.label > b.label;
}

void display()
{
  if (n>=3)
  {
    printf("%s %s %s", user[0].name.c_str(), user[1].name.c_str(), user[2].name.c_str());
    
  }
  else
  {
    if (n == 1)
      printf("%s - -", user[0].name.c_str());
    if (n == 2)
      printf("%s %s -", user[0].name.c_str(), user[1].name.c_str());
  }
}

void solve()
{
  cin >> n;
  for(int i=0; i<n; ++i)
  {
    cache.clear();
    cin >> user[i].name;
    cin >> k;
    for (int j=0; j<k; ++j)
    {
      cin >> x;
      if (!cache.count(x))
        ++user[i].label;
      cache.insert(x);
    }
    user[i].aver = user[i].label * 1.0 / k;
  }

  sort(user, user+n, cmp);
  display();
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

