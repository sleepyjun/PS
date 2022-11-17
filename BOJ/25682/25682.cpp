// https://www.acmicpc.net/problem/25682 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int whiteArr[2002][2002], blackArr[2002][2002];
// [(0,0), (i,j))
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m, k; cin >> n >> m >> k;
  bool myColor = true;
  for (int i = 0; i < n; ++i) {
    std::string str; cin >> str;
    for (int j = 0; j < m; ++j) {
      bool isBlack = (str[j] == 'B' ? 1 : 0);
      int b = (myColor ^ isBlack);
      int w = !(myColor ^ isBlack);
      blackArr[i+1][j+1] = blackArr[i+1][j] + blackArr[i][j+1] - blackArr[i][j] + b;
      whiteArr[i+1][j+1] = whiteArr[i+1][j] + whiteArr[i][j+1] - whiteArr[i][j] + w;

      myColor = !myColor;
    }
    if (m % 2 == 0) myColor = !myColor;
  }

  int min = 99999999;
  for (int i = 0; i <= n-k; ++i) {
    for (int j = 0; j <= m-k; ++j) {
      int r = i+k;
      int c = j+k;
      int bSize = blackArr[r][c] - blackArr[i][c] - blackArr[r][j] + blackArr[i][j];
      int wSize = whiteArr[r][c] - whiteArr[i][c] - whiteArr[r][j] + whiteArr[i][j];

      min = std::min(min, std::min(bSize, wSize));
    }
  }

  cout << min << '\n';
}
// g++ -o a -std=c++17 *.cpp