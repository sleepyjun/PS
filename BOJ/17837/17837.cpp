// https://www.acmicpc.net/problem/17837
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
  {0, 1},
  {0, -1},
  {-1, 0},
  {1, 0},
};

int map[14][14];
iii pieceInfo[11];
std::vector<int> pieceMap[14][14];


bool move(int n, int k) {
  for (int i = 1; i <= k; ++i) {
    int cy, cx, cd;
    std::tie(cy, cx, cd) = pieceInfo[i];

    int ty = cy + DIR[cd][0];
    int tx = cx + DIR[cd][1];

    if (map[ty][tx] == 0) {
      int j = 0;
      for (; j < pieceMap[cy][cx].size(); ++j) {
        if (pieceMap[cy][cx][j] == i) break;
      }

      int tj = j;
      
      int ny, nx, myd;
      for (; j < pieceMap[cy][cx].size(); ++j) {
        int idx = pieceMap[cy][cx][j];
        std::tie(ny, nx, myd) = pieceInfo[idx];
        ny += DIR[cd][0];
        nx += DIR[cd][1];

        pieceMap[ny][nx].push_back(idx);
        pieceInfo[idx] = {ny, nx, myd};
      }
      pieceMap[cy][cx].erase(pieceMap[cy][cx].begin()+tj, pieceMap[cy][cx].end());

      if (pieceMap[ny][nx].size() >= 4) return true;
    }
    else if (map[ty][tx] == 1) {
      int j = 0;
      for (; j < pieceMap[cy][cx].size(); ++j) {
        if (pieceMap[cy][cx][j] == i) break;
      }
      
      int tj = j;
      j = pieceMap[cy][cx].size()-1;

      int ny, nx, myd;
      for (; j >= tj; --j) {
        int idx = pieceMap[cy][cx][j];
        std::tie(ny, nx, myd) = pieceInfo[idx];
        ny += DIR[cd][0];
        nx += DIR[cd][1];

        pieceMap[ny][nx].push_back(idx);
        pieceInfo[idx] = {ny, nx, myd};
      }
      pieceMap[cy][cx].erase(pieceMap[cy][cx].begin()+tj, pieceMap[cy][cx].end());
      if (pieceMap[ny][nx].size() >= 4) return true;
    } 
    else {
      switch (cd) {
        case 0: cd = 1; break;
        case 1: cd = 0; break;
        case 2: cd = 3; break;
        case 3: cd = 2; break;
      }
      pieceInfo[i] = {cy, cx, cd};

      ty = cy + DIR[cd][0];
      tx = cx + DIR[cd][1];

      if (map[ty][tx] == 0) {
        int j = 0;
        for (; j < pieceMap[cy][cx].size(); ++j) {
          if (pieceMap[cy][cx][j] == i) break;
        }

        int tj = j;

        int ny, nx, myd;
        for (; j < pieceMap[cy][cx].size(); ++j) {
          int idx = pieceMap[cy][cx][j];
          std::tie(ny, nx, myd) = pieceInfo[idx];
          ny += DIR[cd][0];
          nx += DIR[cd][1];

          pieceMap[ny][nx].push_back(idx);
          pieceInfo[idx] = {ny, nx, myd};
        }
        pieceMap[cy][cx].erase(pieceMap[cy][cx].begin() + tj, pieceMap[cy][cx].end());
        if (pieceMap[ny][nx].size() >= 4) return true;
        
      } else if (map[ty][tx] == 1) {
        int j = 0;
        for (; j < pieceMap[cy][cx].size(); ++j) {
          if (pieceMap[cy][cx][j] == i) break;
        }

        int tj = j;
        j = pieceMap[cy][cx].size() - 1;

        int ny, nx, myd;
        for (; j >= tj; --j) {
          int idx = pieceMap[cy][cx][j];
          std::tie(ny, nx, myd) = pieceInfo[idx];
          ny += DIR[cd][0];
          nx += DIR[cd][1];

          pieceMap[ny][nx].push_back(idx);
          pieceInfo[idx] = {ny, nx, myd};
        }
        pieceMap[cy][cx].erase(pieceMap[cy][cx].begin() + tj, pieceMap[cy][cx].end());
        if (pieceMap[ny][nx].size() >= 4) return true;
      }
    }
  }
  return false;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  std::fill(&map[0][0], &map[13][14], 2);

  int n,k; 
  cin >> n >> k;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }
  for (int i = 1; i <= k; ++i) {
    int y, x, d; cin >> y >> x >> d;
    d--;
    pieceInfo[i] = {y,x,d};
    pieceMap[y][x].push_back(i);
  }

  for (int i = 1; i <= 1000; ++i) {
    if (move(n, k) == true) {
      cout << i << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}
// g++ -o a -std=c++17 *.cpp