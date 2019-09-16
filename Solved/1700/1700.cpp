#include<stdio.h>
#include<stdlib.h>

int tab[110];
int tab2[110];
int elec[110];

int main()
{
	int N, K;
	int i,j;
	int sw;
	int ans = 0;
	int x;

	scanf("%d %d", &N, &K);
	for (i = 0; i < K; ++i) scanf("%d", &elec[i]);
	for(i=0;i<K;++i)
	{
		for (j = 0; j < N; ++j) tab[j] = 1;
		x = elec[i];
		sw = 0;
		for(j=0;j<N;++j)
			if(tab)