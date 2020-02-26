#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int x[5] = {0, 0, 0, 1, -1};
int y[5] = {0, 1, -1, 0, 0};
int n, m;
int arr[101][101][5];
int s[3];
int e[3];
int res;
bool disc[101][101][5];
bool chk(int x, int y) {
  return 0 < x && x <= n && 0 < y && y <= m;
}
void BFS(int ix, int iy, int dir) {
  if (ix == e[0] && iy == e[1] && dir == e[2]) {
    return;
  }
  disc[ix][iy][dir] = true;
  queue<pair<pair<int, int>, int>> qu;
  qu.push({{ix, iy}, dir});
  // if (dir == 1 || dir == 2)
  // {
  // 	disc[ix][iy][3] = true;
  // 	disc[ix][iy][4] = true;
  // 	qu.push({ { ix,iy } ,3 });
  // 	qu.push({ { ix,iy } ,4 });
  // }
  // else
  // {
  // 	disc[ix][iy][1] = true;
  // 	disc[ix][iy][2] = true;
  // 	qu.push({ { ix,iy } ,1 });
  // 	qu.push({ { ix,iy } ,2 });
  // }
  // for (int i = 1; i <= 3; i++)
  // {
  // 	if (!chk(ix + x[dir] * i, iy + y[dir] * i) || arr[ix + x[dir] * i][iy + y[dir] * i][dir])
  // 	{
  // 		break;
  // 	}
  // 	disc[ix + x[dir] * i][iy + y[dir] * i][dir] = true;
  // 	qu.push({ {ix + x[dir] * i,iy + y[dir] * i} ,dir });
  // }
  int ct = qu.size();
  while (qu.size()) {
    int cx, cy, d;
    while (ct--) {
      cx = qu.front().first.first;
      cy = qu.front().first.second;
      d = qu.front().second;
      qu.pop();
      if (d == 1 || d == 2) {
        if (!disc[cx][cy][3]) {
          disc[cx][cy][3] = true;
          qu.push({{cx, cy}, 3});
        }
        if (!disc[cx][cy][4]) {
          disc[cx][cy][4] = true;
          qu.push({{cx, cy}, 4});
        }
      }
      if (d == 3 || d == 4) {
        if (!disc[cx][cy][1]) {
          disc[cx][cy][1] = true;
          qu.push({{cx, cy}, 1});
        }
        if (!disc[cx][cy][2]) {
          disc[cx][cy][2] = true;
          qu.push({{cx, cy}, 2});
        }
      }
      for (int i = 1; i <= 3; i++) {
        if (!chk(cx + x[d] * i, cy + y[d] * i) || arr[cx + x[d] * i][cy + y[d] * i][d]) {
          break;
        }
        if (!disc[cx + x[d] * i][cy + y[d] * i][d]) {
          disc[cx + x[d] * i][cy + y[d] * i][d] = true;
          qu.push({{cx + x[d] * i, cy + y[d] * i}, d});
        }
      }
    }
    ct = qu.size();
    res++;
    if (disc[e[0]][e[1]][e[2]])
      return;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &arr[i][j][0]);
      for (int k = 1; k <= 4; k++)
        arr[i][j][k] = arr[i][j][0];
    }
  }
  for (int i = 0; i < 3; i++)
    scanf("%d", &s[i]);
  for (int i = 0; i < 3; i++)
    scanf("%d", &e[i]);
  BFS(s[0], s[1], s[2]);
  printf("%d", res);
  return 0;
}