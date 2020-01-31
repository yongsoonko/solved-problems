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

int n, s, ans;
// 조합의 경우(이미 선택한 이전의 것들을 선택할 필요가 없음)
// 원래는 문자열일 때는 자르고, 벡터는 다시 만들고 그랬는데,
// 다시 생각해보니까 기존의 문자열이나 벡터를 조작할 필요가 없을 때에는
// 그냥 인덱스를 가지고 푸는 방식이 훨씬 좋다.
void dfs(vector<int> &v, int begin, int sum) {
  if (begin == n)
    return;
  for (int i = begin; i < n; i++) {
    if (sum + v[i] == s)
      ans++;
    if (sum + v[i] > s && v[i] >= 0)
      return;
    dfs(v, i + 1, sum + v[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  cin >> n >> s;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  sort(v.begin(), v.end());
  dfs(v, 0, 0);
  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}