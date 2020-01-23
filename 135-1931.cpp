#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;
  vector<pii> v(n);
  for(int i=0; i<n; i++)
    cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());

  int end, ans = 0;
  for(auto it=v.begin(); it!=v.end(); it++)
    // 초기화 할 때 아래와 같이 많이 작성 한다.
    if(it == v.begin() || end <= it->second) {
      end = it->first;
      ans++;
    }

  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}