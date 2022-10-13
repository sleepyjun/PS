// https://www.acmicpc.net/problem/2812 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::stack<char> st;
  int n, k; cin >> n >> k;
  std::string str; cin >> str;

  for (const char& ch : str) {
    while (k > 0 && !st.empty() && st.top() < ch) {
      st.pop();
      k--;
    }
    st.push(ch);
  }
  while (k--) {
    st.pop();
  }
  
  std::vector<char> answer;
  while (!st.empty()) {
    answer.push_back(st.top());
    st.pop();
  }

  for (auto rit = answer.rbegin(); rit != answer.rend(); ++rit) {
    cout << *rit;
  }
}
// g++ -o a -std=c++17 *.cpp