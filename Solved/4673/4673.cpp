#include<stdio.h>

int main()
{
	int i,temp,ans;
	int arr[10001];
	arr[0] = 0;
	for (i = 1; i < 10001; ++i)
	{
		arr[i] = 1;
	}

	for (i = 1; i < 10001; ++i)
	{
		ans = i;
		temp = i;
		while ((temp != 0))
		{
			ans += (temp % 10);
			temp /= 10;
		}
		if (ans < 10001)
			arr[ans] = 0;
	}

	for (i = 1; i < 10001; ++i)
		if (arr[i])
			printf("%d\n", i);
}