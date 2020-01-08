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

  int n, cnt;
  cin >> n;
  cnt = n;

  vector<pair<int, int>> v;
  v.reserve(n);
  while(cnt--) {
    int input, input2;
    cin >> input >> input2;

    v.push_back(make_pair(input2, input));
  }

  sort(v.begin(), v.end());
  for(auto a: v) {
    cout << a.second << ' ' << a.first << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
