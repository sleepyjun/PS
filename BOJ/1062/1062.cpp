// https://www.acmicpc.net/problem/1062
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <set>
#include <map>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::map<char, int> m;
std::vector<int> alpha(21,1);
std::set<char> words[51];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n,k; cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::string str; cin >> str;
    for(char ch: str) {
      if (ch == 'a' || ch == 'c' || ch == 'i' 
          || ch == 'n' || ch == 't') continue;
      words[i].insert(ch);
    }
  }

  if (k < 5) {
    cout << 0 << '\n';
    return 0;
  } else { k -= 5; }

  int idx = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    if (ch == 'a' || ch == 'c' || ch == 'i' 
          || ch == 'n' || ch == 't') continue;
    m[ch] = idx++;
  }

  for (int i = 0; i < k; ++i) alpha[i] = 0;

  int max = -1;
  do {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      bool flag = true;
      for(char ch: words[i]) {
        if (alpha[m[ch]] != 0) {
          flag = false;
          break;
        }
      }
      if (true == flag) cnt++;
    }
    max = std::max(max, cnt);
  } while(std::next_permutation(alpha.begin(), alpha.end()));
  cout << max << '\n';
}
// g++ -o a -std=c++17 *.cpp