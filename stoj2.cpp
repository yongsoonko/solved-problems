#include <iostream>
#include <string>
#include <vector>

using namespace std;
int size;
vector<string> vec;

void solution() {
  int i = 0, j = 0;
  for(; i<size; i++) {
    for(; j<size; j++) {
      string row = vec[i];
      if(i <= size - 5 && j <= size - 5) {
        if(vec[i][j] == vec[i+1][j+1] && vec[i+1][j+1] == vec[i+2][j+2] &&
        vec[i+2][j+2] == vec[i+3][j+3] && vec[i+3][j+3] == vec[i+4][j+4]) {
          cout << row[j];
        }
      }
      if(j <= size - 5) {
        if(row[j] == row[j+1] && row[j+1] == row[j+2] &&
        row[j+2] == row[j+3] && row[j+3] == row[j+4]) {
          cout << row[j];
        }
      }
      if(i <= size - 5) {
        if(vec[i][j] == vec[i+1][j] && vec[i+1][j] == vec[i+2][j] &&
        vec[i+2][j] == vec[i+3][j] && vec[i+3][j] == vec[i+4][j]) {
          cout << row[j];
        }
      }
    }
  }
}

int main() {
  cin >> size;
  vec.reserve(size);
  for(int idx=0; idx<size; idx++) {
    string tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  solution();
  // for(string s: vec) {
  //   printf("%s\n", s.c_str());
  // }
}