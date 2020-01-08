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

  //참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지,
  //4, 6, 9, 11월은 30일까지, 2월은 28일
  int a, b, firstDayOfMonth = 1;
  string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

  cin >> a >> b;
  if (a == 1) {
    cout << days[(firstDayOfMonth + b - 1) % 7];
  } else {
    for (int i = 1; i < a; i++) {
      switch (i) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        firstDayOfMonth = (firstDayOfMonth + 31) % 7;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        firstDayOfMonth = (firstDayOfMonth + 30) % 7;
        break;
      case 2:
        firstDayOfMonth = (firstDayOfMonth + 28) % 7;
        break;
      }
    }
    cout << days[(firstDayOfMonth + b - 1) % 7];
  }
}