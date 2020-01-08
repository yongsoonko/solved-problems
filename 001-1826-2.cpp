#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	clock_t start = clock();

	int _n, cnt = 0;
	int _l, _p, _d = 0;
	cin >> _n;

	vector<vector<int> > stations(_n, vector<int>(0));
	int distance = 0, fuel = 0;
	for (vector<int>& i : stations) {
		cin >> distance >> fuel;
		i.push_back(distance);
		i.push_back(fuel);
	}

	sort(stations.begin(), stations.end());
	//for (auto i : stations) {
	//	cout << i[0] << " ";
	//}
	//cout << endl;

	vector<vector<int> >::iterator it = stations.begin();

	cin >> _l >> _p;
	vector<int> sortedFuel(0);

	//for (auto i : stations) {
	//	cout << i[0] << " " << i[1] << " ";
	//}
	//cout << endl;

	//for (auto i : sortedFuel) {
	//	cout << i << " ";
	//}
	//cout << endl;
	do {
		_d += _p;

		//초기 연료량으로 도착 가능
		if (_d >= _l) {
			break;
		}
		for (; it != stations.end(); it++) {
			if ((*it)[0] > _d) {
				break;
			}
			sortedFuel.push_back(((*it)[1]));
		}

		//오름차순
		//cout << "sortedFuel: " << sortedFuel.size() << endl;
		if (sortedFuel.size() == 0 && _d < _l) {
			cout << -1 << endl;
			return 0;
		}
		//런타임 에러
		sort(sortedFuel.begin(), sortedFuel.end());

		//cout << "sort: ";
		////런타임 에러
		//for (auto i : sortedFuel) {
		//	cout << i << " ";
		//}
		//cout << endl;

		// 정지
		_p = sortedFuel.back();
		sortedFuel.pop_back();
		cnt += 1;

	} while (_d < _l);

	cout << cnt << endl;

	//printf("\n\n걸린 시간:%lf\n", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}