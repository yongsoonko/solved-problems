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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<int> v(n);
  // 차례대로 음수, 0, 1, 2이상의 양수 개수
  int cnt[4] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
    if (a < 0)
      cnt[0]++;
    else if (a == 0)
      cnt[1]++;
    else if (a == 1)
      cnt[2]++;
    else
      cnt[3]++;
  }

  sort(v.begin(), v.end());

  int sum = 0, i = 0;
  for (; i <= cnt[0] - 2; i += 2)
    sum += v[i] * v[i + 1];
  // 0의 개수가 없고, 음수가 홀수 개인 경우
  if (!cnt[1] && cnt[0] % 2 == 1)
    sum += v[i];
  i = cnt[0] + cnt[1] + cnt[2];
  sum += cnt[2];
  if (cnt[3] % 2 == 1)
    sum += v[i++];
  for (; i < n; i += 2)
    sum += v[i] * v[i + 1];

  cout << sum;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}