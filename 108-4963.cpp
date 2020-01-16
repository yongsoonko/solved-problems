#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<int, int>> search(int i, int j, vector<vector<int>> &map) {
  int h = map.size(), w = map[0].size();
  vector<int> diff_i = {-1, -1, 0, 1, 1, 1, 0, -1}, diff_j = {0, 1, 1, 1, 0, -1, -1, -1};
  vector<pair<int, int>> result;
  for (int k = 0; k < 8; k++) {
    int _i = i + diff_i[k], _j = j + diff_j[k];
    if (_i < 0 || _i > h - 1 || _j < 0 || _j > w - 1)
      continue;
    if (map[_i][_j])
      result.push_back(make_pair(_i, _j));
  }
  return result;
}

void bfs(pair<int, int> now, vector<vector<bool>> &vertex, vector<vector<vector<pair<int, int>>>> &edge) {
  queue<pair<int, int>> q;
  vertex[now.first][now.second] = true;
  q.push(now);

  while (!q.empty()) {
    pair<int, int> now = q.front();
    q.pop();

    vector<pair<int, int>> coords = edge[now.first][now.second];
    for (int i = 0; i < coords.size(); i++) {
      pair<int, int> next = coords[i];
      if (!vertex[next.first][next.second]) {
        vertex[next.first][next.second] = true;
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

  int w, h;
  cin >> w >> h;
  while (w != 0 || h != 0) {
    vector<vector<int>> map(h, vector<int>(w));
    vector<vector<bool>> vertex(h, vector<bool>(w, false));
    vector<vector<vector<pair<int, int>>>> edge(h, vector<vector<pair<int, int>>>(w));

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> map[i][j];

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        edge[i][j] = search(i, j, map);

    int cnt = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (!vertex[i][j] && map[i][j]) {
          // cout << "i " << i << " j " << j << '\n';
          bfs(make_pair(i, j), vertex, edge);
          cnt++;
        }

    cout << cnt << '\n';
    cin >> w >> h;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
