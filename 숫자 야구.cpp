//야구 게임
#include <iostream>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

// A : 123
// B : 1스트라이크 1볼.
// A : 356
// B : 1스트라이크 0볼.
// A : 327
// B : 2스트라이크 0볼.
// A : 489
// B : 0스트라이크 1볼.

void makeAlive(vector<int>& v, vector<int> v2, int cnt) {
    if(cnt == 3)
        return;
    
    for(vector<int>::iterator it=v2.begin(); it!=v2.end(); it++) {

    }
}

int solution(vector<vector<int>> baseball) {

    int a, b, c;

    a = baseball[0][0] / 100;
    b = (baseball[0][0] / 10) % 10;
    c = baseball[0][0] % 10;
    //0S 0B
    vector<int> ten(10);
    int tmp = 1;
    for(int& i: ten) {
        i = tmp;
        tmp++;
    }

    //0S 1B
    //0S 2B
    //0S 3B
    //1S 0B
    //1S 1B
    //1S 2B
    //2S 0B

    int answer = 0;
    return answer;
    
}

int main() {
    ios::sync_with_stdio(false);    
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> v = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};
    cout << solution(v);
}