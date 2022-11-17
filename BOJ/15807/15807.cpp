// https://www.acmicpc.net/problem/15807 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int alpha = 1501;
const int MAX = 3002;
int dp[MAX][MAX];
int yx[MAX][MAX], _yx[MAX][MAX];
int light[MAX][MAX];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    light[x+alpha][y+alpha]++;
  }

  for (int y = 1; y < MAX; ++y) {
    for (int x = 1; x < MAX; ++x) {
      dp[x][y] = dp[x][y-1] + light[x][y] + yx[x-1][y-1] + _yx[x+1][y-1];
      yx[x][y] = yx[x-1][y-1] + light[x][y];
      _yx[x][y] = _yx[x+1][y-1] + light[x][y];
    }
  }

  int p; cin >> p;
  for (int i = 0; i < p; ++i) {
    int x, y; cin >> x >> y;
    cout << dp[x+alpha][y+alpha] << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp