// https://www.acmicpc.net/problem/2559 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int _INF = std::numeric_limits<int>::min();

const int MAX = 100000;
int arr[2*MAX];
struct SegTree {
  int size;
  SegTree (int n) : size(n) {}

  void init() {
    for(int i = size-1; i > 0; --i)
      arr[i] = arr[i*2] + arr[i*2+1];
  }
  int query(int l, int r) {// [l, r)
    int res = 0;
    l += size; r += size;
    while (l < r) {
      if (l % 2) res += arr[l++];
      if (r % 2) res += arr[--r];
      l /= 2; r /= 2;
    }

    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, k; cin >> n >> k;
  SegTree s(n);

  for (int i = 0; i < n; ++i)
    cin >> arr[i+n];
  s.init();
  int max = _INF; 
  for (int i = 0; i <= n-k; ++i) {
    max = std::max(max, s.query(i, i+k));
  }
  cout << max << '\n';
}
// g++ -o a -std=c++17 *.cpp