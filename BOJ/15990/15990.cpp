// https://www.acmicpc.net/problem/15990
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MOD = 1e9+9;

int dp[100001][4];

void init() {  
    dp[1][1] = dp[2][2] = dp[3][3] = 1;
    for (int i = 3; i <= 100000; ++i) {
      for (int a = 1; a <= 3; ++a) {
        int b = i-a;
        for (int j = 1; j <= 3; ++j) {
          if (a == j) continue;
          dp[i][a] = (dp[i][a] + dp[b][j])%MOD;
        }
      }
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  init();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= 3; ++i) {
      sum = (sum + dp[n][i])%MOD;
    }
    cout << sum << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp