#include <iostream>
#include <vector>

using namespace std;
int k;
vector<int> vec;

void solution() {

}

bool isPrime(int num) {
  int last = num / 2;
  for(int tmp=2; tmp <= last; tmp++) {
    if(num % tmp == 0) return false; 
  }
  if(num == last + 1) return true;
}

int main() {
  cin >> k;
  for(int i=0; i<5; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  for(int i: vec) {
    cout << i << endl;
  }
  vector<int> prime;
  prime.reserve(5);
  for(int i=k; tmp.size() < 5; i++) {
    if(isPrime(i)) {
      prime.push_back(i);
    }
  }
  for(int i: prime) {
    cout << i << endl;
  }
  solution();
}