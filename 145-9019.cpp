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

char op[4] = {'D', 'S', 'L', 'R'};

void bfs(int now, int arrival, vector<bool> &vertex, vector<pair<int, char>> &dist) {
  queue<int> q;
  vertex[now] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    int ms_digit = now / 1000, ls_digit = now % 10;
    int next[4] = {(now * 2) % 10000,
                   (now + 9999) % 10000,
                   (now * 10) % 10000 + ms_digit,
                   (now / 10) + ls_digit * 1000};

    for (int i = 0; i < 4; i++) {
      if (!vertex[next[i]]) {
        vertex[next[i]] = true;
        q.push(next[i]);
        dist[next[i]].first = now;
        dist[next[i]].second = op[i];
      }
    }
    if (dist[arrival].first != -1)
      return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  cin >> _tc;
  for (int _i = _tc; _i--;) {
    int now, arrival;
    cin >> now >> arrival;

    vector<bool> vertex(10000, false);
    vector<pair<int, char>> dist(10000, {-1, ' '});
    bfs(now, arrival, vertex, dist);
    string ans;
    for (int i = arrival; i != now; i = dist[i].first)
      ans.push_back(dist[i].second);
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
      cout << *it;
    cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}