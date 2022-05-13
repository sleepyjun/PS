// https://www.acmicpc.net/problem/1017
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool isPrime[2222], visited[51];
int A[51], B[51];
std::vector<int> odd, even;

void init() {
  std::fill(isPrime, isPrime+2222, true);

  for (int i = 2; i*i <= 2222; ++i) {
    if (true == isPrime[i])
      for (int j = i*i; j <= 2222; j += i)
        isPrime[j] = false;
  }
}

bool dfs(int a, int first) {
  visited[a] = true;
  if (first % 2 == 1) {
    for (int b = 0; b < even.size(); ++b) {
      if (B[b] == 0 || false == isPrime[odd[a] + even[b]]) continue;
      if (B[b] == -1 || (!visited[B[b]] && dfs(B[b], first))) {
        A[a] = b;
        B[b] = a;
        return true;
      }
    }
  }
  else {
    for (int b = 0; b < odd.size(); ++b) {
      if (B[b] == 0 || false == isPrime[even[a] + odd[b]]) continue;
      if (B[b] == -1 || (!visited[B[b]] && dfs(B[b], first))) {
        A[a] = b;
        B[b] = a;
        return true;
      }
    }
  }

  return false;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  init();
  int n; cin >> n;
  int first = -1;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (i == 0) first = x;

    if (x % 2 == 1) odd.push_back(x);
    else even.push_back(x);
  }

  std::vector<int> res;
  if (first % 2 == 1) {
    for (int b = 0; b < even.size(); ++b) {
      if (false == isPrime[first+even[b]]) continue;

      int match = 0;
      std::fill(A, A+51, -1);
      std::fill(B, B+51, -1);
      A[0] = b;
      B[b] = 0;

      for (int a = 1; a < odd.size(); ++a) {
        if (A[a] == -1) {
          std::fill(visited, visited+51, false);
          if (dfs(a, first)) match++;
        }
      }
      if (match == n/2-1) res.push_back(even[b]);
    }
  }
  else {
    for (int b = 0; b < odd.size(); ++b) {
      if (false == isPrime[first+odd[b]]) continue;

      int match = 0;
      std::fill(A, A+51, -1);
      std::fill(B, B+51, -1);
      A[0] = b;
      B[b] = 0;

      for (int a = 1; a < even.size(); ++a) {
        if (A[a] == -1) {
          std::fill(visited, visited+51, false);
          if (dfs(a, first)) match++;
        }
      }
      if (match == n/2-1) res.push_back(odd[b]);
    }
  }

  if (res.empty()) cout << -1;
  else {
    std::sort(res.begin(), res.end());
    for (int x: res) cout << x << ' ';
  }
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp