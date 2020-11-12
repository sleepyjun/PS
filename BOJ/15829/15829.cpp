// https://www.acmicpc.net/problem/15829
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const ull R = 31, M = 1234567891;
ull modPow(ull n)
{
    ull res = 1;
    ull r = R;
    while(n)
    {
        if(n&1) res = res*r%M;
        r=r*r%M;
        n >>= 1;
    }
    return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull l, res = 0; cin >> l;
    std::string str; cin >> str;
    for(int i = 0; i < l; ++i)
    {
        int hashAlpha = str[i] - 'a' + 1;
        res = (res%M + ((hashAlpha%M)*(modPow(i)))%M)%M;
    }
    cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;