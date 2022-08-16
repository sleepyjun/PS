// https://www.acmicpc.net/problem/24416
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int f[50];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  f[0] = f[1] = f[2] = 1;

  for (int i = 3; i <= 41; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  cout << f[n] << ' ' << n-2 << '\n';
}
// g++ -o a -std=c++17 *.cpp