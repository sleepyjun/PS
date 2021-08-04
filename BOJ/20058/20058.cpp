// https://www.acmicpc.net/problem/20058
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[4][2] = {
  {0,1},
  {1,0},
  {-1,0},
  {0,-1}
};
int n, sum;
int map[70][70];
bool visited[70][70];

void print() {
  cout << "=====================\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}
void divide(int n, const int l, int y=1, int x=1) {
  if(n < l) return;
  else if(n > l) {
    n/=2;
    divide(n, l, y, x);
    divide(n, l, y+n, x);
    divide(n, l, y, x+n);
    divide(n, l, y+n, x+n);
    return;
  } else {
    std::vector<int> temp[l];
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < l; ++j) {
        temp[i].push_back(map[y+j][x+i]);
      }
    }

    for (int i = 0; i < l; ++i) {
      std::reverse(temp[i].begin(), temp[i].end());
    }

    for(int i = 0; i < l; ++i) {
      for(int j = 0; j < l; ++j) {
        int cy = y+i;
        int cx = x+j;
        map[cy][cx] = temp[i][j];
      }
    }
  }
}

int run(int y, int x) {
  int cnt = 1;
  std::queue<pii> q;
  q.push({y,x}); visited[y][x] = true;

  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    int cy = curr.first;
    int cx = curr.second;

    for (int d = 0; d < 4; ++d) {
      int ny = cy+DIR[d][0];
      int nx = cx+DIR[d][1];

      if (visited[ny][nx]) continue;
      if (map[ny][nx] != 0) {
        q.push({ny, nx});
        visited[ny][nx] = true;
        cnt++;
      }
    }
  }

  return cnt;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int q; cin >> n >> q;
  n = pow(2, n);
  
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }

  while (q--) {
    sum = 0;
    int l; cin >> l;
    l = pow(2, l);
    divide(n, l);
    
    std::queue<pii> q;
    for (int y = 1; y <= n; ++y) {
      for (int x = 1; x <= n; ++x) {
        int cnt = 0;
        const int &ice = map[y][x];

        if (ice == 0) continue;
        for (int d = 0; d < 4; ++d) {
          int ny = y+DIR[d][0];
          int nx = x+DIR[d][1];

          if(map[ny][nx] != 0) cnt++;
        }

        if (cnt < 3) q.push({y,x});
        else sum += ice;
      }
    }

    while (!q.empty()) {
      auto curr = q.front(); q.pop();

      int cy = curr.first;
      int cx = curr.second;

      map[cy][cx]--;
      sum += map[cy][cx];
    }
  }

  int block = 0;

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      if(!visited[y][x] && map[y][x] != 0) {
        block = std::max(block, run(y,x));
      }
    }
  }
  cout << sum << '\n';
  cout << block << '\n';
}
// g++ -o a -std=c++17 *.cpp