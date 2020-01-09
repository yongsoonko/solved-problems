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
  getline(cin, str);

  for(int i=0; i<str.length(); i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = 'a' + (str[i] - 'a' + 13) % 26;
    } else if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = 'A' + (str[i] - 'A' + 13) % 26;
    }
  }

  cout << str;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
