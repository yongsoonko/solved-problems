#include <time.h>
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

  int n;
  cin >> n;

  int a = 1, b = 3, c;

  if(n == 1) {
    cout << a;
  } else if(n == 2) {
    cout << b;
  } else {
    for(int i=3; i<=n; i++) {
      c = (2 * a + b) % 10007;
      a = b;
      b = c;
    }
    cout << c;
  }
}

