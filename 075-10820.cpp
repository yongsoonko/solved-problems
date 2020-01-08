#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  string str;
  while(getline(cin, str)) {
    int cnt[4] = {0, };
    for(int i=0; i<str.length(); i++) {
      char ch = str[i];
      if(ch >= 'a' && ch <= 'z') cnt[0]++;
      else if(ch >= 'A' && ch <= 'Z') cnt[1]++;
      else if(ch >= '0' && ch <= '9') cnt[2]++;
      else if(ch == ' ') cnt[3]++;
    }
    for(int i: cnt) {
      cout << i << ' ';
    }
    cout << '\n';
  } 

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
