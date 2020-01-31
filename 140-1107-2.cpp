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

  int _tc = 1;
  for (int _i = _tc; _i--;) {
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

    int ans = abs(n - 100), j = 0, k = 0, len_j, len_k;
    for (int i = 0; i <= 500000; i++) {
      if (n + i <= 1000000) {
        string num = to_string(n + i);
        len_j = num.length();
        for (j = 0; j < len_j; j++)
          if (brk[num[j] - '0'])
            break;
        if (j == len_j)
          ans = min(ans, len_j + i);
      }
      if (n - i >= 0) {
        string num = to_string(n - i);
        len_k = num.length();
        for (k = 0; k < len_k; k++)
          if (brk[num[k] - '0'])
            break;
        if (k == len_k)
          ans = min(ans, len_k + i);
      }
      if (j == len_j || k == len_k)
        break;
    }
    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}