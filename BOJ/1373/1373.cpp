// https://www.acmicpc.net/problem/1373
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

  std::string str; cin >> str;
  std::vector<int> res;
  while (!str.empty()) {
    int sum = 0;
    int t = 1;
    for(int i = 0; !str.empty() && i < 3; ++i) {
      if (str.back() == '1') sum += t;
      t *= 2;
      str.pop_back();
    }
    res.push_back(sum);
  }
  for (int i = res.size()-1; i >= 0; --i) 
    cout << res[i];
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp