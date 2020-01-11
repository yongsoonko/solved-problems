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
  //   str += '4'; 
  // }

  vector<string> v = {"000", "001", "010", "011", "100", "101", "110", "111"};

  clock_t start = clock();

  int len = str.length();
  int tmp = str[0] - '0';
  int remain;
  string tmp2;
  for(int i=0; i<3; i++) {
    if(tmp == 0) {
      if(len == 1) {
        tmp2 = '0';
      }
      break;
    } else {
      remain = tmp % 2;
      tmp /= 2;
      tmp2 = (char)('0' + remain) + tmp2;
    }
  }
  cout << tmp2;

  for(int i=1; i<len; i++) {
    cout << v[str[i] - '0'];
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
