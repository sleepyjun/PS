// https://www.acmicpc.net/problem/1292
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

  std::vector<int> v(1001);
  int idx = 0;
  for (int i = 1;;++i) {
    for (int j = 0; j < i; ++j) {
      v[idx++] = i;
      if (idx == 1000) break;
    }
    if (idx == 1000) break;
  }

  int a, b; cin >> a >> b;
  a--; b--;

  ull sum = 0;
  for (int i = a; i <= b; ++i) {
    sum += v[i];
  }

  cout << sum << '\n';
}
// g++ -o a -std=c++17 *.cpp