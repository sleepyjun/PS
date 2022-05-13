// https://www.acmicpc.net/problem/2108
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool comp(const pii &a, const pii &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n; cin >> n;
  std::vector<int> v;

  int sum = 0;
  int avg, mid, mode, range;
  std::map<int, int> m;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push_back(x);
    m[x]++;
    sum += x;
  }
  std::sort(v.begin(), v.end());
  avg = std::round((double)sum / n);
  mid = v[n/2];
  range = v[n-1] - v[0];

  std::vector<pii> modeVector(m.begin(), m.end());
  std::sort(modeVector.begin(), modeVector.end(), comp);
  if (modeVector[0].second == modeVector[1].second)
    mode = modeVector[1].first;
  else mode = modeVector[0].first;
  
  cout << avg << '\n';
  cout << mid << '\n';
  cout << mode << '\n';
  cout << range << '\n';
}
// g++ -o a -std=c++17 *.cpp