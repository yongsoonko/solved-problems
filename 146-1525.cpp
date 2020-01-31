#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

vector<string> vs;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

int _search(int left, int right, string &target) {
  int mid = (left + right) / 2;

  if (vs[mid] == target)
    return mid;
  if (vs[mid] > target)
    return _search(left, mid - 1, target);
  if (vs[mid] < target)
    return _search(mid + 1, right, target);
}

int search(string &target) {
  return _search(0, 362880, target);
}

int bfs(pair<string, int> now, string arrival, vector<bool> &vertex) {
  int arrival_idx = search(arrival), prev_allot = 1, next_allot = 0, moved_cnt = 0;
  queue<pair<string, int>> q;
  vertex[search(now.first)] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    prev_allot--;
    int i = now.second / 3, j = now.second % 3;
    for (int k = 0; k < 4; k++) {
      int pi = i + di[k], pj = j + dj[k];
      if (pi >= 0 && pi <= 2 && pj >= 0 && pj <= 2) {
        string next = now.first;
        int swapped = pi * 3 + pj;
        swap(next[now.second], next[swapped]);
        int next_idx = search(next);
        if (!vertex[next_idx]) {
          vertex[next_idx] = true;
          q.push({next, swapped});
          next_allot++;
        }
      }
    }
    if (!prev_allot) {
      prev_allot = next_allot;
      next_allot = 0;
      moved_cnt++;
      if (vertex[arrival_idx])
        return moved_cnt;
    }
  }
  if (!vertex[arrival_idx])
    return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    string num = "012345678", str;
    int blk;
    vector<bool> vertex(362881, false);

    for (int i = 0; i < 9; i++) {
      char ch;
      cin >> ch;
      if (ch == '0')
        blk = i;
      str.push_back(ch);
    }

    vs.reserve(362881);
    do {
      vs.push_back(num);
    } while (next_permutation(num.begin(), num.end()));

    if (str == "123456780")
      cout << 0;
    else
      cout << bfs({str, blk}, "123456780", vertex);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}