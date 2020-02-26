#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;

  bool operator<(const Pos &p) const {
    if (j == p.j)
      return i < p.i;
    return j < p.j;
  }
};

int N, M, L;
int s[100001];
Pos a[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N >> L;
  for (int i = 0; i < M; i++)
    cin >> s[i];

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {y, x};
  }

  sort(a, a + N);
  sort(s, s + M);
  int p = 0, q = 0, ans = 0;
  for (; p < N; p++) {
    while (q < M - 1 && abs(a[p].j - s[q]) > abs(a[p].j - s[q + 1]))
      q++;

    // cout << a[p].j << ' ' << a[p].i << ' ' << s[q] << '\n';
    if (abs(a[p].j - s[q]) + a[p].i <= L) {
      ans++;
    }
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}