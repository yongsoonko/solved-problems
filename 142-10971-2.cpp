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

bool next_permute(vector<int>::iterator begin, vector<int>::iterator end) {
  int idx = -1;
  for (auto it = begin; it != end - 1; it++) {
    if (*it < *(it + 1))
      idx = it - begin;
  }
  if (idx == -1)
    return false;
  for (auto it = end - 1;; it--) {
    if (*it > *(begin + idx)) {
      swap(*it, *(begin + idx));
      break;
    }
  }
  reverse(begin + idx + 1, end);
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    int n, ans = 1e9;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> cost[i][j];

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = i;

    sort(v.begin(), v.end());
    do {
      int sum = 0, i = 0;
      for (; i < n; i++) {
        if (!cost[v[i]][v[(i + 1) % n]])
          break;
        sum += cost[v[i]][v[(i + 1) % n]];
      }
      if (i == n)
        ans = min(ans, sum);
    } while (next_permute(v.begin(), v.end()));

    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}