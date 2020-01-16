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
  int n = map.size();
  vector<pair<int, int>> result;
  if (i == 0) {
    if (j == 0) {
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
    if (j == n - 1) {
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
    }
    if (j > 0 && j < n - 1) {
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
  }
  if (i == n - 1) {
    if (j == 0) {
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
    if (j == n - 1) {
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
    }
    if (j > 0 && j < n - 1) {
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
  }
  if (i > 0 && i < n - 1) {
    if (j == 0) {
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
    if (j == n - 1) {
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
    }
    if (j > 0 && j < n - 1) {
      if (map[i - 1][j])
        result.push_back(make_pair(i - 1, j));
      if (map[i + 1][j])
        result.push_back(make_pair(i + 1, j));
      if (map[i][j - 1])
        result.push_back(make_pair(i, j - 1));
      if (map[i][j + 1])
        result.push_back(make_pair(i, j + 1));
    }
  }
  return result;
}

int bfs(pair<int, int> now, vector<vector<bool>> &vertex, vector<vector<vector<pair<int, int>>>> &edge) {
  queue<pair<int, int>> q;
  vertex[now.first][now.second] = true;
  q.push(now);

  int cnt = 1;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < edge[now.first][now.second].size(); i++) {
      pair<int, int> next = edge[now.first][now.second][i];
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

  vector<vector<int>> map(n, vector<int>(n));
  vector<vector<bool>> vertex(n, vector<bool>(n, false));
  vector<vector<vector<pair<int, int>>>> edge(n, vector<vector<pair<int, int>>>(n));
  vector<int> cnt;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++)
      map[i][j] = str[j] - '0';
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      edge[i][j] = search(i, j, map);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!vertex[i][j] && map[i][j]) {
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
