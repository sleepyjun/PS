#include<stdio.h>

int main()
{
	int N;
	int temp,sw = 1;
	int rs = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		if (temp != 1)
		{
			for (int j = 2; j < temp; ++j)
			{
				if (temp%j == 0)
				{
					sw = 0; break;
				}
			}

			if (sw)
				++rs;
			else
				sw = 1;
		}
	}
	printf("%d", rs);

}