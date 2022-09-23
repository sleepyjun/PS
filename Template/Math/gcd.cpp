//a bigger than b
long long gcd(long long a, long long b)
{
  if(a < b) std::swap(a,b);
	while(b != 0)
	{
		long long n = a%b;
		a = b;
		b = n;
	}
	return a;
}