#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

void dfs(int now, vector<bool> &vertex, vector<vector<int>> &edge) {
  vertex[now] = true;
  cout << now << ' ';

  sort(edge[now].begin(), edge[now].end());
  for (int i = 0; i < edge[now].size(); i++) {
    // int now = edge[now][i] //이렇게 해서 Segmentation fault가 발생했음
    int next = edge[now][i];
    if (!vertex[next]) {
      dfs(next, vertex, edge);
    }
  }
}

// 재귀적 호출이 존재하지 않는다.
void bfs(int now, vector<bool> vertex, vector<vector<int>> edge) {
  queue<int> q;
  vertex[now] = true;
  cout << now << ' ';
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    sort(edge[now].begin(), edge[now].end());
    for (int i = 0; i < edge[now].size(); i++) {
      int next = edge[now][i];
      if (!vertex[next]) {
        vertex[next] = true;
        cout << next << ' ';
        q.push(next);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n, m, start;
  cin >> n >> m >> start;

  vector<bool> vertex(n + 1, false);
  vector<vector<int>> edge(n + 1, vector<int>());
  for (int i = m; i--;) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  dfs(start, vertex, edge);
  fill(vertex.begin(), vertex.end(), false);
  cout << '\n';
  bfs(start, vertex, edge);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
