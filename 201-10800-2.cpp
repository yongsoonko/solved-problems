#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int idx;
  int color;
  int size;
  bool operator<(const Pos &p) const {
    if (size == p.size)
      return color < p.color;
    return size < p.size;
  }
};

int N;
int tmp[200001], ans[200001];

vector<Pos> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({i, a, b});
  }

  sort(v.begin(), v.end());

  // for (Pos p : v)
  //   cout << p.idx << ' ' << p.color << ' ' << p.size << '\n';

  int all_sum = 0;
  queue<Pos> q;
  for (int i = 0; i < N; i++) {
    ans[v[i].idx] = all_sum - tmp[v[i].color];
    if (i < N - 1 && v[i].size == v[i + 1].size) {
      q.push(v[i]);
      continue;
    } else {
      while (q.size()) {
        Pos p = q.front();
        q.pop();
        tmp[p.color] += p.size;
        all_sum += p.size;
      }
      tmp[v[i].color] += v[i].size;
      all_sum += v[i].size;
    }
  }

  for (int i = 0; i < N; i++)
    cout << ans[i] << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}