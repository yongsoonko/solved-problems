#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, k;
  cin >> n >> k;
  vector<int> v;
  v.reserve(n);
  for(int i=n; i--;) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());
  cout << v[k-1];

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
