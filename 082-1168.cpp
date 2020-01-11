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

  int n, k;
  cin >> n >> k;

  vector<int> v;
  v.reserve(n);
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }

  int idx = k - 1;
  cout << '<' << v[idx];
  v.erase(v.begin() + idx);
  if(v.size() > 0)
    idx %= v.size();
  while (v.size() > 0) {
    idx += k - 1;
    idx %= v.size();
    cout << ", " << v[idx];
    v.erase(v.begin() + idx);
    if (v.size() > 0)
      idx %= v.size();
  }
  cout << '>';

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
