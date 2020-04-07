#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
  if (p == "")
    return "";
  string answer = "";

  stack<char> s;
  int i = 0, s_cnt = 0, e_cnt = 0;
  for (; i < p.size(); i++) {
    if (p[i] == '(') {
      s_cnt++;
    } else {
      e_cnt++;
    }
    if (s.size() && s.top() == '(' && p[i] == ')')
      s.pop();
    else
      s.push(p[i]);
    if (s_cnt == e_cnt)
      break;
  }

  if (!s.size())
    answer += p.substr(0, i + 1) + solution(p.substr(i + 1));
  else {
    string sub = p.substr(0, i + 1).substr(1, i - 1);
    for (int i = 0; i < sub.size(); i++)
      sub[i] = sub[i] == ')' ? '(' : ')';

    answer += "(" + solution(p.substr(i + 1)) + ")" + sub;
  }

  return answer;
}

int main() {
  int tc = 3;
  while (tc--) {
    string str;
    cin >> str;

    cout << solution(str) << '\n';
  }
}