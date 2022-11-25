// https://www.acmicpc.net/problem/2023 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
const int N[] = {1,2,3,5,7,9};
std::vector<int> primes;

bool isPrime(int prime) {
  if (prime == 1) return false;

  for (int i = 2; i * i <= prime; ++i) {
    if (prime % i == 0) return false;
  }
  return true;
}
void dfs(int depth = 0, int prime = 0) {
  if (depth == n) {
    primes.push_back(prime);
    return;
  }

  for (const int& num: N) {
    int next = prime*10 + num;
    if (false == isPrime(next)) continue;
    dfs(depth+1, next);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n;

  dfs();
  std::sort(primes.begin(), primes.end());
  for (const int& prime: primes) {
    cout << prime << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp