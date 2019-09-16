#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare1(const void * a, const void *b)
{
	return strcmp((char *)a, (char*)b);
}

int main()
{
	char ch[20000][51] = { '\0', };
	char temp[51];
	int N;
	int i,j;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; ++i)
		scanf("%s", ch[i]);
	
	qsort(ch, N, sizeof(ch[0]), compare1);//알파벳순 정렬

	for (i = 0; i < N-1; ++i)
	{
		for(j=0;j<N-i;++j)
			if (strlen(ch[j]) > strlen(ch[j + 1]))
			{
				strcpy(temp, ch[j]);
				strcpy(ch[j], ch[j + 1]);
				strcpy(ch[j + 1], temp);
			}
	}
	
	for (i = 0; i < N; ++i)
		printf("%s\n", ch[i]);
}