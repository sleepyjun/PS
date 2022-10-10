// https://www.acmicpc.net/problem/3671 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool isPrime[10000000];
bool primes[10000000];

void init() {
  std::fill(isPrime+2, isPrime+10000000, true);

  for (int i = 2; i * i <= 10000000; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 10000000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  init();
  int t; cin >> t;
  while (t--) {
    int count = 0;
    std::vector<int> v;
    std::string s; cin >> s;
    std::copy(isPrime, isPrime+10000000, primes);

    for (const char& ch: s) {
      v.push_back(ch-'0');
    }
    std::sort(v.begin(), v.end());

    do {
      int num = 0;
      for (const int& n: v) {
        num *= 10;
        num += n;
        if (primes[num]) {
          primes[num] = false;
          count++;
        }
      }
    } while(std::next_permutation(v.begin(), v.end()));
    cout << count << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp