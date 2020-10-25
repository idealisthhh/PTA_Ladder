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

int n, need;
double x;
struct pta
{
	double num;
	double price;
	double unit;
} cakes[MAXN];

int cmp(pta a, pta b)
{
	return a.unit > b.unit;
}

void solve()
{	
	cin >> n >> need;
	for (int i=0; i<n; ++i)
		cin >> cakes[i].num;
	
	for (int i=0; i<n; ++i)
	{
		cin >> x;
		cakes[i].price = x;
		cakes[i].unit = 1.0 * x / cakes[i].num;
	}
		
	sort(cakes, cakes+n, cmp);

	double res = 0;
	for(int i=0; i<n; ++i)
	{
		if (need <= cakes[i].num)
		{
			res += need * cakes[i].unit;
			break;
		}
		res += cakes[i].num * cakes[i].unit;
		need -= cakes[i].num;
	}
	printf("%.2lf\n", res);
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

