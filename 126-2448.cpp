#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void dq(vector<vector<char>> &v, int si, int sj, int size) {
  //    *
  //   * *
  //  *****
  if (size == 3) {
    v[si][sj] = v[si + 1][sj - 1] = v[si + 1][sj + 1] =
        v[si + 2][sj - 2] = v[si + 2][sj - 1] = v[si + 2][sj] =
            v[si + 2][sj + 1] = v[si + 2][sj + 2] = '*';
    return;
  }

  int half = size / 2;
  dq(v, si, sj, half);
  dq(v, si + half, sj - half, half);
  dq(v, si + half, sj + half, half);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<vector<char>> v(n, vector<char>(2 * n - 1, ' '));
  dq(v, 0, n - 1, n);

  for (auto a : v) {
    for (char ch : a)
      cout << ch;
    cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}