#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void bfs(vector<bool> &vertex, vector<vector<int>> &edge) {
  queue<int> q;
  int now = 1;
  vector<int> parent(vertex.size());
  vertex[now] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    vector<int> conn = edge[now];
    for (int i = 0; i < conn.size(); i++) {
      int next = conn[i];
      if (!vertex[next]) {
        vertex[next] = true;
        parent[next] = now;
        q.push(next);
      }
    }
  }
  for (int i = 2; i < parent.size(); i++)
    cout << parent[i] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int tc = 1;
  // cin >> tc;

  for (int i = tc; i--;) {
    int n;
    cin >> n;

    vector<bool> vertex(n + 1, false);
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }

    // for (auto a : edge) {
    //   for (int i : a)
    //     cout << i << ' ';
    //   cout << '\n';
    // }

    bfs(vertex, edge);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}