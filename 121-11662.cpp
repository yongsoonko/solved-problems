#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void search(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
  double px, px2, py, py2, qx, qx2, qy, qy2, d_p, d_q;
  while (abs(bx - ax) > 0.0000000001) {
    px = ax + (bx - ax) / 3.,
    px2 = cx + (dx - cx) / 3.,
    py = ay + (by - ay) / 3.,
    py2 = cy + (dy - cy) / 3.,
    qx = bx - (bx - ax) / 3.,
    qx2 = dx - (dx - cx) / 3.,
    qy = by - (by - ay) / 3.,
    qy2 = dy - (dy - cy) / 3.,
    d_p = pow(px2 - px, 2) + pow(py2 - py, 2),
    d_q = pow(qx2 - qx, 2) + pow(qy2 - qy, 2);
    if (d_p > d_q)
      ax = px, ay = py, cx = px2, cy = py2;
    else
      bx = qx, by = qy, dx = qx2, dy = qy2;
  }
  cout << setprecision(10);
  cout << sqrt(d_p);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int ax, ay, bx, by, cx, cy, dx, dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

  search(ax, ay, bx, by, cx, cy, dx, dy);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}