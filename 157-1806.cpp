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

int n, s, ans = 1e9;

void solve(vector<int> &v) {
  int i = 0, j = 0, sum = 0;
  for (;;) {
    if (sum < s) {
      if (j == n)
        break;
      sum += v[j++];
    } else {
      sum -= v[i++];
      ans = min(ans, j - i + 1);
    }
  }
  if (ans == 1e9)
    ans = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  solve(v);
  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}