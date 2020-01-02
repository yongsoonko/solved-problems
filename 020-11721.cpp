#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution() {
  int ans = 0;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  cin >> input;
  for(int i=0; i<input.length(); i++) {
    if(i%10 == 0 && i!=0) {
      cout << '\n';
    }
    cout << input[i];
  }
  // for(int i=0; i<input.length(); i+=10) {
  //   string tmp = input.substr(i, 10);
  //   cout << tmp << '\n';
  // }
}
