// https://www.acmicpc.net/problem/1789
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

  ull s; cin >> s;
  if (s == 1) {
    cout << 1 << '\n';
    return 0;
  }
  ull cnt = 0;
  ull sum = 0;

  for (ull i = 1; i <= s; ++i) {
    sum += i;
    cnt++;
    if (sum > s) break;
  }

  cout << cnt-1 << '\n';
}
// g++ -o a -std=c++17 *.cpp