#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pos {
  int i;
  int j;

  bool operator<(const Pos &p) const {
    return j > p.j;
  }
};

Pos cnt[100001];

vector<int> solution(string s) {
  vector<int> answer;

  int pos = 2, num = 0;
  for (; s[pos]; pos++) {
    if (s[pos] >= '0' && s[pos] <= '9')
      num = num * 10 + s[pos] - '0';
    else {
      if (s[pos] == ',') {
      } else if (s[pos] == '}' && s[pos + 1] == '}') {
        pos += 1;
      } else if (s[pos] == '}' && s[pos + 1] == ',' && s[pos + 2] == '{') {
        pos += 2;
      }
      cnt[num].i = num;
      cnt[num].j++;
      num = 0;
    }
  }
  sort(cnt, cnt + 100001);

  for (int i = 0; i < 100001; i++) {
    if (cnt[i].j == 0)
      return answer;
    answer.push_back(cnt[i].i);
  }
}

int main() {
  int N = 1;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    vector<int> res = solution(str);
    for (int i : res)
      cout << i << ' ';
    cout << '\n';
  }
}