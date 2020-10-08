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


void solve()
{
  int res = -1;
  string str, com;
  string a[MAXN];

  getline(cin, str);

  int ls = str.size();

  for (int i = 0; i<ls; ++i)
  {
    for(int j = 0; j<=i; ++j)
    {
      a[j] += str[i];
      com = a[j];
      reverse(com.begin(), com.end());
      int jul = com.size();

      if (com == a[j] && jul > res)
        res = jul;
      
    }
  }
  cout << res << endl;
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

