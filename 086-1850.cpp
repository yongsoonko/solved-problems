#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  long long a, b;
  cin >> a >> b;
  int g = gcd(a, b);

  for (int i = g; i--;) {
    cout << '1';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
