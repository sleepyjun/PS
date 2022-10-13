// https://www.acmicpc.net/problem/2891 
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

  int arr[12]; std::fill(arr, arr+12, 1);
  int n, s, r; cin >> n >> s >> r;

  for (int i = 0; i < s; ++i) {
    int x; cin >> x;
    arr[x] -= 1;
  }
  for (int i = 0; i < r; ++i) {
    int x; cin >> x;
    arr[x] += 1;
  }

  for (int i = 1; i <= 10; ++i) {
    if (arr[i] != 2) continue;
    if (arr[i-1] == 0) {
      arr[i-1] = arr[i] = 1;
      continue;
    }
    if (arr[i+1] == 0) {
      arr[i] = arr[i+1] = 1;
      continue;
    }
  }

  int answer = 0;
  for (int i = 1; i <= 10; ++i) {
    if (arr[i] == 0) answer++;
  }

  cout << answer << '\n';
}
// g++ -o a -std=c++17 *.cpp