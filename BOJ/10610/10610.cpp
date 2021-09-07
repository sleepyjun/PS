// https://www.acmicpc.net/problem/10610
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

  int check = 0;
  std::vector<int> v;
  std::string num; cin >> num;
  for (const char &x: num) {
    int n = x-'0';
    v.push_back(n);
    check += n;
  }
  std::sort(v.begin(), v.end(), std::greater<int>());
  if (v.back() == 0 && check % 3 == 0) {
    for (const int &n: v) cout << n;
  } else cout << -1;
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp