#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<int, int>> search(int i, int j, vector<string> &map) {
  int n = map.size();
  vector<pair<int, int>> result;
  vector<int> diff_i = {-1, 0, 1, 0}, diff_j = {0, 1, 0, -1};

  for (int k = 0; k < 4; k++) {
    int _i = i + diff_i[k], _j = j + diff_j[k];
    if (_i < 0 || _i > n - 1 || _j < 0 || _j > n - 1)
      continue;
    if (map[_i][_j] == '1')
      result.push_back(make_pair(_i, _j));
  }
  return result;
}

// 재귀적 호출이 없다.
int bfs(pair<int, int> now, vector<vector<bool>> &vertex, vector<vector<vector<pair<int, int>>>> &edge) {
  queue<pair<int, int>> q;
  vertex[now.first][now.second] = true;
  q.push(now);

  int cnt = 1;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    auto axis = edge[now.first][now.second];
    for (int i = 0; i < axis.size(); i++) {
      pair<int, int> next = axis[i];
      if (!vertex[next.first][next.second]) {
        cnt++;
        vertex[next.first][next.second] = true;
        q.push(next);
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<string> map(n);
  vector<vector<bool>> vertex(n, vector<bool>(n, false));
  vector<vector<vector<pair<int, int>>>> edge(n, vector<vector<pair<int, int>>>(n));
  vector<int> cnt;
  for (int i = 0; i < n; i++)
    cin >> map[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      edge[i][j] = search(i, j, map);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!vertex[i][j] && map[i][j] == '1') {
        // cout << "i " << i << " j " << j << " \n";
        cnt.push_back(bfs(make_pair(i, j), vertex, edge));
      }

  sort(cnt.begin(), cnt.end());
  cout << cnt.size() << '\n';
  for (int i : cnt)
    cout << i << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
