#include <bits/stdc++.h>
using namespace std;
#define MAXN  100002
#define Inf 0x7FFFFFFE
typedef long long LL;

// #define idealist 1
#define singletest 1

/*
* 排序算法如何写，同时排名（有并列） 如何输出
*/


/*******************   CODE   *********************/

int n, m, k;

struct pta
{
  string name;
  int score; 
} stu[MAXN];

int cmp(pta a, pta b)
{
  if (a.score == b.score)
    return a.name < b.name;
  return a.score > b.score;
}

void solve()
{
  int tot = 0, tg;
  cin >> n >> m >> k;
  for (int i=0; i<n; ++i)
  {
    cin >> stu[i].name >> tg;
    stu[i].score = tg;
    if (tg >= m)
      tot += 50;
    else if (tg >= 60 && tg < m)
      tot += 20;
  }
  
  sort(stu, stu+n, cmp);
  cout << tot << endl;
  int sss = 1, pres = stu[0].score, rec = 1;
  printf("%d %s %d\n", sss, stu[0].name.c_str(), stu[0].score);
  for (int i=1; i<n; ++i)
  {
    if (stu[i].score == pres)
      rec++;
    else
    {
      sss += rec;
      rec = 1;
    }
    
    if (sss > k)
      break;

    printf("%d %s %d\n", sss, stu[i].name.c_str(), stu[i].score);
    
    pres = stu[i].score;
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

