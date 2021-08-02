// https://www.acmicpc.net/problem/20057
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[4][2] = {
  { 0,-1},
  { 1, 0},
  { 0, 1},
  {-1, 0}
};
const int RATIO[4][5][5] = {
  {
    { 0, 0, 2, 0, 0},
    { 0,10, 7, 1, 0},
    { 5, 0, 0, 0, 0},
    { 0,10, 7, 1, 0},
    { 0, 0, 2, 0, 0}
  },
  {
    { 0, 0, 0, 0, 0},
    { 0, 1, 0, 1, 0},
    { 2, 7, 0, 7, 2},
    { 0,10, 0,10, 0},
    { 0, 0, 5, 0, 0}
  },
  {
    { 0, 0, 2, 0, 0},
    { 0, 1, 7,10, 0},
    { 0, 0, 0, 0, 5},
    { 0, 1, 7,10, 0},
    { 0, 0, 2, 0, 0}
  },
  {
    { 0, 0, 5, 0, 0},
    { 0,10, 0,10, 0},
    { 2, 7, 0, 7, 2},
    { 0, 1, 0, 1, 0},
    { 0, 0, 0, 0, 0}
  }
};
int n, res;
int map[510][510];

bool safe(const int &y, const int &x) {
  return ((1 <= y) and (y <= n)) and ((1 <= x) and (x <= n));
}
// after moving
void wind(int cy, int cx, int d) {
  int idx = 0;
  int &rSand = map[cy][cx];
  int tSand = map[cy][cx];

  const int M = 2;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      const int &r = RATIO[d][i][j];
      if(r == 0) continue;
      int dy = i-M;
      int dx = j-M;

      int ny = cy+dy;
      int nx = cx+dx;

      if(false == safe(ny, nx)) res += (tSand*r)/100;
      else map[ny][nx] += (tSand*r)/100;

      rSand -= (tSand*r)/100;
    }
  }

  int ny = cy+DIR[d][0];
  int nx = cx+DIR[d][1];

  if(false == safe(ny, nx)) res += rSand;
  else map[ny][nx] += rSand;
  rSand = 0;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }
 
  int my = (n+1)/2;
  int mx = (n+1)/2;

  int idx = 1;
  int d = 0;
  int cnt = 0;
  for (int i = 0; i < n*2; ++i) {
    if (i%2 == 0) cnt++;

    for (int j = 0; j < cnt; ++j) {
      my += DIR[d][0];
      mx += DIR[d][1];
      wind(my, mx, d);
    }

    d = (d+1)%4;
  }

  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp