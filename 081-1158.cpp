#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, k;
  cin >> n >> k;
  queue<int> q;
  vector<int> v;
  v.reserve(n);
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  int cnt = 1;
  while (!q.empty()) {
    int tmp = q.front();
    if (cnt++ % k == 0) {
      q.pop();
      v.push_back(tmp);
    } else {
      q.pop();
      q.push(tmp);
    }
  }

  cout << '<';
  for (int i = 0; i < n; i++) {
    if (i < n - 1)
      cout << v[i] << ", ";
    else
      cout << v[i] << '>';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
