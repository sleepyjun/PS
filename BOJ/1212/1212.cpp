// https://www.acmicpc.net/problem/1212
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

  std::string str; cin >> str;
  std::vector<int> v;

  int num = str[0] - '0';
  do {
    v.push_back(num%2);
    num /= 2;
  } while(num);
  for(int i = v.size()-1; i >= 0; --i)
      cout << v[i];
  v.clear();

  for (int i = 1; i < str.size(); ++i) {
    num = str[i]-'0';
    for (int i = 0; i < 3; ++i) {
      v.push_back(num%2);
      num /= 2;
    }

    for(int i = 2; i >= 0; --i)
      cout << v[i];
    v.clear();
  }
}
// g++ -o a -std=c++17 *.cpp