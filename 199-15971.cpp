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
  int k;
};

int N, pa, pb;
int a[100001], b[100001], chk_a[100001], chk_b[1000001];
vector<Pos> edge[100001];

void dfs(int *arr, int *chk, int cp) {
  chk[cp] = 1;
  for (int i = 0; i < edge[cp].size(); i++) {
    Pos next = edge[cp][i];
    if (!chk[next.j]) {
      arr[next.j] = arr[next.i] + next.k;
      dfs(arr, chk, next.j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> pa >> pb;

  for (int i = 1; i <= N; i++)
    vector<Pos>().swap(edge[i]);

  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back({a, b, c});
    edge[b].push_back({b, a, c});
  }

  dfs(a, chk_a, pa);
  dfs(b, chk_b, pb);

  int ans = 1e9;
  for (int i = 1; i <= N; i++) {
    ans = min(ans, a[i] + b[i]);
    for (int j = 0; j < edge[i].size(); j++) {
      Pos p = edge[i][j];
      ans = min(ans, a[i] + b[p.j]);
    }
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}