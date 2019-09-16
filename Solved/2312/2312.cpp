#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime[100001];
vector<int> primes;

int main()
{
	fill(isPrime, isPrime+100001, true);
	for(int i = 2; i <= 100000; ++i)
	{
		if(isPrime[i] == false) continue;
		
		for(int j = i + i; j <= 100000; j += i)
			isPrime[j] = false;
		primes.push_back(i);
	}

	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		int idx = 0;
		scanf("%d", &n);
		while(n != 1)
		{
			int cnt = 0;
			while(n % primes[idx] == 0)
			{
				n/=primes[idx]; cnt++;
			}
			if(cnt)
				printf("%d %d\n", primes[idx++], cnt);
			else idx++;
		}
	}
	
}