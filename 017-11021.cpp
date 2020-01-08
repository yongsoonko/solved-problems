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
  for(int i=1; i<=a; i++) {
    int a, b;
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << '\n';
  }
}
