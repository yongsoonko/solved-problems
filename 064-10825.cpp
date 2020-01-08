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

  vector<pair<int, pair<int, pair<int, string>>>> v(n);
  for (int i = 0; i < n; i++) {
    string a;
    int b, c, d;
    cin >> a >> b >> c >> d;

    v[i] = make_pair(b, make_pair(c, make_pair(d, a)));
  }

  stable_sort(
      v.begin(),
      v.end(),
      [](auto a, auto b) -> bool 
      { return a.second.second.second < b.second.second.second; }
  );

  stable_sort(
      v.begin(),
      v.end(),
      [](auto a, auto b) -> bool 
      { return a.second.second.first > b.second.second.first; }
  );

  stable_sort(
      v.begin(),
      v.end(),
      [](auto a, auto b) -> bool 
      { return a.second.first < b.second.first; }
  );

  stable_sort(
      v.begin(),
      v.end(),
      [](auto a, auto b) -> bool 
      { return a.first > b.first; }
  );

  for (int i = 0; i < n; i++) {
    cout << v[i].second.second.second << '\n';
    // cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second.first << ' ' << v[i].second.second.second << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
