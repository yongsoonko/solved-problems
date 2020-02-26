#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int N, M;
int dist[101][101];
int chk[101];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;

  fill(&dist[0][0], &dist[100][101], 1e9);
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++)
  //     if (dist[i][j] == 1e9)
  //       cout << "x ";
  //     else
  //       cout << dist[i][j] << ' ';
  //   cout << '\n';
  // }

  for (int i = 1; i <= N; i++)
    if (!chk[i]) {
      vector<int> adj;
      for (int j = 1; j <= N; j++) {
        if (dist[i][j] < 1e9) {
          adj.push_back(j);
          chk[j] = 1;
        }
      }
      int candi_dist = 1e9, candi_idx;
      for (int j : adj) {
        int max_dist = -1;
        for (int k : adj) {
          if (max_dist < dist[j][k]) {
            max_dist = dist[j][k];
          }
        }
        if (candi_dist > max_dist) {
          candi_dist = max_dist;
          candi_idx = j;
        }
      }
      ans.push_back(candi_idx);
    }

  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int i : ans)
    cout << i << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}