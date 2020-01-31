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

int n, s;
ll ans;

void solve(vector<int> &v, int begin, int add, vector<ll> &sum) {
  if (begin == n)
    return;
  for (int i = begin; i < n; i++) {
    sum[add + v[i] + 2000000]++;
    solve(v, i + 1, add + v[i], sum);
  }
}

void solve_small(vector<int> &v, int begin, int add) {
  if (begin == n)
    return;
  for (int i = begin; i < n; i++) {
    if (add + v[i] == s)
      ans++;
    if (add + v[i] > s && v[i] >= 0)
      return;
    solve_small(v, i + 1, add + v[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int tc = 1;
  for (int i = tc; i--;) {
    ans = 0;
    cin >> n >> s;

    if (n > 20) {
      vector<int> v(20), v2(n - 20);
      vector<ll> sum(4000001, 0), sum2(4000001, 0);
      for (int i = 0; i < 20; i++)
        cin >> v[i];
      for (int i = 0; i < n - 20; i++)
        cin >> v2[i];

      int tmp = n;
      n = 20;
      solve(v, 0, 0, sum);
      n = tmp - 20;
      solve(v2, 0, 0, sum2);

      ans += sum[s + 2000000] + sum2[s + 2000000];
      for (int i = -2000000; i <= 2000000; ++i) {
        int ni = s - i + 2000000;
        if (ni >= 0 && ni <= 4000000)
          ans += sum[i + 2000000] * sum2[ni];
      }

      // Answer: 129024480
      // Answer: 137846528819
      cout << ans;
    } else {
      vector<int> v(n);
      for (int i = 0; i < n; i++)
        cin >> v[i];

      sort(v.begin(), v.end());
      solve_small(v, 0, 0);

      cout << ans;
    }
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}