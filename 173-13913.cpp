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
ve<int> mark(100001);
ve<bool> chk(100001);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> n >> k;

  queue<int> q;
  chk[n] = 1;
  q.push(n);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    int next[3] = {curr - 1, curr + 1, curr * 2};
    for (int i = 0; i < 3; i++)
      if (next[i] >= 0 && next[i] <= 100000 && !chk[next[i]]) {
        chk[next[i]] = 1;
        mark[next[i]] = i;
        dist[next[i]] = dist[curr] + 1;
        q.push(next[i]);

        if (chk[k])
          goto out;
      }
  }

out:
  ve<int> ans;
  ans.push_back(k);
  for (int p = k; p != n;) {
    if (mark[p] == 0) {
      ans.push_back(p + 1);
      p += 1;
    } else if (mark[p] == 1) {
      ans.push_back(p - 1);
      p -= 1;
    } else {
      ans.push_back(p / 2);
      p /= 2;
    }
  }

  if (n == k)
    cout << 0 << '\n'
         << n;
  else {
    cout << dist[k] << '\n';
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
      cout << *it << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}