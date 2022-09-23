long long pow(long long base, long long exp)
{
	long long result = 1;
	while(exp)
	{
		if(exp&1) result *= base;
		base *= base;
		exp >>= 1;
	}
	return result;
}

long long powWithMod(long long base, long long exp, long long mod)
{
	long long result = 1;
	while(exp)
	{
		if(exp&1) result = (result*base) % mod;
		base = (base*base) % mod;
		exp >>= 1;
	}
	return result;
}