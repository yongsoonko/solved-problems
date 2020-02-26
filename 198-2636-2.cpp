#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, m, a[101][101], b[101][101], r, f;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int disc[101][101];
bool chk(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}
bool existCheese() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ret += a[i][j];
    }
  }
  if (ret)
    f = ret;
  return ret;
}
void bfs() {
  memset(disc, 0, sizeof(disc));
  queue<pair<int, int>> qu;
  for (int i = 0; i < n; i++) {
    disc[i][0] = true;
    disc[i][m - 1] = true;
    qu.push({i, 0});
    qu.push({i, m - 1});
  }
  for (int i = 0; i < m; i++) {
    disc[0][i] = true;
    disc[n - 1][i] = true;
    if (i)
      qu.push({0, i});
    if (i != m - 1)
      qu.push({n - 1, i});
  }
  while (qu.size()) {
    int x = qu.front().first;
    int y = qu.front().second;
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int cx = x + dx[i];
      int cy = y + dy[i];
      if (chk(cx, cy)) {
        if (!a[cx][cy] && !disc[cx][cy]) {
          qu.push({cx, cy});
          disc[cx][cy] = true;
        } else if (a[cx][cy]) {
          b[cx][cy] = 1;
        }
      }
    }
  }
}
void nextday() {
  bfs();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      a[i][j] &= (b[i][j] ^ 1);
  }
}
int main() {
  int tc = 1;
  while (tc--) {
    fill(&a[0][0], &a[100][101], 0);
    fill(&b[0][0], &b[100][101], 0);
    fill(&disc[0][0], &disc[100][101], 0);
    r = f = 0;    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
    }
    while (existCheese()) {
      r++;
      nextday();
    }
    printf("%d\n%d\n", r, f);
  }
  return 0;
}
