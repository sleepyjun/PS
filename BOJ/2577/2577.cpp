#include<stdio.h>

int main()
{
	int arr[10] = { 0 };
	int x, y, z;
	int temp;

	scanf("%d %d %d", &x, &y, &z);
	
	temp = x*y*z;

	while (temp != 0)
	{
		switch (temp % 10)
		{
		case 0:
			arr[0]++;
			break;

		case 1:
			arr[1]++;
			break;
	
		case 2:
			arr[2]++;
			break;

		case 3:
			arr[3]++;
			break;

		case 4:
			arr[4]++;
			break;

		case 5:
			arr[5]++;
			break;

		case 6:
			arr[6]++;
			break;

		case 7:
			arr[7]++;
			break;

		case 8:
			arr[8]++;
			break;

		default:
			arr[9]++;
			break;
		}
		temp /= 10;
	}
	for (int i = 0; i < 10; ++i)
		printf("%d\n", arr[i]);

	return 0;
}