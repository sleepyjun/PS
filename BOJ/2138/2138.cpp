// https://www.acmicpc.net/problem/2138 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool current[100001], todo[100001], temp[100001];
void toggle(int i) {
  current[i] = !current[i];
  if (i > 0)
    current[i-1] = !current[i-1];
  if (i < 100000)
    current[i+1] = !current[i+1];
}

void run(int i, int& count) {
  int prev = i-1;

  if (current[prev] != todo[prev]) {
    toggle(i);
    count++;
  }
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) scanf("%1d", &temp[i]);
  for (int i = 0; i < n; ++i) scanf("%1d", &todo[i]);

  int count = 0;
  int min = INF;
  bool correct = true;
  // First Switch Toggle
  std::copy(temp, temp + n + 1, current);
  toggle(0); count = 1;
  for (int i = 1; i < n; ++i) {
    run(i, count);
  }
  for (int i = 0; i < n; ++i) {
    if (current[i] != todo[i]) {
      correct = false;
      break;
    }
  }
  if (correct) min = std::min(min, count);
  
  // First Switch Not Toggle
  std::copy(temp, temp + n + 1, current);
  count = 0; correct = true;
  for (int i = 1; i < n; ++i) {
    run(i, count);
  }
  for (int i = 0; i < n; ++i) {
    if (current[i] != todo[i]) {
      correct = false;
      break;
    }
  }
  if (correct) min = std::min(min, count);

  cout << (min==INF ? -1 : min) << '\n';
}
// g++ -o a -std=c++17 *.cpp