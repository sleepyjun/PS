#include<stdio.h>
#include<stdlib.h>

int * changeArr(int num)
{
	int * nums = (int*)malloc(sizeof(int) * 3);
	nums[0] = num / 100;
	num %= 100;
	nums[1] = num / 10;
	num %= 10;
	nums[2] = num / 1;
	return nums;
}

int isnum(int *temp, int num, int S, int B)
{
	int i, j;
	int *nums = changeArr(num);
	int s=0, b=0;

	for(i=0;i<3;++i)
		for (j = 0; j < 3; ++j)
		{
			if (nums[i] == temp[j])
			{
				if (i == j)
					s++;
				else
					b++;
			}
		}
	if (S == s && B == b)
		return 1;
	return 0;
}
int main()
{
	int T, N, S, B;
	int cnt = 0;
	int arr[889],*temp;
	int i,j;

	for (i = 111; i <= 999; ++i)
		arr[i - 111] = i;

	scanf("%d", &T);
	//arr[i]%10 1의자리
	//(arr[i]/10)%10 10의자리
	//arr[i]/100 100의자리

	for (i = 0; i < 889; ++i)//안되는것 미리 제외
	{
		if ((arr[i] % 10 == arr[i] / 100) || (arr[i] % 10 == (arr[i] / 10) % 10) || (arr[i] / 100 == (arr[i] / 10) % 10))
			arr[i] = 0;
		if (!(arr[i] % 10) || !((arr[i] / 10) % 10))
			arr[i] = 0;
	}

	for (i = 0; i < T; ++i)
	{
		scanf("%d %d %d", &N, &S, &B);
		temp = changeArr(N);
		for (j = 0; j < 889; ++j)
		{
			if (arr[j])
				if (!isnum(temp, arr[j], S, B))
					arr[j] = 0;
		}
	}

	for (i = 0; i < 889; ++i)
		if (arr[i])
			++cnt;

	printf("%d", cnt);
}