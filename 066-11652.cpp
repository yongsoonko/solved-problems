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
  v.push_back(9223372036854775807LL);
  
  // for(auto a: v) {
  //   cout << a << '\n';
  // }

  vector<pair<int, long long>> v2;
  v2.reserve(n);
  long long tmp = v[0];
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (tmp == v[i + 1]) {
      cnt++;
    } else {
      v2.push_back(make_pair(cnt, v[i]));
      tmp = v[i + 1];
      cnt = 1;
    }
  }

  // for(auto a: v2) {
  //   cout << a.first << ' ' << a.second << '\n';
  // }

  stable_sort(v2.begin(), v2.end(), [](auto a, auto b) -> bool {
    return a.second < b.second;
  });
  stable_sort(v2.begin(), v2.end(), [](auto a, auto b) -> bool {
    return a.first > b.first;
  });
  cout << v2[0].second;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
