#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int ans[4] = {
    0,
};
int dq(vector<vector<int>> &v, int si, int sj, int size) {
  if (size == 1)
    return v[si][sj];

  int cnt[4] = {
      0,
  };
  for (int i = 0; i < size; i += size / 3)
    for (int j = 0; j < size; j += size / 3)
      cnt[dq(v, si + i, sj + j, size / 3) + 1]++;

  for (int i = 0; i <= 2; i++)
    if (cnt[i] == 9)
      return i - 1;

  for (int i = 0; i <= 2; i++)
    ans[i] += cnt[i];
  return 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<vector<int>> v(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> v[i][j];

  ans[dq(v, 1, 1, n) + 1]++;
  for (int i = 0; i <= 2; i++)
    cout << ans[i] << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}