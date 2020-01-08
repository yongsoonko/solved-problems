#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, cnt;
  cin >> n;
  cnt = n;

  vector<int> v;
  v.reserve(n);

  for (int i = 0; i < n; i++) {
    v.push_back(i + 1);
  }

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  for (int i = 2; i * i <= n; i++) {
    v[i * i - 1] = 1;
  }

  for (int i = 3; i < n; i++) {
    for (int j = 1; j * j < i; j++) {
      v[i] = min(v[i], v[i - j * j] + 1);
    }
  }
  cout << v[n - 1];

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
