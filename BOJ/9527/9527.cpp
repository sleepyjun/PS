// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <bitset>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

ull pow(ull base, ull exponent)
{
	ull res = 1;
	while(exponent)
	{
		if(exponent & 1) res *= base;
		base *= base;
		exponent >>= 1;
	}
	return res;
}
ull sum(const ull n)
{
	ull res = 0;
	for(ull i = 1, I=0; i <= n; i <<= 1, ++I)
	{
		for(ull j = (i << 1), J=I+1; j <= n; j <<= 1, ++J)
			if(n & j) res += pow(2,J-I-1)*pow(2,I);
		if(n & i)
		{
			for(ull j = 1, J = 0; j < i; j <<= 1, ++J)
				if(n & j) res += pow(2,J);
			res++;
		}
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull a,b; cin >> a >> b;
	// cout << sum(b) << ' ' << sum(a-1) << '\n';
	cout << sum(b)-sum(a-1) << '\n';

}//g++ -o a -std=c++11 *.cpp