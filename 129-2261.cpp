#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll INF = 1e9;

double distance(const pll &a, const pll &b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

bool comp(const pll &a, const pll &b) {
  return a.first < b.first;
}

bool comp_ysort(const pll &a, const pll &b) {
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<pll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;

  stable_sort(v.begin(), v.end());

  double min_dist = distance(v[0], v[1]);
  auto _begin = v.begin(), _end = v.end();
  for (int i = 0; i < n; i++) {
    pll dist = {v[i].first + min_dist, v[i].second};
    pll dist_ybound_down = {v[i].first, v[i].second - min_dist};
    pll dist_ybound_up = {v[i].first, v[i].second + min_dist};
    int idx = upper_bound(_begin + i + 1, _end, dist, comp) - _begin;
    int idx_ybound_down = lower_bound(_begin + i + 1, _begin + idx, dist_ybound_down, comp_ysort) - _begin;
    int idx_ybound_up = upper_bound(_begin + i + 1, _begin + idx, dist_ybound_up, comp_ysort) - _begin;

    // cout << idx << '\t' << idx_ybound_down << '\t' << idx_ybound_up << '\n';
    for (int j = idx_ybound_down; j < idx_ybound_up; j++) {
      double tmp_dist = distance(v[i], v[j]);
      min_dist = min(min_dist, tmp_dist);
    }
  }

  cout << setprecision(12);
  cout << round(min_dist * min_dist);
  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}