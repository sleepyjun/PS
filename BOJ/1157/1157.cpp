#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int count[26];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  std::string str; cin >> str;
  std::vector<pii> v;

  for (char &c: str) {
    int index = ('a' <= c && c <= 'z') ? c-'a' : c-'A';
    count[index]++;
  }
  for (int i = 0; i < 26; ++i) {
    v.push_back({count[i], i});
  }
  
  std::sort(v.begin(), v.end(), std::greater<pii>());

  if (v[0].first == v[1].first) {
    cout << '?' << '\n';
  }
  else {
    char ch = 'A' + v[0].second;
    cout << ch << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp