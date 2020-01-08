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

  int a;
  cin >> a;
  for(int i=0; i<a; i++) {
    string input;
    int a, b;
    cin >> input;
    a = input[0] - '0';
    b = input[2] - '0';
    cout << a + b << '\n'; 
  }
}
