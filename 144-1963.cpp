#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

bool prime[10000];
int dist[10000];

string bfs(int now, int arrival, vector<bool> &vertex) {
  queue<int> q;
  vertex[now] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    int div = 10000, share = 0;
    for (int i = 0; i < 4; i++) {
      div /= 10;
      int curr_digit = now / div - share * 10;
      for (int j = 0; j <= 9; j++) {
        if (i == 0 && j == 0)
          continue;
        if (j != curr_digit) {
          int next = now - curr_digit * div + j * div;
          if (!prime[next] && !vertex[next]) {
            dist[next] = dist[now] + 1;
            vertex[next] = true;
            q.push(next);
          }
        }
      }
      share = share * 10 + curr_digit;
    }
  }
  if (!vertex[arrival])
    return "Impossible";
  else
    return to_string(dist[arrival]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  // false가 소수
  prime[0] = prime[1] = true;
  for (int i = 2; i <= 9999; i++)
    for (int j = i + i; j <= 9999; j += i)
      prime[j] = true;

  int _tc = 1;
  cin >> _tc;
  for (int _i = _tc; _i--;) {
    memset(dist, 0x00, 40000);
    int now, arrival;
    cin >> now >> arrival;

    vector<bool> vertex(10000, false);
    cout << bfs(now, arrival, vertex) << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
