#include <iostream>
#include <time.h>

using namespace std;

void solution(int a) {
  if(a == 3) {
    cout << "***\n* *\n***\n";
  } else {
    int tmp = a / 3;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < tmp; j++) {
        for (int k = tmp / 3; k >= 1; k /= 3) {
          if ((i / (k * 3)) % 3 == 1 && (j / k) % 3 == 1) {
            cout << "   ";
            break;
          }
          if (k == 1) {
            if (i % 3 == 1) {
              cout << "* *";
            } else {
              cout << "***";
            }
          }
        }
      }
      cout << '\n';
    }
  }
}

int main() {
  int num;
  cin >> num;

  // clock_t start = clock();
  solution(num);
  // float time = (clock() - start) / CLOCKS_PER_SEC;
  // printf("time : %f\n", time);
  // return 1;
}
