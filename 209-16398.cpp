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

  bool operator<(const Pos &p) const {
    return k < p.k;
  }
};

int N;
int root[1001];
vector<Pos> edge;

int find(int x) {
  if (root[x] == x)
    return x;
  return root[x] = find(root[x]);
}

void merge(int x, int y) {
  if (x != y) {
    int rx = find(x),
        ry = find(y);
    root[ry] = rx;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 1; i <= N; i++)
    root[i] = i;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int a;
      cin >> a;
      if (j <= i)
        continue;
      edge.push_back({i, j, a});
    }

  sort(edge.begin(), edge.end());

  int cnt = 1, i = 0;
  ll ans = 0;
  while (cnt < N) {
    Pos p = edge[i++];
    if (find(p.i) != find(p.j)) {
      merge(p.i, p.j);
      cnt++;
      ans += (ll)p.k;
    }
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}