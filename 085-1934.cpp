#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;
  for (int i = n; i--;) {
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    cout << a * b / g << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
