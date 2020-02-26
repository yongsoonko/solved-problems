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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;
  int dist[51][51];
  fill(&dist[0][0], &dist[50][51], 1e9);
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;

  while (1) {
    int a, b;
    cin >> a >> b;
    if (a == -1)
      break;
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     if (dist[i][j] == 1e9)
  //       cout << "x ";
  //     else
  //       cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  int ans_score = 1e9, ans_cnt = 0, score[51];
  for (int i = 1; i <= N; i++) {
    int max_score = 0;
    for (int j = 1; j <= N; j++) {
      if (max_score < dist[i][j])
        max_score = dist[i][j];
    }
    score[i] = max_score;
    if (ans_score > max_score) {
      ans_score = max_score;
      ans_cnt = 1;
    } else if (ans_score == max_score)
      ans_cnt++;
  }

  cout << ans_score << ' ' << ans_cnt << '\n';
  for (int i = 1; i <= N; i++)
    if (ans_score == score[i])
      cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}