// https://www.acmicpc.net/problem/7469 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 100000;
std::vector<int> arr[2 * MAX];

struct MergesortTree {
  int size;
  MergesortTree(int n) : size(n) {}
  void init() {
    for (int i = size-1; i > 0; --i) {
      std::vector<int> &curr = arr[i];
      std::vector<int> &left = arr[i*2];
      std::vector<int> &right = arr[i*2+1];
      curr.resize(left.size() + right.size());

      for (int j = 0, l = 0, r = 0; j < curr.size(); ++j) {
        if (r == right.size() || (l < left.size() && left[l] < right[r])) {
          curr[j] = left[l++];
        } else {
          curr[j] = right[r++];
        }
      }
    }
  }
  int query(int l, int r, int k) { //[l,r) 
    long long res = 0;
    l += size;
    r += size;
    while (l < r) {
      if (l % 2) {
        res += std::lower_bound(arr[l].begin(), arr[l].end(), k) - arr[l].begin();
        ++l;
      }
      if (r % 2) {
        --r;
        res += std::lower_bound(arr[r].begin(), arr[r].end(), k) - arr[r].begin();
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, t; cin >> n >> t;
  MergesortTree m(n);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr[i+n].push_back(x);
  }
  m.init();
  
  while (t--) {
    int l, r, k; cin >> l >> r >> k;

    int low = -1e9, high = 1e9+1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int ret = m.query(l-1, r, mid);
      if (ret < k) {
        low = mid+1;
      } else {
        high = mid-1;
      }
    }
    cout << high << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp