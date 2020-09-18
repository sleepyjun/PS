#include<stdio.h>
#include<string.h>

int main()
{
	int N;
	int sw=0;
	int temp;
	int cnt[100] = { 0 };
	char ox[100][81];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", ox[i]);

	for (int i = 0; i < N; ++i)
	{
		temp = 0;
		for (int j = 0; j < strlen(ox[i]); ++j)
		{
			if (ox[i][j] == 'X')
			{
				sw = 0;
				temp = 0;
			}
			else
				sw = 1;

			if (sw == 1)
			{
				cnt[i] += (++temp);
			}
			
		}
		
	}

	for (int i = 0; i < N; ++i)
		printf("%d\n", cnt[i]);
}