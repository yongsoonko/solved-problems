#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  // str = "";
  // for(int i=0; i<300000; i++) {
  //   str += '0'; 
  // }

  clock_t start = clock();

  string ans;
  int len = str.length();
  for(int i=0; i<len; i++) {
    int tmp = str[i] - '0';
    string tmp2;
    int remain;
    for(int j=0; j<3; j++) {
      if(tmp == 0) {
        if(i > 0)
          tmp2 = '0' + tmp2;
        else if(i==0 && len==1) {
          tmp2 = '0';
          break;
        }
      } else {
        remain = tmp % 2;
        tmp /= 2; 
        tmp2 = (char)('0' + remain) + tmp2;
      }
    } 
    ans += tmp2;
  }
  
  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
