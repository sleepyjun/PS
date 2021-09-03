// https://www.acmicpc.net/problem/19237
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[5][2] = {
  {0,0},
  {-1,0},
  {1,0},
  {0,-1},
  {0,1}
};
struct Shark {
  int y,x;
  int idx;

  Shark(int _y, int _x, int _idx) : y(_y), x(_x), idx(_idx) {}
  bool operator < (const Shark &b) {
    return this->idx < b.idx;
  }
};

int n,m,k;
int map[20][20], sharkDir[401], dirPriority[401][5][4];
pii smellMap[20][20];

bool safe(const int &y, const int &x) {
  return (0 <= y && y < n) && (0 <= x && x < n);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> k;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      int &shark = map[y][x]; 
      cin >> shark;
      
      if (shark == 0) continue;
      smellMap[y][x] = {shark, k};
    }
  }

  for (int i = 1; i <= m; ++i) {
    cin >> sharkDir[i];
  }

  for (int i = 1; i <= m; ++i) { // n th shark's
    for (int j = 1; j <= 4; ++j) { // dir (1 to 4)
      for (int k = 0; k < 4; ++k) { // priority
        int d; cin >> d;
        dirPriority[i][j][k] = d;
      }
    }
  }

  for (int time = 1; time <= 1000; ++time) {
    std::vector<Shark> v;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        int shark = map[y][x];
        if (shark == 0) continue;

        bool flag = false;
        int cd = sharkDir[shark];
        map[y][x] = 0;

        for (int i = 0; i < 4; ++i) {
          int nd = dirPriority[shark][cd][i];
          int ny = y + DIR[nd][0];
          int nx = x + DIR[nd][1];

          if (false == safe(ny,nx)) continue;
          if (smellMap[ny][nx].second != 0) continue;

          flag = true;

          v.push_back({ny,nx,shark});
          sharkDir[shark] = nd;
          break;
        }

        if (true == flag) continue;

        for (int i = 0; i < 4; ++i) {
          int nd = dirPriority[shark][cd][i];
          int ny = y + DIR[nd][0];
          int nx = x + DIR[nd][1];

          if (false == safe(ny,nx)) continue;
          if (smellMap[ny][nx].first != shark) continue;

          v.push_back({ny,nx,shark});
          sharkDir[shark] = nd;
          break;
        }
      }
    }

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (smellMap[y][x].second == 0) continue;
        smellMap[y][x].second--;
      }
    }

    std::sort(v.begin(), v.end());
    for (const Shark &s: v) {
      if (map[s.y][s.x] != 0) {
        m--;
        continue;
      }

      map[s.y][s.x] = s.idx;
      smellMap[s.y][s.x] = {s.idx, k};
    }

    if (m == 1) {
      cout << time << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
}
// g++ -o a -std=c++17 *.cpp