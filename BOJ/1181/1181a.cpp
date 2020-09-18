#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *a, const void *b)
{
	if (strlen((char*)a) > strlen((char*)b))
		return 1;
	else if (strlen((char*)a) < strlen((char*)b))
		return -1;
	else
		return strcmp((char*)a, (char*)b);
}
int main()
{
	int N;
	int i;
	scanf("%d", &N);
	char str[N][51];
	for (i = 0; i < N; ++i)
	{
		scanf("%s", str[i]);
	}
	qsort(str, N, sizeof(str[0]), compare);

	for (i = 0; i < N; ++i)
	{
		if (!strcmp(str[i], str[i + 1]))
			continue;
		printf("%s\n", str[i]);
	}

}