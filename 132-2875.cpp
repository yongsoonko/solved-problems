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

  int n, m, k;
  cin >> n >> m >> k;

  int ans = -1;
  for (int i = 0; i <= k; i++)
    ans = max(min((n - i) / 2, m - (k - i)), ans);

  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}