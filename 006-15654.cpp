#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m;

void solution(vector<int>& v, vector<int>& v2, int round) {
    if(round==m) {
        for(int i: v2) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    int temp;
    vector<int>::iterator temp2;

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
        temp = *it;
        v2.push_back(temp);
        temp2 = v.erase(it);

        solution(v, v2, round+1);

        v.insert(temp2, temp);
        v2.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    vector<int> v, v2;

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    solution(v, v2, 0);
}