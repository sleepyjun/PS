// https://www.acmicpc.net/problem/10807 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::map<int, int> m;
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    m[x]++;
  }
  int v; cin >> v;
  cout << m[v] << '\n';
}
// g++ -o a -std=c++17 *.cpp