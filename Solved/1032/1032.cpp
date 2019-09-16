#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

char str[50][51];
char result[51];
int main()
{
	memset(str, 0, sizeof(str));
	memset(result, 0, sizeof(result));
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", str[i]);
	}

	bool chk;
	int len = strlen(str[0]);

	if (N > 1)
	{
		for (int i = 0; i < len; ++i)
		{
			chk = true;
			for (int j = 1; j < N; ++j)
			{
				if (str[0][i] != str[j][i])
				{
					chk = false;
					break;
				}
			}
			if (chk)
				result[i] = str[0][i];
			else
				result[i] = '?';
		}
	}
	else strcpy(result, str[0]);

	printf("%s", result);
}