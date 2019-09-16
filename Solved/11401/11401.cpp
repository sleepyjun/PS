#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
const ull M = 1000000007;

ull fac[4000001];

ull fastPower(ull a, ull n)
{
	ull res = 1;
	while(n)
	{
		if(n&1) res = (res*a)%M;
		a = (a*a)%M;
		n >>= 1;
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n, k; std::cin >> n >> k;
	k = ((n-k) < k) ? (n-k) : k;
	
	fac[1] = 1;
	for(int i = 2; i <= 4000000; ++i)
		fac[i] = (fac[i-1]*i)%M;
	
	if(n==k || k==0) std::cout << 1 << '\n';
	else
	{
		// std::cout << fac[n] << std::endl;
		// std::cout << fac[k] << std::endl;
		// std::cout << fac[n-k] << std::endl;
		ull r = (fac[n] * fastPower(fac[n-k], M-2))%M;
		r = (r*fastPower(fac[k], M-2))%M;
		std::cout << r << '\n';
	}
}