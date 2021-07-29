// https://www.acmicpc.net/problem/21610
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
const int DIR[8][2] = {
  { 0,-1},
  {-1,-1},
  {-1, 0},
  {-1, 1},
  { 0, 1},
  { 1, 1},
  { 1, 0},
  { 1,-1}
};

int n, m;
int map[51][51];
bool visited[51][51];
std::queue<pii> cloud;

bool safe(const int &y, const int &x) {
  return (1 <= y && y <= n) && (1 <= x && x <= n);
}
void move(int d, int s) {
  int qSize = cloud.size();
  while (qSize--) {
    auto curr = cloud.front(); 
    cloud.pop();

    int cy = curr.first;
    int cx = curr.second;

    int ny = cy + DIR[d][0]*s;
    int nx = cx + DIR[d][1]*s;
    ny = (ny < 0) ? n+(ny%n) : (ny%n);
    nx = (nx < 0) ? n+(nx%n) : (nx%n);
    ny = (ny == 0) ? n : ny;
    nx = (nx == 0) ? n : nx;

    visited[ny][nx] = true;
    map[ny][nx]++;
    cloud.push({ny, nx});
  }

  while(!cloud.empty())
  {
    auto curr = cloud.front(); 
    cloud.pop();

    int cy = curr.first;
    int cx = curr.second;

    for (int i = 1; i < 8; i += 2) {
      int ny = cy+DIR[i][0];
      int nx = cx+DIR[i][1];

      if (false == safe(ny, nx)) continue;
      if (map[ny][nx] != 0) map[cy][cx]++;
    }
  }
}

void cloudy() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (false == visited[i][j] && map[i][j] >= 2) {
        cloud.push({i,j});
        map[i][j] -= 2;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) 
      cin >> map[i][j];

  cloud.push({n,1}); cloud.push({n,2});
  cloud.push({n-1,1}); cloud.push({n-1,2});
  while (m--) {
    std::fill(&visited[0][0], &visited[50][51], false);
    int d, s; cin >> d >> s;
    move(d-1, s);
    cloudy();
  }

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum += map[i][j];
    }
  }

  cout << sum << '\n';
}// g++ -o a -std=c++17 *.cpp