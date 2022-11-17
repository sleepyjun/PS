// https://www.acmicpc.net/problem/5597 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[31];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for (int i = 0; i < 28; ++i) {
    int x; cin >> x;
    visited[x] = true;
  }

  for (int i = 1; i <= 30; ++i) {
    if (visited[i] == false) {
      cout << i << '\n';
    }
  }
}
// g++ -o a -std=c++17 *.cpp