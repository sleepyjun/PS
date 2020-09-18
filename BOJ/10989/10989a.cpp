#include <stdio.h>

int n, d[10001], a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a), d[a]++;
	for (int i = 0; i < 10001; i++)
		for (int j = 0; j<d[i]; j++)
			printf("%d\n", i);
	return 0;
}