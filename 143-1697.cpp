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

  int _tc = 1;
  // Answer: 4 6 5 5 5 6
  for (int _i = _tc; _i--;) {
    int n, k;
    cin >> n >> k;

    vector<int> v(100001);
    for (int i = 0; i <= 100000; i++) {
      if (n - i >= 0)
        v[n - i] = i;
      if (n + i <= 100000)
        v[n + i] = i;
    }

    for (int i = n; i <= 100000 && i <= 2 * k; i++) {
      if (i - 1 >= 0)
        v[i] = min(v[i], v[i - 1] + 1);
      if (i + i <= 100000)
        v[i] = min(v[i], v[i + 1] + 1);
      if (i % 2 == 0)
        v[i] = min(v[i], v[i / 2] + 1);

      if (i - 1 >= 0)
        v[i - 1] = min(v[i - 1], v[i] + 1);
      if (i + 1 <= 100000)
        v[i + 1] = min(v[i + 1], v[i] + 1);
      if (i <= 50000)
        v[2 * i] = min(v[2 * i], v[i] + 1);
    }

    // for (int i = 0; i < 100; i++)
    //   cout << i << ' ' << v[i] << '\n';
    // cout << '\n';
    cout << v[k] << ' ';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}