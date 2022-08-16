// https://www.acmicpc.net/problem/2477 
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

  int n; cin >> n;

  int maxWidth = -1, maxHeight = -1;
  int cw[2];
  std::vector<pii> trace;
  for (int i = 0; i < 6; ++i) {
    int curr, length;
    cin >> curr >> length;
    trace.push_back({curr, length});
  }
  trace.push_back(trace.front());

  pii prev = {0, 0}; // dir, len
  for (const auto & curr : trace) {
    if (prev.first == 4 && curr.first == 1 ||
        prev.first == 1 && curr.first == 3 ||
        prev.first == 3 && curr.first == 2 ||
        prev.first == 2 && curr.first == 4) {
      cw[0] = prev.second;
      cw[1] = curr.second;
    }
    else { // counter clock wise
      if (curr.first > 2) //width
        maxWidth = std::max(maxWidth, curr.second);
      else // height
        maxHeight = std::max(maxHeight, curr.second);
    }
    prev = curr;
  }

  int area = maxWidth * maxHeight - (cw[0] * cw[1]);
  cout << area * n << '\n';
}
// g++ -o a -std=c++17 *.cpp