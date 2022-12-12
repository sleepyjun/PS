// https://www.acmicpc.net/problem/1253 
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

  int ans = 0;
  int n; cin >> n;
  std::vector<int> v;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push_back(x);
  }
  std::sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    int dest = v[i];
    int left = 0, right = n-1;
    while (1) {
      if (left == i) left++;
      if (right == i) right--;
      if (left >= right) break;

      if (v[left] + v[right] > v[i]) {
        right--;
      } else if (v[left] + v[right] < v[i]) {
        left++;
      } else {
        ans++;
        break;
      }
    }
  }

  cout << ans << '\n';
}
// g++ -o a -std=c++17 *.cpp