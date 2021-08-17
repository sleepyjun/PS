// https://www.acmicpc.net/problem/19238
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using info = std::tuple<int, int, int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[4][2] = {
  {-1,0},
  {0,-1},
  {0,1},
  {1,0},
};

int n,m,f;
int map[21][21];
bool visited[21][21];
std::vector<info> client;

bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= n);
}
int visit(const int &sy, const int &sx,
          const int &dy, const int &dx) {
  std::fill(&visited[0][0], &visited[20][21], false);
  
  int cnt = 0;
  std::queue<pii> q;
  q.push({sy,sx}); visited[sy][sx] = true;
  while (!q.empty()) {
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      auto curr = q.front(); q.pop();
      int cy = curr.first;
      int cx = curr.second;

      if (cy == dy && cx == dx) return cnt;

      for (int d = 0; d < 4; ++d) {
        int ny = cy+DIR[d][0];
        int nx = cx+DIR[d][1];

        if (safe(ny, nx) == false) continue;
        if (visited[ny][nx] == true) continue;
        if (map[ny][nx] == 1) continue;

        visited[ny][nx] = true;
        q.push({ny,nx});
      }
    }
    cnt++;
  }
  return -1;
}
void run(int y, int x) {
  std::queue<pii> q;
  q.push({y,x}); visited[y][x] = true;
  int ty = 999, tx = 999;
  int cnt;
  int flag;
  if (map[y][x] < 0) {
    cnt = 0;
    flag = map[y][x];
  } else {
    cnt = 1;
    flag = 0;
  }

  while (!q.empty()) {
    int qSize = q.size();
    if (flag == 0) {
      for (int i = 0; i < qSize; ++i) {
        auto curr = q.front(); q.pop();
        int cy = curr.first;
        int cx = curr.second;

        for (int d = 0; d < 4; ++d) {
          int ny = cy+DIR[d][0];
          int nx = cx+DIR[d][1];
          if (safe(ny, nx) == false) continue;
          if (visited[ny][nx] == true) continue;
          if (map[ny][nx] == 1) continue;

          visited[ny][nx] = true;
          if (map[ny][nx] < 0) {
            if (ty > ny) {
              ty = ny;
              tx = nx;
              flag = map[ny][nx];
            } else if (ty == ny && tx > nx) {
              tx = nx;
              flag = map[ny][nx];
            }
          }
          q.push({ny,nx});
        }
      }
    }
    if (flag != 0) {
      flag *= -1;
      flag--;

      f -= cnt;
      if (f <= 0) return;
      
      int sy,sx,dy,dx;
      std::tie(sy,sx,dy,dx) = client[flag];
      cnt = visit(sy,sx,dy,dx);
      // cout << sy << ' ';
      // cout << sx << ' ';
      // cout << dy << ' ';
      // cout << dx << '\n';
      // cout << cnt << '\n';

      if (cnt == -1) return;
      f -= cnt;
      if (f < 0) return;
      f += cnt*2;

      map[sy][sx] = 0;
      std::fill(&visited[0][0], &visited[20][21], false);
      q = std::queue<pii>();
      q.push({dy,dx});
      if (map[dy][dx] < 0) {
        flag = map[dy][dx];
        cnt = 0;
      } else {
        flag = 0;
        cnt = 1;
      }
      ty = 999;
      tx = 999;
      m--;
    } else cnt++;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> f;

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }
  int y, x; cin >> y >> x;

  for (int i = 1; i <= m; ++i) {
    int sy,sx,dy,dx;
    cin >> sy >> sx >> dy >> dx;
    client.push_back({sy,sx,dy,dx});
    map[sy][sx] = -1*i;
  }

  run(y, x);
  cout << (m == 0 ? f : -1) << '\n';
}
// g++ -o a -std=c++17 *.cpp