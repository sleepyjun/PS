// https://www.acmicpc.net/problem/3034 
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

  int n, w, h; cin >> n >> w >> h;
  int diagonal = w*w + h*h;
  
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x * x <= diagonal) {
      cout << "DA\n";
    }
    else cout << "NE\n";
  }
}
// g++ -o a -std=c++17 *.cpp