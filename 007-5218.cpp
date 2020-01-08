#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sol(int cnt, vector<vector<string>> v) {
    vector<vector<int>> ans;
    for(int i=0; i<(int)v.size(); i++) {
    vector<int> tmp;
        for(int j=0; j<(int)v[i].front().size(); j++) {
            if((int)v[i].front()[j] <= (int)v[i].back()[j]) {
                tmp.push_back((int)v[i].back()[j] - (int)v[i].front()[j]);
            } else {
                tmp.push_back((int)v[i].back()[j] - (int)v[i].front()[j] + 26);
            }
        }
        ans.push_back(tmp);
        vector<int>().swap(tmp);
    }
    
    for(vector<int> i: ans) {
        cout << "Distances: ";
        for(int j: i) {
           cout << j << ' '; 
        }
        cout << '\n';
    }
}

int main() {
    
    int cnt, i = 0;
    
    cin >> cnt;
    vector<vector<string>> v;
    while(i < cnt) {
        string s1, s2;
        cin >> s1 >> s2;
        v.push_back(vector<string>{s1, s2});
        
        i++;
    }
    sol(cnt, v);
    return 0;

}