// https://www.acmicpc.net/problem/12919 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool find = false;
std::string s, t;

void run(std::string str) {
  if (find || s.length() == str.length()) {
    if (s == str) {
      find = true;
    }
    return;
  }
  if (str[str.length()-1] == 'A') {
    std::string a(str, 0, str.length()-1);
    run(a);
  }
  if (str[0] == 'B') {
    std::string b(str.rbegin(), str.rend()-1);
    run(b);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> s;
  cin >> t;
  run(t);

  cout << find << '\n';
}
// g++ -o a -std=c++17 *.cpp