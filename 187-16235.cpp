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

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
vector<int> tree[11][11];
int A[11][11];
int soil[11][11];

bool chk_out(int ci, int cj) {
  return ci >= 1 && ci <= N && cj >= 1 && cj <= N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        vector<int>().swap(tree[i][j]);

    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        cin >> A[i][j];
        soil[i][j] = 5;
      }

    for (int i = 0; i < M; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      tree[a][b].push_back(c);
    }

    while (K--) {
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
          sort(tree[i][j].begin(), tree[i][j].end());
          auto it = tree[i][j].begin();
          int sum = 0;
          for (int k = 0; k < tree[i][j].size();) {
            if (soil[i][j] - tree[i][j][k] >= 0) {
              soil[i][j] -= tree[i][j][k];
              tree[i][j][k]++;
              k++;
            } else {
              sum += (tree[i][j][k] / 2);
              tree[i][j].erase(it + k);
            }
          }
          soil[i][j] += sum;
        }
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
          soil[i][j] += A[i][j];
          for (int k = 0; k < tree[i][j].size(); k++)
            if (tree[i][j][k] % 5 == 0)
              for (int l = 0; l < 8; l++) {
                int ni = i + di[l], nj = j + dj[l];
                if (chk_out(ni, nj))
                  tree[ni][nj].push_back(1);
              }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        ans += tree[i][j].size();

    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}