// https://www.acmicpc.net/problem/9465
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 100000;

int arr[MAX+1][2];
int dp[MAX+1][2];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    std::fill(&arr[0][0], &arr[MAX][2], 0);
    std::fill(&dp[0][0], &dp[MAX][2], 0);

    int n; cin >> n;
    for (int j = 0; j <= 1; ++j)
      for (int i = 1; i <= n; ++i)
        cin >> arr[i][j];
    
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    int res = std::max(dp[1][0], dp[1][1]);
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j <= 1; ++j) {
        dp[i][j] = arr[i][j] + std::max(std::max(dp[i-2][0], dp[i-2][1]),dp[i-1][(j+1)%2]);
        res = std::max(res, dp[i][j]);
      }
    }

    cout << res << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp