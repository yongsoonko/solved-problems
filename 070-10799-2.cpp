#include <time.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int ans = 0;
  string str;
  stack<char> s;
  cin >> str;
  for(int i=0; i<str.length(); i++) {
    if(str[i] == '(') {
      s.push(str[i]);
    } else {
      s.pop();
      if(str[i-1] == '(') {
        ans += s.size(); 
      } else {
        ans++;
      }
    }
  }  
  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
