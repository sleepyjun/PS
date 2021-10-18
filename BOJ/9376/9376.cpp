// https://www.acmicpc.net/problem/9376
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
const int N = 102;
const int DIR[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

char map[N][N];
int h, w;
int visited[3][N][N];

bool safe(int y, int x) {
  return (0 <= y && y <= h+1) && (0 <= x && x <= w+1);
}
void run(int c, int y, int x) {
  std::queue<pii> q;
  q.push({y, x});
  visited[c][y][x] = 0;

  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    int cy = curr.first;
    int cx = curr.second;

    for (int d = 0; d < 4; ++d) {
      int ny = cy + DIR[d][0];
      int nx = cx + DIR[d][1];

      if (!safe(ny, nx)) continue;
      if (map[ny][nx] == '*') continue;

      if (map[ny][nx] == '#') {
        if (visited[c][ny][nx] == -1 || visited[c][ny][nx] > visited[c][cy][cx]+1) {
          visited[c][ny][nx] = visited[c][cy][cx]+1;
          q.push({ny, nx});
        } 
      }
      else {
        if (visited[c][ny][nx] == -1 || visited[c][ny][nx] > visited[c][cy][cx]) {
          visited[c][ny][nx] = visited[c][cy][cx];
          q.push({ny, nx});
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;

  while (t--) {
    std::fill(&map[0][0], &map[N-1][N], '.');
    std::fill(&visited[0][0][0], &visited[2][N-1][N], -1);
    cin >> h >> w;
    int y1 = -1, x1;
    int y2, x2;
    for (int y = 1; y <= h; ++y) {
      for (int x = 1; x <= w; ++x) {
        cin >> map[y][x];
        if (map[y][x] == '$' && y1 == -1) {
          y1 = y;
          x1 = x;
        } else if(map[y][x] == '$' && y1 != -1) {
          y2 = y;
          x2 = x;
        }
      }
    }

    run(0,0,0);
    run(1, y1,x1);
    run(2, y2,x2);

    int res = INF;
    for (int y = 0; y <= h+1; ++y) {
      for (int x = 0; x <= w+1; ++x) {
        if(visited[0][y][x] >= 0) {
          int sum = visited[0][y][x] - ((map[y][x] == '#') * 2);
          sum += (visited[1][y][x] + visited[2][y][x]);
          res = std::min(res, sum);
        }
      }
    }
    cout << res << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp