#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int n, m, ans;

void dfs(vector<int> &v) {
  int sum = 0, i = 0, j = 0;
  for (;;) {
    if (sum >= m)
      sum -= v[i++];
    else {
      if (j == n)
        return;
      sum += v[j++];
    }
    if (sum == m)
      ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    ans = 0;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    dfs(v);
    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}