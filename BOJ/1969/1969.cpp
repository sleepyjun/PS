#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[1000][51] = { '\0' };
	int N, M;
	int i, j;
	int cnt[4];
	int max = -1;
	char result[51] = { '\0' };
	scanf("%d %d", &N, &M);
	//str = (char**)malloc(N);
	//result = (char*)malloc(M);

	/*for (i = 0; i < N; ++i)
		str[i] = (char*)malloc(M);
		*/

	for (i = 0; i < N; ++i)
		scanf("%s", str[i]);


	for (i = 0; i < M; ++i)
	{
		max = -1;
		for (j = 0; j < 4; ++j)
			cnt[j] = 0;

		for (j = 0; j < N; ++j)
		{
			if (str[j][i] == 'A')
				cnt[0]++;
			else if (str[j][i] == 'C')
				cnt[1]++;
			else if (str[j][i] == 'G')
				cnt[2]++;
			else if (str[j][i] == 'T')
				cnt[3]++;
		}

		for (j = 0; j < 4; ++j)
		{
			if (max < cnt[j])
			{
				max = cnt[j];
				if (j == 0)
					result[i] = 'A';
				else if (j == 1)
					result[i] = 'C';
				else if (j == 2)
					result[i] = 'G';
				else if (j == 3)
					result[i] = 'T';
			}
		}
	}
	result[i] = '\0';

	printf("%s\n", result);
	int count = 0;
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (result[i] != str[j][i])
				count++;
		}
	}
	printf("%d", count);
}