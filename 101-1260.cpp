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

  // 1에서 n까지
  for (int next = 1; next < edge.size(); next++) {
    // int now = edge[now][i] //이렇게 해서 Segmentation fault가 발생했음
    if (edge[now][next] == 1 && !vertex[next]) {
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

    // 1에서 n까지
    for (int next = 1; next < edge.size(); next++) {
      if (edge[now][next] == 1 && !vertex[next]) {
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
  vector<vector<int>> edge(n + 1, vector<int>(n + 1, 0));
  for (int i = m; i--;) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = 1;
    edge[b][a] = 1;
  }

  dfs(start, vertex, edge);
  fill(vertex.begin(), vertex.end(), false);
  cout << '\n';
  bfs(start, vertex, edge);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
