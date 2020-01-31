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

  int n, s, ans = 0;
  cin >> n >> s;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i = 0; i < n; i++) {
    vector<int> v2(n - i, 1);
    for (int j = 0; j < i; j++)
      v2.push_back(0);

    do {
      int sum = 0;
      for (int i = 0; i < n; i++)
        if (v2[i])
          sum += v[i];

      if (sum == s)
        ans++;
    } while (prev_permutation(v2.begin(), v2.end()));
  }

  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}