// https://www.acmicpc.net/problem/6156 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool arr[101][101];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m; cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    arr[u][v] = true;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (arr[i][k] & arr[k][j]) {
          arr[i][j] = true;
        }
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    int count = 0;
    for (int j = 1; j <= n; ++j) {
      if (arr[i][j] || arr[j][i]) {
        count++;
      }
    }
    if (count == n-1) {
      answer++;
    }
  }

  cout << answer << '\n';
}
// g++ -o a -std=c++17 *.cpp