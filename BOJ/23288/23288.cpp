// https://www.acmicpc.net/problem/23288
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
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
};
const int DICE[4][6] = {
  //0 top, 1 north, 2 east, 3 west, 4 south, 5 bottom
  {1, 5, 2, 3, 0, 4}, //to north
  {2, 1, 5, 0, 4, 3}, //to east
  {4, 0, 2, 3, 5, 1}, //to south
  {3, 1, 0, 5, 4, 2}, //to west
};
int dice[] = {1, 2, 3, 4, 5, 6};
int n, m, k;
int map[21][21];
int conMap[21][21];

bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= m);
}

void init() {
  bool visited[21][21];
  std::fill(&visited[0][0], &visited[20][21], false);

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      if (visited[y][x] == true) continue;
      else {
        int node = map[y][x];
        std::queue<pii> q;
        std::vector<pii> v;
        q.push({y,x});
        visited[y][x] = true;
        
        while(!q.empty()) {
          pii curr = q.front(); q.pop();
          v.push_back(curr);

          int cy = curr.first;
          int cx = curr.second;
          for (int d = 0; d < 4; ++d) {
            int ny = cy + DIR[d][0];
            int nx = cx + DIR[d][1];

            if (false == safe(ny, nx)) continue;
            if (true == visited[ny][nx]) continue;
            if (node != map[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
          }
        }

        for (auto p: v) conMap[p.first][p.second] = v.size();
      }
    }
  }
}

int dy = 1, dx = 1;
int diceDir = 1;

int move() {
  int ny = dy + DIR[diceDir][0];
  int nx = dx + DIR[diceDir][1];

  if (false == safe(ny, nx)) diceDir = (diceDir+2) % 4;
  ny = dy + DIR[diceDir][0];
  nx = dx + DIR[diceDir][1];

  int temp[6];
  for (int i = 0; i < 6; ++i)
    temp[DICE[diceDir][i]] = dice[i];
  std::copy(temp, temp+6, dice);

  int bottom = dice[5];
  if(bottom > map[ny][nx]) diceDir = (diceDir+1) % 4;
  else if(bottom < map[ny][nx]) diceDir = (diceDir+3) % 4;

  dy = ny; dx = nx;
  return map[ny][nx] * conMap[ny][nx];
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> k;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      cin >> map[y][x];
    }
  }
  init();

  int res = 0;
  while(k--) {
    res += move();
  }

  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp