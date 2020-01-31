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

int f, s, g, u, d;

string bfs(vector<bool> &vertex) {
  int prev_allot = 1, next_allot = 0, traversal_cnt = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    prev_allot--;
    if (now + u <= f && !vertex[now + u]) {
      vertex[now + u] = true;
      q.push(now + u);
      next_allot++;
    }
    if (now - d >= 0 && !vertex[now - d]) {
      vertex[now - d] = true;
      q.push(now - d);
      next_allot++;
    }
    if (!prev_allot) {
      prev_allot = next_allot;
      next_allot = 0;
      traversal_cnt++;
      if (vertex[g])
        return to_string(traversal_cnt);
    }
  }
  return "use the stairs";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {

    cin >> f >> s >> g >> u >> d;
    vector<bool> vertex(f + 1, false);
    vertex[s] = true;
    if (s == g)
      cout << 0;
    else
      cout << bfs(vertex);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}