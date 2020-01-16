#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int bfs(int now, vector<bool> &vertex, vector<vector<pll>> &edge) {
  bool doOnce = false;
  if (now == -1) {
    doOnce = true;
    now = 1;
  }
  queue<int> q;
  vector<int> weight(vertex.size(), 0);
  int dist = 0;
  vertex[now] = true;
  q.push(now);

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    dist = weight[now];

    vector<pll> conn = edge[now];
    for (int i = 0; i < conn.size(); i++) {
      int next = conn[i].first;
      if (!vertex[next]) {
        vertex[next] = true;
        q.push(next);

        weight[next] = dist + conn[i].second;
      }
    }
  }
  int max = 0, idx = -1;
  for (int i = 1; i < weight.size(); i++) {
    // cout << weight[i] << ' ';
    if (max < weight[i]) {
      max = weight[i];
      idx = i;
    }
  }
  // cout << '\n';
  if (!doOnce)
    cout << weight[idx];
  return idx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<bool> vertex(n + 1, false);
  vector<vector<pll>> edge(n + 1, vector<pll>());
  for (int i = 0; i < n; i++) {
    int v, a, b;
    cin >> v >> a;

    while (a != -1) {
      cin >> b;
      edge[v].push_back({a, b});
      cin >> a;
    }
  }
  // for (auto a : edge)
  //   for (auto b : a)
  //     cout << b.first << ' ' << b.second << '\n';

  int now;
  now = bfs(-1, vertex, edge);
  fill(vertex.begin(), vertex.end(), false);
  bfs(now, vertex, edge);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}