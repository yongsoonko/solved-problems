#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;                   //걸린 시간
    int reach = 0;                    //도달한 차량 수
    int current = 0;                  //현재 무기
    int total = truck_weights.size(); //지나가야 하는 차량 수
    vector<int> traffic(total, -1);

    vector<int>::iterator it = truck_weights.begin();

    while (reach != total)
    {
        for (vector<int>::iterator it = traffic.begin(); it != traffic.end(); it++)
        {
            if (*it != -1)
            {
                if (bridge_length < *it + 1)
                {
                    reach++;
                    current -= truck_weights[it - traffic.begin()];
                    *it = -1;
                }
                else
                {
                    (*it)++;
                }
            }
        }
        if (it != truck_weights.end() && weight >= current + *it)
        {
            current += *it;
            traffic[it - truck_weights.begin()] = 1;
            it++;
        }
        answer++;
    }
    // cout << answer;
    return answer;
}

int main()
{
    int size, a, b;
    vector<int> tmp;
    cin >> size >> a >> b;

    for(int i=0; i<size; i++) {
        int weight;
        cin >> weight;
        tmp.push_back(weight);
    }
    solution(a, b, tmp);
}