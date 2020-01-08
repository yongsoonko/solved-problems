#include <iostream>
#include <map>
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
  vector<int> v;
  map<int, int> m;
  cin >> n;
  cnt = n;
  v.reserve(n);

  while (cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  m.insert(make_pair(0, 1));
  int ans = 1;
  for (int i = 1; i < n; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      if (v[i] < v[j]) {
        if(max < m[j]) {
          max = m[j];
        }
      }
    }
    if(ans < max + 1) {
      ans = max + 1;
    }
    m.insert(make_pair(i, max + 1));
  }

  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
