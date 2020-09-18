#include<stdio.h>
#include<string.h>

int main()
{
	int i,j;
	int arr[26] = { 0 };
	char ch[101] = { '\0' };

	scanf("%s", &ch);

	for (i = 97; i <= 122; ++i)
	{
		for (j = 0; j < strlen(ch); ++j)
		{
			if (i == ch[j])
			{
				arr[i - 97] = j;
				break;
			}
			else
			{
				arr[i - 97] = -1;
			}
		}
	}

	for(i=0;i<26;++i)
		printf("%d ", arr[i]);
}