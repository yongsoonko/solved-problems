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
  bool operator<(const Pos &p) const {
    return i < p.i;
  }
};

int N, L, P;
vector<Pos> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  v.push_back({0, 0});
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  cin >> L >> P;
  v.push_back({L, 0});

  sort(v.begin(), v.end());

  priority_queue<int> pq;
  int ans = 0;
  for (int i = 1; i <= N + 1; i++) {
    int adj_dist = v[i].i - v[i - 1].i;
    while (P - adj_dist < 0) {
      if (pq.size() == 0) {
        cout << -1 << '\n';
        return 0;
      }
      P += pq.top();
      pq.pop();
      ans++;
    }
    P -= adj_dist;
    if (i > 0 && i < N + 1)
      pq.push(v[i].j);
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}