// https://www.acmicpc.net/problem/15828
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  std::queue<int> q;

  while (1) {
    int x;
    cin >> x;
    if (x == -1)
      break;
    else if (x == 0)
      q.pop();
    else if (q.size() == n)
      continue;
    else
      q.push(x);
  }

  if (q.empty()) {
    cout << "empty\n";
  } else {
    for (int i = 0; i < n; ++i) {
      if (q.empty()) break;

      cout << q.front() << ' ';
      q.pop();
    }
  }
}
// g++ -o a -std=c++17 *.cpp