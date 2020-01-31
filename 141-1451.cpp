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

ll sum = 0, ans = 0;
void div2(vector<string> &vs, pii start, pii end, int sub_sum) {
  int sub_sub_sum = 0;
  // 행으로 자르기
  for (int i = start.first; i < end.first; i++) {
    for (int j = start.second; j <= end.second; j++)
      sub_sub_sum += vs[i][j] - '0';
    ans = max(ans, (sum - sub_sum) * (sub_sum - sub_sub_sum) * sub_sub_sum);
  }
  sub_sub_sum = 0;
  // 열(i)으로 자르기
  for (int i = start.second; i < end.second; i++) {
    for (int j = start.first; j <= end.first; j++)
      sub_sub_sum += vs[j][i] - '0';
    ans = max(ans, (sum - sub_sum) * (sub_sum - sub_sub_sum) * sub_sub_sum);
  }
}

// s 0 0
// 0 0 0
// 0 0 e
void div(vector<string> &vs, pii start, pii end) {
  int sub_sum = 0;
  // 행(i)으로 자르기
  for (int i = start.first; i < end.first; i++) {
    for (int j = start.second; j <= end.second; j++)
      sub_sum += vs[i][j] - '0';
    div2(vs, {start.first, start.second}, {i, end.second}, sub_sum);
    div2(vs, {i + 1, start.second}, {end.first, end.second}, sum - sub_sum);
  }
  sub_sum = 0;
  // 열(i)으로 자르기
  for (int i = start.second; i < end.second; i++) {
    for (int j = start.first; j <= end.first; j++)
      sub_sum += vs[j][i] - '0';
    div2(vs, {start.first, start.second}, {end.first, i}, sub_sum);
    div2(vs, {start.first, i + 1}, {end.first, end.second}, sum - sub_sum);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  // answer: 3806599216
  for (int _i = _tc; _i--;) {
    sum = 0, ans = 0;
    int n, m;
    cin >> n >> m;

    vector<string> vs(n);
    for (int i = 0; i < n; i++)
      cin >> vs[i];

    for (auto a : vs)
      for (char ch : a)
        sum += ch - '0';

    div(vs, {0, 0}, {n - 1, m - 1});
    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}