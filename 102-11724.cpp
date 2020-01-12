#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

void bfs(int now, vector<bool> &vertex, vector<vector<int>> &edge) {
  queue<int> q;

  vertex[now] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    for (int i = 0; i < edge[now].size(); i++) {
      int next = edge[now][i];
      if (!vertex[next]) {
        vertex[next] = true;
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

  int n, m;
  cin >> n >> m;

  vector<bool> vertex(n + 1, false);
  vector<vector<int>> edge(n + 1, vector<int>());
  for (int i = m; i--;) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  // 인접리스트 사용 시에 map 출력(인접행렬보다 길다.)
  // vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
  // for (int i = 1; i <= n; i++)
  //   for (int j = 0; j < edge[i].size(); j++)
  //     map[i][edge[i][j]] = 1;

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++)
  //     cout << map[i][j] << ' ';
  //   cout << '\n';
  // }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vertex[i])
      cnt++;
    bfs(i, vertex, edge);
  }

  cout << cnt;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
