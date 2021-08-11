// https://www.acmicpc.net/problem/16235
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <tuple>
#include <deque>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[8][2] = {
  {-1,-1},
  {-1, 0},
  {-1, 1},
  { 0,-1},
  { 0, 1},
  { 1,-1},
  { 1, 0},
  { 1, 1}
};
int n,m,k; 
int base[11][11], food[11][11];
std::deque<int> map[11][11];
std::queue<iii> q;

inline bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= n);
}

void eat() {
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      int size = map[y][x].size();
      for (int i = 0; i < size; ++i) {
        const int &tree = map[y][x][0];
        
        if (food[y][x] >= tree) {
          food[y][x] -= tree;
          map[y][x].push_back(tree+1);
        } else {
          q.push({y,x,tree});
        }
        map[y][x].pop_front();
      }
    }
  }
}

void dead() {
  while (!q.empty()) {
    int y,x,z;
    std::tie(y,x,z) = q.front();
    q.pop();
    food[y][x] += (z/2);
  }
}

void breed() {
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      for (const int &tree: map[y][x]) {
        if (tree % 5 == 0) {
          for (int d = 0; d < 8; ++d) {
            int ny = y+DIR[d][0];
            int nx = x+DIR[d][1];

            if(false == safe(ny, nx)) continue;
            map[ny][nx].push_front(1);
          }
        }
      }
    }
  }
}

void add() {
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      food[y][x] += base[y][x];
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

 cin >> n >> m >> k;
  
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> base[y][x];
      food[y][x] = 5;
    }
  }

  for (int i = 0; i < m; ++i) {
    int x,y,z; cin >> x >> y >> z;
    map[x][y].push_back(z);
  }

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      if (!map[y][x].empty()) std::sort(map[y][x].begin(), map[y][x].end());
    }
  }

  while (k--) {
    for (int season = 1; season <= 4; ++season) {
      switch (season) {
        case 1:
          eat();
          break;
        case 2:
          dead();
          break;
        case 3:
          breed();
          break;
        case 4:
          add();
          break;
      }
    }
  }
  int res = 0;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      res += map[y][x].size();
    }
  }
  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp