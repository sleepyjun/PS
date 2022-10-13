// https://www.acmicpc.net/problem/18500 
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

int r, c;
char map[101][101];
bool visited[101][101];

const int MOVE[2] = {1, -1};
const int DIR[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

void print() {
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      cout << map[y][x];
    }
    cout << '\n';
  }
}

bool possible(int y, int x) {
  return (0 <= y && y < r) && (0 <= x && x < c);
}
void bfs() {
  std::fill(&visited[0][0], &visited[100][101], false);
  std::queue<pii> q;

  for (int x = 0; x < c; ++x) {
    if (map[r-1][x] == 'x') {
      q.push({r-1, x});
      visited[r-1][x] = true;
      while(!q.empty()) {
        pii curr = q.front(); q.pop();
        int cy = curr.first;
        int cx = curr.second;

        for (int d = 0; d < 4; ++d) {
          int ny = cy + DIR[d][0];
          int nx = cx + DIR[d][1];

          if (!possible(ny, nx)) continue;
          if (map[ny][nx] == 'x' && visited[ny][nx] == false) {
            q.push({ny ,nx});
            visited[ny][nx] = true;
          }
        }
      }
    }
  }

  std::vector<pii> block;
  bool flag = true;
  for (int y = 0; flag && y < r; ++y) {
    for (int x = 0; flag && x < c; ++x) {
      if (map[y][x] == 'x' && visited[y][x] == false) {
        flag = false;

        q.push({y, x});
        visited[y][x] = true;

        while(!q.empty()) {
          pii curr = q.front(); q.pop();
          int cy = curr.first;
          int cx = curr.second;
          block.push_back(curr);
          map[cy][cx] = '.';

          for (int d = 0; d < 4; ++d) {
            int ny = cy + DIR[d][0];
            int nx = cx + DIR[d][1];

            if (!possible(ny, nx)) continue;
            if (map[ny][nx] == 'x' && visited[ny][nx] == false) {
              q.push({ny ,nx});
              visited[ny][nx] = true;
            }
          }
        }
      }
    }
  }
  int down = 0;
  while (!block.empty()) {
    down++;
    bool flag = false;
    for (const pii &b: block) {
      int ny = b.first+down;
      int nx = b.second;

      if (!possible(ny, nx) || map[ny][nx] == 'x') {
        flag = true;
        down--;
        break;
      }
    }
    if (flag) {
      for (const pii &b: block) {
        map[b.first+down][b.second] = 'x';
      }
      break;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> r >> c;

  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      cin >> map[y][x];
    }
  }

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    int height; cin >> height;
    height = r - height;
    int start = (i % 2 == 0 ? 0 : c-1);

    for (int x = 0; x < c; ++x) {
      if (map[height][start] == 'x') {
        map[height][start] = '.';
        break;
      }
      start += MOVE[i%2];
    }

    bfs();
  }
  print();
}
// g++ -o a -std=c++17 *.cpp