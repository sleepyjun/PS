// https://www.acmicpc.net/problem/2480 
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

  int a, b, c; cin >> a >> b >> c;
  if (a == b && b == c)
    cout << 10000 + a*1000;
  else if (a == b)
    cout << 1000 + a*100;
  else if (a == c)
    cout << 1000 + a*100;
  else if (b == c)
    cout << 1000 + b*100;
  else
    cout << std::max(std::max(a,b),c)*100;
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp