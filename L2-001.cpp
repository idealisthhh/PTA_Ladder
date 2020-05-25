/*
 * @Author: Haohui Lee
 * @Github: harveyleeh@163.com
 * @Blog: harveyl.cn
 * @Date: 2020-03-29 22:44:32
 */ 
#include <bits/stdc++.h>
using namespace std;
#define MAXN  505

// #define idealist 1

#define singletest 1

const int Inf = 0x7FFFFFFE;

/*******************   CODE   *********************/

int n, k, s, e;
int dis[MAXN];
int w[MAXN][MAXN];
int cw[MAXN];
int pre[MAXN], weight[MAXN], num[MAXN];

set<int> vised;

int least()
{
	int resi = -1;
	int res = Inf + 1;
	for(int i=0; i<n; i++)
		if(vised.count(i) == 0)
			if (dis[i] < res)
			{
				resi = i;
				res = dis[i];
			}

	vised.insert(resi);
	return resi;
}

int Dijkstra(int s, int e)
{
	for(int i=0; i<n; i++)
		dis[i] = Inf;
	dis[s] = 0;
	num[s] = 1;
	weight[s] = cw[s];
	while (!vised.count(e))
	{
		int u = least();
		for(int i=0; i<n; i++)
		{
			if (vised.count(i) == 0)
			{
				if (dis[u]+w[u][i] < dis[i] && w[u][i] != 0)
				{
					weight[i] = weight[u] + cw[i];
					num[i] = num[u];
					dis[i] = dis[u] + w[u][i];
					pre[i] = u;
				}
				else if (dis[u]+w[u][i] == dis[i] && w[u][i] != 0)
				{
					num[i] += num[u];
					if (weight[u] + cw[i] > weight[i])
					{
						weight[i] = weight[u] + cw[i];
						pre[i] = u;
					}
				}
			}
		}
	}
	return dis[e];
}

void myprint(int c)
{
	if (c == s)
	{
		printf("%d", s);
		return;
	}
	myprint(pre[c]);
	printf(" %d", c);
}
void solve()
{
	cin >> n >> k >> s >> e;
	for(int i=0;i<n;i++)
		cin >> cw[i];
	
	int u, v, x;
	for(int i=0; i<k; ++i)
	{
		cin >> u >> v >> x;
		w[u][v] = w[v][u] = x;
	}
	
	Dijkstra(s, e);

	printf("%d %d\n", num[e], weight[e]);
	myprint(e);
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

