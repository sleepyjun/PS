// https://www.acmicpc.net/problem/2331
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

  int a, p; cin >> a >> p;
  std::map<int, int> arr;
  while (arr[a] != 3) {
    arr[a]++;
    int temp = 0;
    while (a > 0) {
      int x = 1;
      for (int i = 1; i <= p; ++i)
        x *= a%10;
      temp += x;
      a/=10;
    }
    a = temp;
  }

  int cnt = 0;
  for (const auto &kv: arr)
    if (kv.second == 1) cnt++;
  cout << cnt << '\n';
}
// g++ -o a -std=c++17 *.cpp