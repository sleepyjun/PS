// https://www.acmicpc.net/problem/15806 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[8][2] = {
  {-2, 1},
  {-1, 2},
  {1, 2},
  {2, 1},
  {2, -1},
  {1, -2},
  {-1, -2},
  {-2, -1},
};
bool visited[301][301][2];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::queue<pii> q;
  int n, m, k, t; cin >> n >> m >> k >> t;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    q.push({x, y});
    visited[x][y][0] = true;
  }

  for (int i = 0; i < t; ++i) {
    int qSize = q.size();
    for (int j = 0; j < qSize; ++j) {
      int cx = q.front().first;
      int cy = q.front().second;
      q.pop();

      if (i < 3) {
        visited[cx][cy][i%2] = false;
      }

      for (int d = 0; d < 8; ++d) {
        int nx = cx + DIR[d][0];
        int ny = cy + DIR[d][1];

        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (visited[cx][cy][(i+1)%2]) continue;
        visited[cx][cy][(i+1)%2] = true;
        q.push({cx, cy});
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y;
    if (visited[x][y][t%2]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
// g++ -o a -std=c++17 *.cpp