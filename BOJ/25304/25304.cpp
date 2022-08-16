// https://www.acmicpc.net/problem/25304 
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

  int total; cin >> total;
  int n;
  cin >> n;
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    sum += (a * b);
  }

  if (total == sum) {
    cout << "Yes\n";
  } else{
    cout << "No\n";
  }
}
// g++ -o a -std=c++17 *.cpp