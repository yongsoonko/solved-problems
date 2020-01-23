#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pair<int, string> dq(vector<string> &v, int si, int sj, int size) {
  if (size == 1)
    return {v[si][sj] - '0', to_string(v[si][sj] - '0')};

  int cnt[3] = {
      0,
  };
  string ans;

  for (int i = 0; i < size; i += size / 2)
    for (int j = 0; j < size; j += size / 2) {
      auto p = dq(v, si + i, sj + j, size / 2);
      cnt[p.first]++;
      ans += p.second;
    }

  for (int i = 0; i < 2; i++)
    if (cnt[i] == 4)
      return {i, to_string(i)};

  return {2, '(' + ans + ')'};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  cout << dq(v, 0, 0, n).second;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}