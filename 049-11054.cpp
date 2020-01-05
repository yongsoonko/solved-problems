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
  cin >> n;
  cnt = n;

  vector<int> v;
  map<int, int> m1, m2;
  v.reserve(n);

  while (cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  }
  
  m1.insert(make_pair(0, 1));
  for (int i = 1; i < n; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i]) {
        if (max < m1[j]) {
          max = m1[j];
        }
      }
    }
    m1.insert(make_pair(i, max + 1));
  }

  m2.insert(make_pair(n - 1, 1));
  for (int i = n - 2; i >= 0; i--) {
    int max = 0;
    for (int j = n - 1; j > i; j--) {
      if (v[j] < v[i]) {
        if (max < m2[j]) {
          max = m2[j];
        }
      }
    }
    m2.insert(make_pair(i, max + 1));
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans < m1[i] + m2[i] - 1) {
      ans = m1[i] + m2[i] - 1;
    }
  }
  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}

