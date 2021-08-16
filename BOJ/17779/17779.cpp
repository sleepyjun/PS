// https://www.acmicpc.net/problem/17779
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
int map[21][21];
int marking[21][21];

void print() {
  cout << "===========================\n";
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= n; ++c) {
      cout << marking[r][c] << ' ';
    }
    cout << '\n';
  }
  cout << "===========================\n";
}

int judge(const int &x, const int &y,
  const int &r, const int &c) {
  if (y == c) return 0;
  return (x-r)/(y-c);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= n; ++c) {
      cin >> map[r][c];
    }
  }

  int ans = INF;
  int sum[5];
  for (int d1 = 1; d1 <= n; ++d1) {
    for (int d2 = 1; d2 <= n; ++d2) {
      for (int x = 1; x <= n; ++x) {
        if (x+d1+d2 > n) continue;
        for (int y = 1; y <= n; ++y) {
          if (1 > y-d1 || y+d2 > n) continue;
          std::fill(&marking[0][0], &marking[20][21], 0);
          std::fill(sum, sum+5, 0);

          for(int i = 0; i <= d1; ++i){
            marking[x+i][y-i] = 5;
            marking[x+d2+i][y+d2-i] = 5;
          }
          for(int i = 0; i <= d2; ++i){
            marking[x+i][y+i] = 5;
            marking[x+d1+i][y-d1+i] = 5;
          }


          for (int r = 1; r < x+d1; ++r) {
            for (int c = 1; c <= y; ++c) {
              if (marking[r][c] == 5) break;
              marking[r][c] = 1;
            }
          }
          
          for (int r = 1; r <= x+d2; ++r) {
            for (int c = n; c > y; --c) {
              if (marking[r][c] == 5) break;
              marking[r][c] = 2;
            }
          }
          
          for (int r = x+d1; r <= n; ++r) {
            for (int c = 1; c < y-d1+d2; ++c) {
              if (marking[r][c] == 5) break;
              marking[r][c] = 3;
            }
          }
          
          for (int r = x+d2+1; r <= n; ++r) {
            for (int c = n; c >= y-d1+d2; --c) {
              if (marking[r][c] == 5) break;
              marking[r][c] = 4;
            }
          }

          for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
              const int &idx = marking[x][y];
              sum[idx%5] += map[x][y];
            }
          }

          std::sort(sum, sum+5);
          ans = std::min(ans, sum[4]-sum[0]);
        }
      }
    }
  }

  cout << ans << '\n';
}
// g++ -o a -std=c++17 *.cpp