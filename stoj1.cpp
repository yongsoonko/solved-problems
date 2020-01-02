#include <iostream>
#include <vector>

using namespace std;
char a, b;
int depthSize;
vector<char> moeum = {'a', 'e', 'i', 'o', 'u'};

void solution(int size, string s) {
  if(depthSize == size) {
    bool doOnce = false;
    if(depthSize >= 3) {
      for(int idx = 2; idx <= s.length(); idx++) {
        if(s[idx-2] == s[idx-1] && s[idx-1] == s[idx]) return;
      }
    }
    for(vector<char>::iterator it=moeum.begin(); it!=moeum.end(); it++) {
      if(s.find(*it) != string::npos) {
        doOnce = true;
        break;
      }
    }
    if(doOnce == false) return;
    printf("%s\n", s.c_str());
    return;
  }
  for(char tmp=a; tmp<=b; tmp++) {
    string tmp2 = s + tmp;
    solution(size + 1, tmp2);
  }
}

int main() {
  cin >> a >> b >> depthSize;
  string tmp;

  solution(0, tmp);
}