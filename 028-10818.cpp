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

  int a, min, max;
  cin >> a;
  for(int i=0; i<a; i++) {
    int tmp;
    cin >> tmp;
    if(i==0) {
      min = max = tmp;
    } else {
      if(min > tmp) min = tmp;
      if(max < tmp) max = tmp;
    }
  }
  cout << min << " " << max;
}
