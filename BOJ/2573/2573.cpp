// https://www.acmicpc.net/problem/2573 
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
using iii = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};
int n, m;
int map[301][301];

void print() {
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      cout << map[y][x] << ' ';
    }
    cout << '\n';
  }
}
bool position(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= m);
}

int bfs() {
  int cnt = 0;
  bool visited[301][301] = {false,};

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      if (visited[y][x] == false && map[y][x] != 0) {
        std::queue<pii> q;
        q.push({y, x});
        visited[y][x] = true;
        while (!q.empty()) {
          const pii &curr = q.front(); q.pop();
          int y = curr.first;
          int x = curr.second;

          for (int i = 0; i < 4; ++i) {
            int ny = y + DIR[i][0];
            int nx = x + DIR[i][1];

            if (map[ny][nx] == 0) continue;
            if (position(ny, nx) == false) continue;
            if (visited[ny][nx] == true) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
          }
        }
        cnt++;
      }
    }
  }
  return cnt;
}

bool melt() {
  bool flag = false;
  std::vector<iii> melted;

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      if (map[y][x] != 0) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
          int ny = y + DIR[i][0];
          int nx = x + DIR[i][1];
          if (map[ny][nx] == 0) cnt++;
        }
        melted.push_back({y, x, cnt});
        flag = true;
      }
    }
  }

  for (const iii &info: melted) {
    int y, x, cnt;
    std::tie(y, x, cnt) = info;

    map[y][x] = (map[y][x] - cnt) < 0 ? 0 : (map[y][x] - cnt);
  }
  return flag;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      cin >> map[y][x];
    }
  }
  int year = 0;
  while (1) {
    // print();
    if (bfs() >= 2) break;
    if (melt() == false) {
      year = 0;
      break;
    }

    year++;
  }

  cout << year << '\n';
}
// g++ -o a -std=c++17 *.cpp