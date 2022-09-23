unsigned long long cnt[1000001];
unsigned long long arr[1000001];
unsigned long long sArr[1000001];

void sumInit()
{
	sArr[1] = arr[1];
	for(int i = 2; i <= 1000000; ++i)
	{
		sArr[i] = sArr[i-1] + arr[i];
	}
}
void init()
{
	for(int i = 1; i <= 1000000; ++i)
		for(int j = 1; j <= 1000000/i; ++j)
			arr[i*j] += i;
	sumInit();
}
void count()
{
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = 1; j <= 1000000 / i; j++)
		{
			cnt[i * j]++;
		}
	}
}