#include<cstdio>

const int E = 15;
const int S = 28;
const int M = 19;
int main()
{
	int e,s,m;
	scanf("%d %d %d", &e, &s, &m);
	
	e = (e == E) ? 0 : e;
	s = (s == S) ? 0 : s;
	m = (m == M) ? 0 : m;
	int max = 15*28*19;
	for(int i = 1; i <= max; ++i)
		if((i % E == e) && (i % S == s) && (i % M == m))
			printf("%d\n", i);
}
