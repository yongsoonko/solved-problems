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

  int tc = 1;
  for (int i = tc; i--;) {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int j = 0; j < n; j++)
      cin >> v[j];

    int ans = 0;
    auto it = v.rbegin();
    while (k != 0) {
      if (k >= *it) {
        ans += k / *it;
        k %= *it;
      } else
        it++;
    }

    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}