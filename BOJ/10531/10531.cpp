// https://www.acmicpc.net/problem/10531
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <complex>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using cpx = std::complex<double>;

const int INF = std::numeric_limits<int>::max();
const double PI = std::acos(-1);
std::map<int, bool> exist;

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

std::vector<cpx> power(std::vector<cpx>& a){
    int n = 1;
    while(n < a.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    std::vector<cpx> c(n);
 
    cpx w(cos(2*PI/n), sin(2*PI/n));
 
    FFT(a, w);
 
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*a[i];
 
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

  std::vector<cpx> a(200001);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a[x] = cpx(1, 0);
    exist[x] = true;
  }

  std::vector<cpx> result = power(a);
  for (int i = 0; i < result.size(); ++i) {
    int num = std::round(result[i].real());
    if (num > 0) exist[i] = true;
  }

  int m; cin >> m;
  int count = 0;
  
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    if (exist[x]) count++;
  }
  cout << count << '\n';
}
// g++ -o a -std=c++17 *.cpp