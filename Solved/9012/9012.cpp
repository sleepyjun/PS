#include<stdio.h>
#include<string.h>

int main()
{
	char str[51];
	int cnt = 0;
	int T;

	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; ++i)
	{
		scanf("%s", str);
		getchar();
		for (int j = 0; j < strlen(str); ++j)
		{
			if (cnt>=0 && str[j] == '(')
				cnt++;
			else
				cnt--;
		}
		if (cnt == 0)
			puts("YES");
		else
			puts("NO");
		cnt = 0;
	}
}