// https://www.acmicpc.net/problem/17299 
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

int counting[1000001];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  std::stack<int> s;
  std::vector<int> v, answer;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push_back(x);
    counting[x]++;
  }

  for (int i = n-1; i >= 0; --i) {
    int next = v[i];
   
    while (!s.empty() && counting[next] >= counting[s.top()]) {
      s.pop();
    }
   
    if (s.empty()) {
      answer.push_back(-1);
    } else {
      answer.push_back(s.top());
    }
    
    s.push(next);
  }

  for (int i = n-1; i >= 0; --i) {
    cout << answer[i] << ' ';
  }
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp