// https://www.acmicpc.net/problem/19236
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[8][2] = {
  {-1,0},
  {-1,-1},
  {0,-1},
  {1,-1},
  {1,0},
  {1,1},
  {0,1},
  {-1,1}
};

pii map[5][5];
pii fish[20];
bool safe(const int &y, const int &x) {
  return (1 <= y && y <= 4) && (1 <= x && x <= 4);
}
void move(int sy, int sx) {
  for (int i = 1; i <= 16; ++i) {
    int cy = fish[i].first;
    int cx = fish[i].second;
    int &d = map[cy][cx].second;
    if (d == -1) continue;

    for (int j = 0; j <= 8; ++j) {
      int ny = cy + DIR[d][0];
      int nx = cx + DIR[d][1];

      if (safe(ny, nx) == true && !(ny == sy && nx == sx)) {
        std::swap(fish[i], fish[map[ny][nx].first]);
        std::swap(map[cy][cx], map[ny][nx]);
        break;
      }
      d = (d+1 == 8 ? 0 : d+1);
    }
  }
}
int dfs(int y=1, int x=1, pii shark={0,0}) {
  if (safe(y,x) == false) return 0;
  if (map[y][x].second == -1) return 0;

  pii save = map[y][x];
  map[y][x].second = -1;
  
  shark.first += save.first;
  shark.second = save.second;

  move(y,x);
  pii tempMap[5][5];
  pii tempFish[20];
  std::copy(&map[0][0], &map[4][5], &tempMap[0][0]);
  std::copy(&fish[0], &fish[20], &tempFish[0]);

  int max = shark.first;
  int ny = y;
  int nx = x;
  for (int i = 0; i < 4; ++i) {
    ny += DIR[shark.second][0];
    nx += DIR[shark.second][1];
    max = std::max(max, dfs(ny,nx,shark));

    std::copy(&tempMap[0][0], &tempMap[4][5], &map[0][0]);
    std::copy(&tempFish[0], &tempFish[20], &fish[0]);
  }

  map[y][x] = save;
  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for (int y = 1; y <= 4; ++y) {
    for (int x = 1; x <= 4; ++x) {
      int a, b; cin >> a >> b;
      fish[a] = {y,x};
      map[y][x] = {a,b-1};
    }
  }

  cout << dfs() << '\n';
}
// g++ -o a -std=c++17 *.cpp