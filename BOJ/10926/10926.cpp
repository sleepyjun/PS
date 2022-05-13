// https://www.acmicpc.net/problem/10926 
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

  std::string str; cin >> str;
  str += "??!";
  cout << str << '\n';
}
// g++ -o a -std=c++17 *.cpp