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
    int n, m;
    cin >> n >> m;

    if (n == 1)
      cout << 1;
    else if (n == 2)
      cout << min((m - 1) / 2 + 1, 4);
    // n이 3이상인 경우
    else {
      if (m >= 7)
        cout << 5 + m - 7;
      else
        cout << min(m, 4);
    }
    cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}