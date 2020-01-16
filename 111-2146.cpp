#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

vector<vector<int>> unionfind(vector<vector<int>> &map) {
  int n = map.size(), seq = 1;
  vector<vector<int>> unionmap(n, vector<int>(n, 0));
  vector<vector<bool>> vertex(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (map[i][j] == 1 && !vertex[i][j]) {
        queue<pll> q;
        vertex[i][j] = true;
        unionmap[i][j] = seq;
        q.push({i, j});
        while (!q.empty()) {
          pll now = q.front();
          q.pop();
          int i = now.first, j = now.second;
          for (int k = 0; k < 4; k++) {
            int pi = i + di[k], pj = j + dj[k];
            if (pi >= 0 && pi <= n - 1 && pj >= 0 && pj <= n - 1 && map[pi][pj] == 1 && !vertex[pi][pj]) {
              vertex[pi][pj] = true;
              unionmap[pi][pj] = seq;
              q.push({pi, pj});
            }
          }
        }
        seq++;
      }
  return unionmap;
}

int bfs(vector<vector<int>> &map, vector<vector<int>> &unionmap) {
  int n = map.size();
  int result = n * n;
  queue<pll> q;
  // 바로 인접한 곳이 바디인 해변을 큐에 넣는 과정
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      // 육지인 경우
      if (map[i][j])
        for (int k = 0; k < 4; k++) {
          int pi = i + di[k], pj = j + dj[k];
          // 육지에서 인접한 곳에 바다가 존재하는 경우
          if (pi >= 0 && pi <= n - 1 && pj >= 0 && pj <= n - 1 && !map[pi][pj])
            q.push({i, j});
        }

  while (!q.empty()) {
    pll now = q.front();
    q.pop();

    int i = now.first, j = now.second, groupseq = unionmap[i][j];
    for (int k = 0; k < 4; k++) {
      int pi = i + di[k], pj = j + dj[k];
      if (pi >= 0 && pi <= n - 1 && pj >= 0 && pj <= n - 1) {
        if (map[pi][pj] == 0) {
          q.push({pi, pj});
          map[pi][pj] = map[i][j] + 1;
          unionmap[pi][pj] = groupseq;
        } else if (map[pi][pj] != 0 && unionmap[pi][pj] != groupseq) {
          // cout << "pi " << pi << " pj " << pj << '\n';
          result = min(result, map[pi][pj] - 1 + map[i][j] - 1);
        }
      }
    }
  }
  return result;
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

    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> unionmap;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> map[i][j];

    unionmap = unionfind(map);
    cout << bfs(map, unionmap) << '\n';

    // for (auto a : map) {
    //   for (int i : a)
    //     cout << i << ' ';
    //   cout << '\n';
    // }
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}