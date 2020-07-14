/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 

/*
 * set 模板的灵活运用
 * 我们可以通过一些简单的分析就可以意识到，每次加入一个新的列车的时候都要有一些选择，1.加入之前的列车队伍或者2.自己重新开一个队伍。而第一个选择，我们又会遇到选择：加入哪个列车队伍最好。
 * 这时候 贪心算法就来了，我们选择列车序号和当前车最近的，这样可以大大的减少空的位置。考虑到 要对每个队伍的最后一个列车的序号进行排序 ，我们可以使用set 来减少我们代码实现的难度。
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE

#define idealist 1

#define singletest 1

/*******************   CODE   *********************/

int n, x;
set<int> road;

void solve()
{
  cin >> n;
  road.insert(MAXN);
  for (int i=0; i<n; i++)
  {
    cin >> x;
    if (x < *road.rbegin())
      road.erase(*road.upper_bound(x));
    road.insert(x);
  }

  cout << road.size() << endl;
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

