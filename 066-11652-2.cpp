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

  int n;
  cin >> n;

  vector<long long> v;
  v.reserve(n);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  int cnt = 1, ans = 1;
  long long ans2 = v[0];

  for (int i = 1; i < n; i++) {
    if (v[i - 1] == v[i]) {
      cnt++;
    } else {
      cnt = 1;
    }
    if (ans < cnt) {
      ans = cnt;
      ans2 = v[i];
    }
  }

  // cout << "ans : " << ans << " ans2 : " << ans2;
  cout << ans2;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
