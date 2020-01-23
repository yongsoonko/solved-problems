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

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  int llimit = v[0].first, rlimit = v[0].second, ans = rlimit - llimit;
  for (int i = 1; i < n; i++) {
    int first = v[i].first, second = v[i].second;
    if (first >= llimit && first <= rlimit)
      if (second > rlimit) {
        ans += second - rlimit;
        rlimit = second;
      } else;
    else {
      ans += second - first;
      llimit = first;
      rlimit = second;
    }
  }

  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}