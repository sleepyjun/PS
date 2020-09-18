#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull PRIME = 1000000007;

ull gcd(ull a, ull b)
{
	int c;
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

ull get_square_mod(ull a, ull n)
{
	ull res = 1;
	while(n)
	{
		if(n&1) res = res * a % PRIME;
		a = a * a % PRIME;
		n >>= 1;
	}
	return res;
}

ull convert(ull a, ull b)
{
	ull res = get_square_mod(b, PRIME-2);
	return a * res % PRIME;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull res = 0;
	int m; cin >> m;
	
	while(m--)
	{
		ull n, s; cin >> n >> s;
		ull g = gcd(n,s);
		n /= g; s /= g;
		
		res = (res + convert(s,n)) % PRIME;
	}
	
	cout << res << endl;
}