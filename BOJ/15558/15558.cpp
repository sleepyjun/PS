// https://www.acmicpc.net/problem/15558
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

int map[2][100005];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n,k; cin >> n >> k;

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch; cin >> ch;
      map[i][j] = ch-'0';
    }
  }

  bool clear = false;
  int sec = 1;
  std::queue<pii> q; q.push({0,1});
  while(!q.empty() && !clear) {
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      auto curr = q.front(); q.pop();
      int line = curr.first;
      int floor = curr.second;

      if (floor > n) {
        clear = true;
        break;
      }
      if (map[line][floor] == 0) continue;
      map[line][floor] = 0;

      int next = floor+k;
      q.push({(line+1)%2, next});
      
      next = floor+1;
      q.push({line, next});
      
      next = floor-1;
      q.push({line, next});
    }
    map[0][sec] = map[1][sec] = 0;
    sec++;
  }

  if (true == clear) cout << 1;
  else cout << 0;
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp