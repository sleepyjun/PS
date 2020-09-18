#include<stdio.h>
int arr[999][2];
void main()
{
	int i,j,k;
	int test;

	
	

	scanf("%d", &test);
	
	for (i = 0; i < test; ++i)
	{
		arr[0][0] = 1;
		arr[1][1] = 1;
		scanf("%d", &j);
		
			for (k = 2; k <= j; ++k)
			{
				arr[k][0] = arr[k - 2][0] + arr[k - 1][0];
				arr[k][1] = arr[k - 2][1] + arr[k - 1][1];
			}
		
			printf("%d %d\n", arr[j][0], arr[j][1]);
	}
	
}