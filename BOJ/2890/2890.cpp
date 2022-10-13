// https://www.acmicpc.net/problem/2890 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<std::string> map;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::vector<pii> prize;
  int answer[10];

  int r, c; cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    std::string line; cin >> line;
    map.push_back(line);
  }

  for (const auto& line: map) {
    int length = line.length();
    int count = 0;
    for (int i = length-2; i >= 0; --i) {
      if ('1' <= line[i] && line[i] <= '9') {
        prize.push_back({count, line[i]-'0'});
        break;
      }
      count++;
    }
  }

  std::sort(prize.begin(), prize.end());
  int min = prize[0].first, grade = 1;
  for (int i = 0; i < prize.size(); ++i) {
    if (min == prize[i].first) {
      answer[prize[i].second] = grade;
    }
    else {
      min = prize[i].first;
      grade++;
      answer[prize[i].second] = grade;
    }
  }

  for (int i = 1; i < 10; ++i) {
    cout << answer[i] << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp