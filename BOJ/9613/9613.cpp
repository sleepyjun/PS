// https://www.acmicpc.net/problem/9613
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

// ensure a is bigger than b
long long gcd(long long a, long long b)
{
  if(a < b) std::swap(a,b);
  while (b != 0) {
    long long temp = a%b;
    a = b;
    b = temp;
  }

  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      v.push_back(x);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        sum += gcd(v[i], v[j]);
      }
    }

    cout << sum << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp