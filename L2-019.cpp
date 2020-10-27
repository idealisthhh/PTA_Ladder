#include <bits/stdc++.h>
#define MAXN  10002
#define Inf 0x7FFFFFFE
typedef long long LL;
using namespace std;

// #define idealist 1
#define singletest 1

/**********************************
 * 考察 STL map 的运用。
***********************************/

/*******************   CODE   *********************/

int n, m;
map<string, int> ppp;
set<string> rec;

void solve()
{
  cin >> n;
  string tmp;
  for (int i=0; i<n; ++i)
  {
    cin >> tmp;
    rec.insert(tmp);
  }
  cin >> m;
  double x, tot = 0;
  for (int i=0; i<m; i++)
  {
    cin >> tmp;
    cin >> x;
    tot += x;
    ppp[tmp]= x;
  }
  tot /= m;
  map<string, int>::iterator it;

  int f = 0;
  for (it=ppp.begin();it!=ppp.end();++it)
    if (rec.count(it->first) == 0 && it->second > tot)
      {
        cout << it->first << endl;
        f = 1;
      }
  
  if (!f)
    cout << "Bing Mei You" << endl;
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

