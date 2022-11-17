// https://www.acmicpc.net/problem/2566 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int max = -1;
  int y, x;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      int n; cin >> n;
      if (max < n) {
        max = n;
        y = i;
        x = j;
      }
    }
  }

  cout << max << '\n';
  cout << y << ' ' << x << '\n';
}
// g++ -o a -std=c++17 *.cpp