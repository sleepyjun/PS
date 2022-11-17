// https://www.acmicpc.net/problem/2587 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <numeric>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int arr[5];
  for (int i = 0; i < 5; ++i) {
    cin >> arr[i];
  }
  std::sort(arr, arr+5);
  cout << std::accumulate(arr, arr+5, 0) / 5 << '\n';
  cout << arr[2] << '\n';
}
// g++ -o a -std=c++17 *.cpp