#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int ans[3];
int dq(vector<vector<int>> &v, int si, int sj, int size) {
  // 인덱스 번호: 의미하는 값
  // 0: -1, 1: 0, 2: 1, 3: 2
  // 3번 인덱스는 부분 문제에서 반환할 값이 없는 경우
  int cnt[4] = {
      0,
  };
  if (size == 1)
    return v[si][sj] + 1;

  for (int i = 0; i < size; i += size / 3)
    for (int j = 0; j < size; j += size / 3)
      cnt[dq(v, si + i, sj + j, size / 3)]++;

  for (int i = 0; i < 3; i++)
    if (cnt[i] == 9)  
      return i;

  ans[0] += cnt[0], ans[1] += cnt[1], ans[2] += cnt[2];
  return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;
  vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> v[i][j];

  if (n == 1)
    ans[v[1][1] + 1]++;
  else
    ans[dq(v, 1, 1, n)]++;

  for (int i : ans)
    cout << i << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}