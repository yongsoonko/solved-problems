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
  if (size == 1) {
    v[si][sj] = '*';
    return;
  }

  for (int i = 0; i < size; i += size / 3)
    for (int j = 0; j < size; j += size / 3) {
      if (i == size / 3 && j == size / 3)
        continue;
      dq(v, si + i, sj + j, size / 3);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<vector<char>> v(n, vector<char>(n, ' '));
  dq(v, 0, 0, n);
  for (auto a : v) {
    for (char ch : a)
      cout << ch;
    cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}