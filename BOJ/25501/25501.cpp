// https://www.acmicpc.net/problem/25501 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int visit;

int recursion(const std::string &s, int l, int r) {
  visit++;
  if (l >= r) return 1;
  else if (s[l] != s[r]) return 0;
  else return recursion(s, l+1, r-1);
}

int isPalindrome(const std::string &s){
  return recursion(s, 0, s.length()-1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;

  while (t--) {
    visit = 0;
    std::string str; cin >> str;
    cout << isPalindrome(str) << ' ' << visit << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp