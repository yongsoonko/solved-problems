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
  vector<vector<int>> t(3, vector<int>(n, 0));
  v.reserve(n);

  while (cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  t[1][0] = v[0];
  for (int i = 1; i < n; i++) {
    t[0][i] = t[1][i - 1] + v[i];
    t[1][i] = t[2][i - 1] + v[i];
    t[2][i] = max(t[0][i - 1], t[1][i - 1]);
  }

  cout << max(t[0][n - 1], t[1][n - 1]);

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  //   cout << "\ntime : " << _time;
}
