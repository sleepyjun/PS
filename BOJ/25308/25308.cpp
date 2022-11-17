// https://www.acmicpc.net/problem/25308 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int answer = 0;
  std::vector<int> v(8), shuffle(8);
  for(int i = 0; i < 8; ++i) {
    cin >> v[i];
    shuffle[i] = i;
  }

  do {
    int sum = 0;

    for (int i = 0; i < 8; ++i) {
      int a = shuffle[i];
      int b = shuffle[(i+1) % 8];
      int c = shuffle[(i+2) % 8];
      if (double(v[a] * v[c] * std::sqrt(2)) <= double(v[b] * (v[a] + v[c]))) {
        sum++;
      } 
    }

    if (sum == 8) {
      answer++;
    }
  } while (std::next_permutation(shuffle.begin(), shuffle.end()));

  cout << answer << '\n';
}
// g++ -o a -std=c++17 *.cpp