#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int size;
vector<vector<string>> vec;

void solution() {
  for(int idx=0; idx<size; idx++) {
    float a, b;
    int c, d;
    bool e = false, f = false;
    string op = vec[idx][1];
    if(vec[idx][0].find(".") != string::npos) {
      a = std::atof(vec[idx][0].c_str());
      e = true;
    } else {
      c = std::atoi(vec[idx][0].c_str());
      a = c;
    }
    if(vec[idx][2].find(".") != string::npos) {
      b = std::atof(vec[idx][2].c_str());
      f = true;
    } else {
      d = std::atoi(vec[idx][2].c_str());
      b = d;
    }

    if(op == "+") {
      if(e || f) {
        // printf("%.6f\n", a + b);
        cout.precision(6);
        cout << a + b << endl;
      } else {
        printf("%d\n", c + d);
      }
    } else if(op == "-") {
      if(e || f) {
        // printf("%.6f\n", a - b);
        cout.precision(6);
        cout << a - b << endl;
      } else {
        printf("%d\n", c - d);
      }
    } else if(op == "**") {
      if(e || f) {
        // printf("%.6f\n", float(std::pow(a, b)));
        cout.precision(6);
        cout << float(std::pow(a, b)) << endl;
      } else {
        printf("%d\n", int(std::pow(c, d)));
      }
    } else if(op == "*") {
      if(e || f) {
        // printf("%.6f\n", a * b);
        cout.precision(6);
        cout << a * b << endl;
      } else {
        printf("%d\n", c * d);
      }
    } else if(op == "/") {
      if(e || f) {
        // printf("%.6f\n", a / b);
        cout.precision(6);
        cout << a / b << endl;
      } else {
        printf("%d\n", c / d);
      }
    }
    else if(op == "%") {
      // printf("%d\n", int(a) % int(b));
        cout.precision(6);
        cout << int(a) % int(b) << endl;
    }
  }
}

int main() {
  cin >> size;
  vec.reserve(size);
  for(vector<string> s: vec) {
    s.reserve(3);
  }
  for(int i=0; i<size; i++) {
    vector<string> tmp2;
    for(int j=0; j<3; j++) {
      string tmp;
      cin >> tmp;
      tmp2.push_back(tmp);
    }
    vec.push_back(tmp2);
  }
  solution();
  // for(vector<string> s: vec) {
  //   for(string str: s) {
  //     printf("%s\n", str.c_str());
  //   }
  // }
}