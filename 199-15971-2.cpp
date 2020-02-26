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

int N, S, E, sum, max_dist = 0;
vector<Pos> edge[100001];

bool dfs(int curr, int prev) {
  if (curr == E)
    return 1;

  for (auto next : edge[curr]) {
    if (next.i == prev)
      continue;
    if (dfs(next.i, curr)) {
      sum += next.j;
      max_dist = max(max_dist, next.j);
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> S >> E;

  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }

  dfs(S, -1);
  cout << sum - max_dist;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}