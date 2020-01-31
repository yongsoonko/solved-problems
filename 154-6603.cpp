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

  int k;
  cin >> k;
  while (k != 0) {
    vector<int> v(k), v2(6, 1);
    for (int i = 0; i < k; i++)
      cin >> v[i];
    for (int i = 0; i < k - 6; i++)
      v2.push_back(0);

    do {
      vector<int> v3;
      for (int i = 0; i < k; i++)
        if (v2[i] == 1)
          v3.push_back(v[i]);

      for (int i : v3)
        cout << i << ' ';
      cout << '\n';
    } while (prev_permutation(v2.begin(), v2.end()));
    cout << '\n';
    cin >> k;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}