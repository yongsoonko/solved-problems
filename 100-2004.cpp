#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll=long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, m;
  cin >> n >> m;

  int n_m = n - m;
  int nCnt2 = 0, mCnt2 = 0, n_mCnt2 = 0;
  for (ll i = 2; i <= n; i *= 2) {
    nCnt2 += n / i;
    if (i <= m)
      mCnt2 += m / i;
    if (i <= n_m)
      n_mCnt2 += n_m / i;
  }

  int nCnt5 = 0, mCnt5 = 0, n_mCnt5 = 0;
  for (ll i = 5; i <= n; i *= 5) {
    nCnt5 += n / i;
    if (i <= m)
      mCnt5 += m / i;
    if (i <= n_m)
      n_mCnt5 += n_m / i;
  }
  cout << min(nCnt2 - mCnt2 - n_mCnt2, nCnt5 - mCnt5 - n_mCnt5);

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
