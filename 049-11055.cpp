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

  // m.insert(make_pair(-1, 0));
  m.insert(make_pair(0, v[0]));
  for (int i = 1; i < n; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i]) {
        if (max < m[j]) {
          max = m[j];
        }
      }
    }
    m.insert(make_pair(i, max + v[i]));
  }

  int max = -1;  
  for(int i=0; i<n; i++) {
    if(max < m[i]) {
      max = m[i];
    }
  }

  cout << max;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
