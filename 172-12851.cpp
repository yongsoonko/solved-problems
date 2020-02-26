#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define ve vector
#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int n, k;
ve<int> dist(100001);
ve<int> cnt(100001);
ve<bool> chk(100001);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> n >> k;

  queue<int> q;
  chk[n] = 1;
  q.push(n);

  int prev_lv = 1, next_lv = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    prev_lv--;
    for (int next : {curr - 1, curr + 1, curr * 2}) {
      if (next >= 0 && next <= 100000 && !chk[next]) {
        cnt[next]++;
        q.push(next);
        dist[next] = dist[curr] + 1;
        next_lv++;
      }
    }
    if (!prev_lv) {
      for (int i = 0; i < next_lv; i++) {
        int next = q.front();
        q.pop();
        q.push(next);
        chk[next] = 1;
      }
      prev_lv = next_lv;
      next_lv = 0;

      if (chk[k])
        break;
    }
  }

  if (n == k)
    cout << 0 << '\n'
         << 1;
  else
    cout << dist[k] << '\n'
         << cnt[k];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}