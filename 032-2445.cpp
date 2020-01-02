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

  int a, sign = 1;
  cin >> a;

  for (int i = 0; i < a && i > -1; i += sign) {
    for (int j = 0; j <= i; j++) {
      cout << '*';
    }
    for (int k = 0; k < a * 2 - (i + 1) * 2; k++) {
      cout << ' ';
    }
    for (int j = 0; j <= i; j++) {
      cout << '*';
    }
    if (i == a - 1)
      sign *= -1;
    cout << '\n';
  }
}
