#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int m, n;
  cin >> m >> n;

  // 소수인 경우 true
  vector<bool> v(n + 1, true);
  v[1] = false;

  for (int i = 2; i <= sqrt(n); i++) {
    for (int j = i + i; j <= n; j += i) {
      v[j] = false;
    }
  }

  for (int i = m; i <= n; i++) {
    if (v[i])
      cout << i << ' ';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
