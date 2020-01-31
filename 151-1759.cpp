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
void solve(int cnt, int vowel_cnt, int consonant_cnt, string str, string vowel, string consonant, string ans) {
  // 1 - vowel_cnt 가 음수일 때 vowel.length()는 unsigned int형이므로
  // 음수가 unsigned int으로 형변환해서 매우 큰 양수가 되버린다.
  // 그래서 논리적으로 그럴듯 해보이는 -1 > 2가 참이된다.
  // 크기(lenght, size)를 음수 정수와 비교하는 행위를 하지 않아야 한다.
  if (1 - vowel_cnt > (int)vowel.length() && 2 - consonant_cnt > (int)consonant.length()) {
    cout << vowel.length() << ' ' << consonant.length() << '\n';
    return;
  }
  if (cnt == l) {
    if (vowel_cnt < 1 || consonant_cnt < 2)
      return;
    cout << ans << '\n';
    return;
  }

  for (int i = 0; i <= str.length() - (l - cnt); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      int idx = vowel.find(str[i]);
      solve(cnt + 1, vowel_cnt + 1, consonant_cnt, str.substr(i + 1), vowel.substr(idx + 1), consonant, ans + str[i]);
    } else {
      int idx = consonant.find(str[i]);
      solve(cnt + 1, vowel_cnt, consonant_cnt + 1, str.substr(i + 1), vowel, consonant.substr(idx + 1), ans + str[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    string str, vowel, consonant;
    cin >> l >> c;

    for (int i = c; i--;) {
      string ch;
      cin >> ch;
      if (ch.find_first_of("aeiou") != string::npos)
        vowel.push_back(ch[0]);
      else
        consonant.push_back(ch[0]);
      str.push_back(ch[0]);
    }

    sort(str.begin(), str.end());
    sort(vowel.begin(), vowel.end());
    sort(consonant.begin(), consonant.end());

    solve(0, 0, 0, str, vowel, consonant, "");
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}