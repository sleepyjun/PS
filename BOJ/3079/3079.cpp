// https://www.acmicpc.net/problem/3079
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const long long INF = std::numeric_limits<long long>::max();

long long N, M;
long long arr[100001];

bool possible(const long long& time) {
  long long people = 0;
  for (int i = 0; i < N; ++i) {
    people += (time / arr[i]);
    if (people >= M) return true;
  }

  return people >= M;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  long long low = 0, high = 1e18+1;
  while (low <= high) {
    long long mid = (high + low) / (long long)2;
    if (possible(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << low << '\n';
}
// g++ -o a -std=c++17 *.cpp