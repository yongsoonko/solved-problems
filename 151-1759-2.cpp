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

int l, c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    string str;
    cin >> l >> c;

    for (int i = c; i--;) {
      char ch;
      cin >> ch;
      str.push_back(ch);
    }

    vector<bool> v(c - l, 0);
    for (int i = 0; i < l; i++)
      v.push_back(1);
    sort(v.rbegin(), v.rend());
    sort(str.begin(), str.end());

    do {
      int vowel_cnt = 0, consonant_cnt = 0;
      string ans;
      for (int i = 0; i < c; i++)
        if (v[i] == 1) {
          if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vowel_cnt++;
          else
            consonant_cnt++;
          ans.push_back(str[i]);
        }
      if (vowel_cnt >= 1 && consonant_cnt >= 2)
        cout << ans << '\n';
    } while (prev_permutation(v.begin(), v.end()));
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}