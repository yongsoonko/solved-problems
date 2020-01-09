#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, k;
  cin >> n >> k;
  list<int> l, tmp;
  vector<int> v;
  v.reserve(n);
  for (int i = 1; i <= n; i++) {
    l.push_back(i);
    tmp.push_back(i);
  }

  // // 리스트 사용 예시
  // for (int i : tmp)
  //   cout << i << ' ';
  // cout << '\n';
  // auto tmp2 = tmp.begin();
  // cout << "list.begin()\t" << *tmp2 << '\n'; // 처음 요소 출력
  // tmp2 = tmp.end();
  // cout << "list.end()\t" << *tmp2 << '\n'; // 마지막 요소 출력
  // tmp2--;                                 // 실제 마지막 요소를 가리키고 있다.
  // cout << "list.end()-1\t" << *tmp2 << '\n'; // 마지막 요소 출력

  // // 마지막 요소가 출력된다고 erase에도 이렇게 넣으면 절대 안된다.
  // // tmp.erase(tmp.end());  
  // // 올바른 사용 예 #1: 대신 tmp2를 아래에서 사용하면 절대 안된다.
  // // list 원소 삭제 시 주의사항: http://blog.naver.com/picbuddy/80032246219
  // tmp.erase(tmp2); 
  // for (int i : tmp)
  //   cout << i << ' ';
  // cout << '\n';
  // // 출력된 리스트에 접근 중인 *tmp2 값은 삭제되고 없다.
  // cout << "erase *tmp2\t" << *tmp2 << '\n';

  // tmp2 = tmp.end();
  // // advance(tmp.end(), 0);      // tmp.end()를 인자로 못넣는다.
  // // advance(tmp2, 0); // tmp2가 tmp.end()이므로 erase에 넣으면 절대안된다.
  // advance(tmp2, -1);
  // tmp2 = tmp.erase(tmp2); // 올바른 사용 예 #1
  // for (int i : tmp)
  //   cout << i << ' ';
  // cout << '\n';
  // cout << "erase *tmp2\t" << *tmp2 << '\n';

  // tmp2 = tmp.end();
  // advance(tmp2, -1);
  // tmp.erase(tmp2--);  // 올바른 사용 예 #2
  // for (int i : tmp)
  //   cout << i << ' ';
  // cout << '\n';
  // cout << "erase *tmp2\t" << *tmp2 << '\n';
  // // 순차 접근과 달리 임의접근이 가능한 벡터는 end()값이 ?이다.
  // vector<int> tmp3 = {1, 2, 3};
  // cout << "*(vector.end())\t" << *(tmp3.end()) << '\n';

  auto it = l.begin();
  while (!l.empty()) {
    for (int i = 0; i < k - 1; i++) {
      it++;
      if (it == l.end())
        it = l.begin();
    }
    v.push_back(*it);
    it = l.erase(it);
    if (it == l.end())
      it = l.begin();
  }

  cout << '<';
  for (int i = 0; i < n; i++) {
    if (i < n - 1)
      cout << v[i] << ", ";
    else
      cout << v[i] << '>';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
