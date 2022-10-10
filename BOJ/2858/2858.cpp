// https://www.acmicpc.net/problem/2858 
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

  int r, b; cin >> r >> b;
  int size = r + b;
  int len = r + 4;
  
  for (int l = 1;; ++l) {
    for (int w = 1; w <= l; ++w) {
      if (l*w == size && (l+w)*2 == len) {
        cout << l << ' ' << w << '\n';
        return 0;
      }
    }
  }
}
// g++ -o a -std=c++17 *.cpp