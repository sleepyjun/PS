// https://www.acmicpc.net/problem/2563 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[101][101];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int answer = 0;
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int y, x; cin >> y >> x;
    for (int u = 0; u < 10; ++u) {
      for (int v = 0; v < 10; ++v) {
        if (visited[y+u][x+v]) continue;
        visited[y+u][x+v] = true;
        answer++;
      }
    }
  }

  cout << answer << '\n';
}
// g++ -o a -std=c++17 *.cpp