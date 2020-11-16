#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<int> photo[1005];
double rela[1005], relb[1005];
int gender[1005];

int main()
{
  cin >> n >> m;
  string str;
  int x, a, b;
  for (int i=0; i<m;++i)
  {
    cin >> k;
    while(k--)
    {
      cin >> str;
      x = abs(atoi(str.c_str()));
      gender[x] = (str[0] != '-');
      photo[i].push_back(x);   
    }
  }
  cin >> a >> b;
  a = abs(a), b = abs(b);
  int finda, findb;

  for (int i=0; i<m; ++i)
  {
    finda = (find(photo[i].begin(), photo[i].end(), a) != photo[i].end());
    findb = (find(photo[i].begin(), photo[i].end(), b) != photo[i].end());
    if (finda || findb)
    {
      int l = photo[i].size();
      for (int j=0; j<l; ++j)
      {
        x = photo[i][j];
        if (finda && gender[x] != gender[a])
          rela[x] += 1.0/l;
        if (findb && gender[x] != gender[b])
          relb[x] += 1.0/l;
      }
    }
  }

  double maxa = -1.0, maxb = -1.0;
  
  for (int i=0; i<n; ++i)
  {
    maxa = max(maxa, rela[i]);
    maxb = max(maxb, relb[i]);
  }
  
  if (rela[b] == maxa && relb[a] == maxb)
  {
    if (gender[a] == 0) cout << '-';
    cout << a << ' ';
    if (gender[b] == 0) cout << '-';
    cout << b << endl;
  }
  else
  {
    for (int i=0; i<n; ++i)
      if (rela[i] == maxa)
      {
        if (gender[a] == 0) cout << '-';
        cout << a << ' ';
        if (gender[i] == 0) cout << '-';
        cout << i << endl;
      }
    for (int i=0; i<n; ++i)
      if (relb[i] == maxb)
      {
        if (gender[b] == 0) cout << '-';
        cout << b << ' ';
        if (gender[i] == 0) cout << '-';
        cout << i << endl;
      }
  }
  
}
