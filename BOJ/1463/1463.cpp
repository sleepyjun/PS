#include<stdio.h>
#include<stdlib.h>

int d[1000000];

int go(int n) {
	if (n == 1) return 0;
	if (d[n]>0) return d[n];
	d[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}

int main()
{
	int x;
	scanf("%d", &x);
	d[2] = 1; d[3] = 1;
	for (int i = 4; i <= x; ++i)
		go(i);
	printf("%d\n", d[x]);
}