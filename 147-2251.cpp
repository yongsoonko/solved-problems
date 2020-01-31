#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

ai3 capacity;

set<int> bfs(ai3 now, set<ai3> &vertex) {
  queue<ai3> q;
  set<int> ans;
  vertex.insert(now);
  q.push(now);
  ans.insert(now[2]);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++) {
        if (i == j)
          continue;
        int moved_liter = min(now[i], capacity[j] - now[j]);
        ai3 next = now;
        next[i] -= moved_liter;
        next[j] += moved_liter;
        if (vertex.find(next) == vertex.end()) {
          vertex.insert(next);
          q.push(next);
          if (!next[0])
            ans.insert(next[2]);
        }
      }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    ai3 now;
    cin >> capacity[0] >> capacity[1] >> capacity[2];

    set<ai3> vertex;
    set<int> liter = bfs({0, 0, capacity[2]}, vertex);
    for (int i : liter)
      cout << i << ' ';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}