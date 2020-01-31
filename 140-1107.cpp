#include <algorithm>
#include <cmath>
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

  vector<string> vs(1000001);
  for (int i = 0; i <= 1000000; i++)
    vs[i] = to_string(i);

  int tc = 1;
  for (int i = tc; i--;) {
    int n, m;
    cin >> n >> m;

    bool brk[10] = {
        0,
    };
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      brk[a] = 1;
    }

    int ans = abs(n - 100);
    for (int i = 0; i <= 500000; i++) {
      if (n + i <= 1000000) {
        string num = vs[n + i];
        int len = num.length(), j = 0;
        for (; j < len; j++)
          if (brk[num[j] - '0'])
            break;
        if (j == len)
          ans = min(ans, len + i);
      }
      if (n - i >= 0) {
        string num = vs[n - i];
        int len = num.length(), j = 0;
        for (; j < len; j++)
          if (brk[num[j] - '0'])
            break;
        if (j == len)
          ans = min(ans, len + i);
      }
    }
    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}