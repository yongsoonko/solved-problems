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

int bfs(int now, int arrival, vector<bool> &vertex) {
  int traversal_cnt = 0, prev_allot = 1, next_allot = 0;
  queue<int> q;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();
    prev_allot--;
    if (now - 1 >= 0 && !vertex[now - 1]) {
      vertex[now - 1] = true;
      q.push(now - 1);
      next_allot++;
    }
    if (now + 1 <= 100000 && !vertex[now + 1]) {
      vertex[now + 1] = true;
      q.push(now + 1);
      next_allot++;
    }
    if (now <= 50000 && !vertex[2 * now]) {
      vertex[2 * now] = true;
      q.push(2 * now);
      next_allot++;
    }
    if (!prev_allot) {
      prev_allot = next_allot;
      next_allot = 0;
      traversal_cnt++;
      if (vertex[arrival])
        return traversal_cnt;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  // Answer: 4 6 5 5 5 6
  for (int _i = _tc; _i--;) {
    int n, k;
    cin >> n >> k;

    vector<bool> vertex(100001, false);
    vertex[n] = true;
    if (n == k)
      cout << 0;
    else
      cout << bfs(n, k, vertex) << ' ';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}