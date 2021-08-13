// https://www.acmicpc.net/problem/17142
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
const int DIR[4][2] = {
  {0,1},
  {1,0},
  {0,-1},
  {-1,0}
};

int n, m, zero;
int map[51][51];
bool visited[51][51];
std::vector<pii> virus;

inline bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= n);
}

int bfs(std::queue<pii> q) {
  int cnt = 0;
  if (zero == cnt) return 0;

  int time = 1;

  while (!q.empty()) {
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      int cy = q.front().first;
      int cx = q.front().second;
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int ny = cy+DIR[d][0];
        int nx = cx+DIR[d][1];

        if (false == safe(ny,nx)) continue;
        if (map[ny][nx] == 1) continue;
        if (true == visited[ny][nx]) continue;

        if (map[ny][nx] == 0) cnt++;

        visited[ny][nx] = true;
        q.push({ny,nx});
      }
    }

    if (zero == cnt) {
      return time;
    }
    time++;
  }

  return INF;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
      
      if (map[y][x] == 2)
        virus.push_back({y,x});
      else if (map[y][x] == 0) zero++;
    }
  }

  std::vector<int> lot(virus.size(), 1);
  for (int i = 0; i < m; ++i) lot[i] = 0;

  int min = INF;
  do {
    std::fill(&visited[0][0], &visited[50][51], false);
    std::queue<pii> q;
    for (int i = 0; i < lot.size(); ++i) {
      if (lot[i] == 0) {
        int y = virus[i].first;
        int x = virus[i].second;

        q.push({y,x});
        visited[y][x] = true;
      }
    }

    min = std::min(min, bfs(q));
  } while (std::next_permutation(lot.begin(), lot.end()));

  cout << (min == INF ? -1 : min) << '\n';
}
// g++ -o a -std=c++17 *.cpp