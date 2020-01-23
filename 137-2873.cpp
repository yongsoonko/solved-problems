#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;
  vector<vector<short>> map(r, vector<short>(c));

  int min_happy = 1001, min_i, min_j;
  bool even = r % 2 == 0 && c % 2 == 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
      if (even && (i + j) % 2 == 1 && min_happy > map[i][j]) {
        min_i = i;
        min_j = j;
        min_happy = map[i][j];
      }
    }
  int i = 0, j = 0;
  if (even) {
    for (; i < min_i - (min_i % 2); i++) {
      if (i % 2 == 0)
        for (j = 1; j < c; j++)
          cout << 'R';
      else
        for (j = 1; j < c; j++)
          cout << 'L';
      cout << 'D';
    }
    for (j = 0; j < c - 1; j++) {
      if (j == min_j)
        cout << 'R';
      else {
        if (i % 2 == 0) {
          cout << "DR";
          i++;
        } else {
          cout << "UR";
          i--;
        }
      }
    }
    if (i % 2 == 0) {
      cout << 'D';
      i++;
    }
    if (i < r - 1) {
      cout << 'D';
      i++;
      for (; i < r; i++) {
        if (i % 2 == 0)
          for (j = 1; j < c; j++)
            cout << 'L';
        else
          for (j = 1; j < c; j++)
            cout << 'R';
        if (i < r - 1)
          cout << 'D';
      }
    }
  } else {
    if (r % 2 == 1) {
      for (; i < r; i++) {
        if (i % 2 == 0)
          for (j = 0; j < c - 1; j++)
            cout << 'R';
        else
          for (j = 0; j < c - 1; j++)
            cout << 'L';
        if (i < r - 1)
          cout << 'D';
      }
    } else {
      for (; j < c; j++) {
        if (j % 2 == 0)
          for (i = 0; i < r - 1; i++)
            cout << 'D';
        else
          for (i = 0; i < r - 1; i++)
            cout << 'U';
        if (j < c - 1)
          cout << 'R';
      }
    }
  }
}
