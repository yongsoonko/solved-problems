#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j])
      cout << a[i++] << ' ';
    else
      cout << b[j++] << ' ';
  }
  while (i < a.size())
    cout << a[i++] << ' ';
  while (j < b.size())
    cout << b[j++] << ' ';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}