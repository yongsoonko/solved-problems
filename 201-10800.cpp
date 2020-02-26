#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int idx;
  int color;
  int size;
  int sum;
};

struct Pos2 {
  int color;
  int size;

  bool operator<(const Pos2 &p) const { //dummy
    if (color == p.color)
      return size < p.size;
    return color < p.color;
  }
};

bool compare(const Pos &a, const Pos &b) {
  if (a.size == b.size)
    return a.color < b.color;
  return a.size < b.size;
}

bool compare2(const Pos &a, const Pos &b) {
  return a.idx < b.idx;
}

int N;
int tmp[200001];

vector<Pos> v;
set<Pos2> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // int tc = 1;
  // while (tc--) {
  cin >> N;
  // fill(tmp + 1, tmp + N + 1, 0);
  // vector<Pos>().swap(v);

  for (int i = 1; i <= N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({i, a, b, 0});
  }

  sort(v.begin(), v.end(), compare);

  int all_sum = 0;
  for (int i = 0, j = 0; i < N; i++) {
    Pos &a = v[i];
    Pos b = v[j];

    while (b.size < a.size) {
      all_sum += b.size;
      tmp[b.color] += b.size;

      b = v[++j];
    }

    a.sum += all_sum - tmp[a.color];
  }

  sort(v.begin(), v.end(), compare2);

  for (int i = 0; i < N; i++)
    cout << v[i].sum << '\n';
  // }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}