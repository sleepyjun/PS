// https://www.acmicpc.net/problem/1358
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

int w, h, x, y;

int length(int ax, int ay, int bx, int by) {
  return ((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by));
}
int calc(int cx, int cy) {
  if ((x <= cx && cx <= x + w) && (y <= cy && cy <= y + h)) {
    return 1;
  } else {
    int radius = h / 2;
    int leftSideLength = length(cx, cy, x, y + radius);
    int rightSideLength = length(cx, cy, x + w, y + radius);

    if ((leftSideLength <= (radius * radius)) ||
        (rightSideLength <= (radius * radius))) {
      return 1;
    }
  }

  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int p;
  cin >> w >> h >> x >> y >> p;

  int count = 0;
  for (int i = 0; i < p; ++i) {
    int x, y;
    cin >> x >> y;
    count += calc(x, y);
  }

  cout << count << '\n';
}
// g++ -o a -std=c++17 *.cpp