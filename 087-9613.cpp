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

  int t;
  cin >> t;
  for (int i = t; i--;) {
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (int j = n; j--;) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        sum += gcd(v[i], v[j]);
      }
    }
    cout << sum << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
