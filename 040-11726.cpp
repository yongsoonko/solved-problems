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
  clock_t start = clock();

  int a, b, c;
  a = 1;
  b = 2;
  if(n == 1) cout << a;
  else if(n == 2) cout << b;
  else {
    for(int i=3; i<=n; i++) {
      c = (a + b) % 10007;
      a = b;
      b = c;
    }
    cout << c;
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << _time;
}
