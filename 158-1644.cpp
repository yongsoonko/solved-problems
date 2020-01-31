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

int n, ans;

void solve(vector<int> &v) {
  int i = 0, j = 0, sum = 0, size = v.size();
  for (;;) {
    if (sum >= n) {
      if (sum == n)
        ans++;
      sum -= v[i++];
    } else {
      if (j == size)
        break;
      sum += v[j++];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    ans = 0;
    cin >> n;

    vector<int> v;
    vector<bool> vb(n + 1, true);

    vb[0] = vb[1] = false;
    for (int i = 2; i * i <= n; i++)
      if (vb[i])
        for (int j = i + i; j <= n; j += i)
          vb[j] = false;

    v.reserve(283146);
    for (int i = 0; i <= n; i++)
      if (vb[i])
        v.push_back(i);

    solve(v);
    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}