#include<stdio.h>
//이야 이산수학이 이걸?
long long power(long long A, long long B, long long C)
{
	if (B == 0)
	{
		return 1;
	}
	else if(B % 2 == 0)
	{
		return (power(A, B / 2, C)*power(A, B / 2, C)) % C;
	}
	else
	{
		return ((power(A, B / 2, C)*power(A, B / 2, C)) % C *(A%C)) % C;
	}
}
int main()
{
	long long A, B, C;

	scanf("%lld %lld %lld", &A, &B, &C);

	C = power(A, B, C);
	printf("%lld", C);
}