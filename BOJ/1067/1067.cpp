// https://www.acmicpc.net/problem/1067 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <complex>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using cpx = std::complex<double>;

const int INF = std::numeric_limits<int>::max();
const double PI = std::acos(-1);

void FFT(std::vector<cpx> &v, cpx w) {
  int n = v.size();
  if (n == 1) return;

  std::vector<cpx> even(n/2), odd(n/2);
  for (int i = 0; i < n; ++i) {
    if (i%2) odd[i/2] = v[i];
    else even[i/2] = v[i];
  }

  FFT(even, w*w);
  FFT(odd, w*w);

  cpx wp(1, 0);
  for (int i = 0; i < n/2; ++i) {
    v[i] = even[i] + wp*odd[i];
    v[i + n/2] = even[i] - wp*odd[i];
    wp *= w;
  }
}

std::vector<cpx> multiply(std::vector<cpx>& a, std::vector<cpx>& b){
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    std::vector<cpx> c(n);
 
    cpx w(cos(2*PI/n), sin(2*PI/n));
 
    FFT(a, w);
    FFT(b, w);
 
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
 
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  std::vector<cpx> a, b;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a.push_back(cpx(x, 0));
  }
  a.insert(a.end(), a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    b.push_back(cpx(x, 0));
  }
  std::reverse(b.begin(), b.end());

  int max = -1;
  std::vector<cpx> result = multiply(a, b);
  for (int i = n-1; i < 2*n-1; ++i) {
    max = std::max(max, (int)round(result[i].real()));
  }
  cout << max << '\n';
}
// g++ -o a -std=c++17 *.cpp