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

int n, ans;
void dfs(int now, int cost, int traversal_cnt, vector<bool> &vertex, vector<vector<int>> &edge) {
  // 마지막 순회 도시 인 경우
  if (traversal_cnt == n - 1) {
    // 현재 마을에서 첫 번째 마을로 가는 경로가 있는 경우
    if (edge[now][1]) {
      cost += edge[now][1];
      ans = min(ans, cost);
    }
    return;
  }

  for (int i = 1; i <= n; i++)
    if (!vertex[i] && edge[now][i]) {
      vertex[i] = true;
      dfs(i, cost + edge[now][i], traversal_cnt + 1, vertex, edge);
      vertex[i] = false;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> n;
    ans = 1e9;

    vector<vector<int>> edge(n + 1, vector<int>(n + 1, 0));
    vector<bool> vertex(n + 1, false);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> edge[i][j];

    // 루트 노드가 사이클에 반드시 포함되기 때문에
    // 하나의 루트 노드를 기점으로 dfs를 하면
    // 최소 비용을 만드는 경로에서 시작 도시로 반드시 도착한다.
    vertex[1] = true;
    dfs(1, 0, 0, vertex, edge);

    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}