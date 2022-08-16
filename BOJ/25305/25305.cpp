// https://www.acmicpc.net/problem/25305 
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

  int n,k; cin >> n >> k;
  std::vector<int> v;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push_back(x);
  }
  std::sort(v.begin(), v.end(), std::greater<int>());
  cout << v[k-1] << '\n';
}
// g++ -o a -std=c++17 *.cpp