// https://www.acmicpc.net/problem/11478 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::unordered_set<std::string> s;
  std::string str; cin >> str;

  for (int i = 0; i < str.length(); ++i) {
    for (int j = 0; j < str.length()-i; ++j) {
      s.insert(str.substr(i, j+1));
    }
  }

  cout << s.size() << '\n';
}
// g++ -o a -std=c++17 *.cpp