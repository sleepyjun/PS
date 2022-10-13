// https://www.acmicpc.net/problem/3663 
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

  int t; cin >> t;
  while (t--) {
    std::string str; cin >> str;
    int length = str.length();
    int answer = 0, move = length - 1;

    for (const char& ch: str) {
      answer += std::min(ch-'A', 'Z'-ch+1);
    }

    for (int i = 0; i < length; ++i) {
      int nextIdx = i+1;
      while (nextIdx < length && str[nextIdx] == 'A') nextIdx++;
      int distance = std::min(i, length-nextIdx);
      move = std::min(move, i + length-nextIdx + distance);
    }
    cout << answer+move << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp