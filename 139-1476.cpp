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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int e, s, m;
  cin >> e >> s >> m;

  int _e = 1, _s = 1, _m = 1;
  for (int i = 1;; i++) {
    if (_e == e && _s == s && _m == m) {
      cout << i << '\n';
      break;
    }
    if (_e++ == 15)
      _e = 1;
    if (_s++ == 28)
      _s = 1;
    if (_m++ == 19)
      _m = 1;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}