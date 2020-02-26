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
};

int D1, D2;
int chk[2001][2001];
int cache[2001][2001];

int gcd(int a, int b) {
  if (cache[a][b])
    return cache[a][b];
  if (b == 0)
    return a;
  return cache[a][b] = gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int ans = 0;
  cin >> D1 >> D2;
  for (int i = D1; i <= D2; i++)
    for (int j = 1; j <= i; j++) {
      int tmp = gcd(i, j);
      if (tmp > 1) {
        if (!chk[j / tmp][i / tmp]) {
          ans++;
          chk[j / tmp][i / tmp] = 1;
        }
      } else if (!chk[j][i]) {
        ans++;
        chk[j][i] = 1;
      }
    }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}