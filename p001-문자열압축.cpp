#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = s.length();

  // printf("%s\n", tmp.c_str());
  for (int i = 1; i <= s.length() / 2; i++) {
    string tmp = s.substr(0, i);
    int cnt = 1;
    string result;
    for (int j = i; j <= s.length() - 1; j += i) {
      string curr = s.substr(j, i);
      if(i == 3) printf("--%s %s\n", curr.c_str(), tmp.c_str());
      if(curr == tmp) {
        cnt++;
        if(j + i> s.length() - 1) {
          char buff[100];
          sprintf(buff, "%d", cnt);
          result += string(buff) + curr;
        }
      } else {
        if(cnt == 1) {
          result += tmp;
          if(j + i> s.length() - 1) {
            result += curr;
          }
        } else {
          char buff[100];
          sprintf(buff, "%d", cnt);
          result += string(buff) + tmp;
          if(j + i> s.length() - 1) {
            result += curr;
          }
        }
        cnt = 1;
        tmp = curr;
      }
    }
    // printf("%s\n", result.c_str());
    if(answer > result.length()) answer = result.length();
  }
  // printf("%d\n", answer);
  return answer;
}

// int main() {
//   solution("abcabcdede");
//   solution("ababcdcdababcdcd");
// }