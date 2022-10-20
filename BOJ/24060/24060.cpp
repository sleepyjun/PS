// https://www.acmicpc.net/problem/24060 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int save = 0;
int ans = -1;
int n, k;
int temp[500001];

void merge(std::vector<int> &A, int s, int m, int e) {
  int i = s, j = m+1, t = 0;
  
  while (i <= m && j <= e) {
    if (A[i] <= A[j]) {
      temp[t++] = A[i++];
    } else {
      temp[t++] = A[j++];
    }
  }
  while (i <= m) {
    temp[t++] = A[i++];
  }
  while (j <= e) {
    temp[t++] = A[j++];
  }

  i = s, t = 0;
  while (i <= e) {
    A[i++] = temp[t++];
    save++;
    if (save == k) {
      ans = A[i-1];
    }
  }
}

void merge_sort(std::vector<int> &A, int s, int e) {
  if (s < e) {
    int m = (s+e)/2;
    merge_sort(A, s, m);
    merge_sort(A, m+1, e);
    merge(A, s, m, e);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> k;
  std::vector<int> v(n);
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  merge_sort(v, 0, n-1);
  
  cout << ans << '\n';
}
// g++ -o a -std=c++17 *.cpp