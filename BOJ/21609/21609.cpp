// https://www.acmicpc.net/problem/21609
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

struct BlockGroupInfo {
  int y,x;
  int cnt;
  int rainbow;
  BlockGroupInfo() 
    : y(-1), x(-1), cnt(0), rainbow(0) {}
  BlockGroupInfo(int _y, int _x) 
    : y(_y), x(_x), cnt(0), rainbow(0) {}
  BlockGroupInfo(int _y, int _x, int _c, int _r)
    : y(_y), x(_x), cnt(_c), rainbow(_r) {}

  bool operator < (const BlockGroupInfo &b) const {
    if (this->cnt != b.cnt) return this->cnt < b.cnt;
    if (this->rainbow != b.rainbow) return this->rainbow < b.rainbow;
    if (this->y != b.y) return this->y < b.y;
    return this->x < b.x;
  }
  friend std::ostream& operator << (std::ostream &os, const BlockGroupInfo &info);
};
std::ostream& operator << (std::ostream &os, const BlockGroupInfo &info) {
  os << info.y << ' ' << info.x << ' ' << info.cnt << ' ' << info.rainbow;
  return os;
}


int n, m;
int map[21][21];
bool visited[21][21];

bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= n);
}
void clean() {
  for (int y = 1; y <= n; ++y) {
      for (int x = 1; x <= n; ++x) {
        if (map[y][x] == 0) visited[y][x] = false;
      }
    }
}
BlockGroupInfo findBlockGroup(const int &y, const int &x) {
  BlockGroupInfo info(y,x);
  const int num = map[y][x];
  std::queue<pii> q;
  q.push({y,x}); visited[y][x] = true;

  int cnt = 0;
  int rainbow = 0;
  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    int cy = curr.first;
    int cx = curr.second;

    if (map[cy][cx] == 0) rainbow++;
    else if (map[cy][cx] == num) cnt++;

    for (int d = 0; d < 4; ++d) {
      int ny = cy + DIR[d][0];
      int nx = cx + DIR[d][1];

      if (false == safe(ny,nx)) continue;
      if (visited[ny][nx] == true) continue;

      if (map[ny][nx] == num || map[ny][nx] == 0) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }

  cnt += rainbow;
  info.cnt = cnt;
  info.rainbow = rainbow;

  return info;
}

void boom(const int &y, const int &x) {
  const int num = map[y][x];
  std::queue<pii> q;
  q.push({y,x}); visited[y][x] = true;


  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    int cy = curr.first;
    int cx = curr.second;
    
    map[cy][cx] = -2;

    for (int d = 0; d < 4; ++d) {
      int ny = cy + DIR[d][0];
      int nx = cx + DIR[d][1];

      if (false == safe(ny,nx)) continue;
      if (visited[ny][nx] == true) continue;

      if (map[ny][nx] == num || map[ny][nx] == 0) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
}
void down() {
  for (int y = n; y >= 1; --y) {
    for (int x = 1; x <= n; ++x) {
      if (map[y][x] != -2) continue;

      int cy = y;
      int ny = y-1;

      while (ny) {
        if (map[ny][x] == -1) break;
        else if (map[ny][x] != -2) {
          std::swap(map[cy][x], map[ny][x]);
          cy--;
        }
        ny--;
      }
    }
  }
}
void ccw() {
  int temp[21][21];
 
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      temp[y][x] = map[x][n-y+1];
    }
  }

  std::copy(&temp[0][0], &temp[20][21], &map[0][0]);
}
void print() {
  cout << "==========================\n";
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cout << map[y][x] << ' ';
    }
    cout << '\n';
  }
  cout << "==========================\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }

  int sum = 0;
  while (1) {
    std::fill(&visited[0][0], &visited[20][21], false);

    int fy, fx;
    BlockGroupInfo del;
    for (int y = 1; y <= n; ++y) {
      for (int x = 1; x <= n; ++x) {
        if (map[y][x] <= 0) continue;
        if (visited[y][x] == true) continue;
        del = std::max(findBlockGroup(y,x), del);
        clean();
      }
    }
    if (del.cnt <= 1) break;
    // cout << del << '\n';
    sum += (del.cnt * del.cnt);
    std::fill(&visited[0][0], &visited[20][21], false);
    boom(del.y, del.x);
    down();
    ccw();
    down();
    // print();
  }

  cout << sum << '\n';
}
// g++ -o a -std=c++17 *.cpp