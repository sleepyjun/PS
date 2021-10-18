// https://www.acmicpc.net/problem/10164
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int dp[16][16];

int run(int cy, int cx, const int ey, const int ex) {
  if (cy == ey && cx == ex) return 1;
  if (cy > ey || cx > ex) return 0;

  int &ret = dp[cy][cx];
  if (ret != 0) return ret;

  ret += run(cy+1, cx, ey, ex);
  ret += run(cy, cx+1, ey, ex);

  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m, k; cin >> n >> m >> k;
  int res = 0;

  if (k == 0) {
    res = run(1,1,n,m);
  }
  else {
    k--;
    int dy = k / m + 1;
    int dx = k % m + 1;

    res = run(1,1,dy,dx);
    res *= run(dy,dx,n,m);
  }
  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp