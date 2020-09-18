#include<stdio.h>
#include<string.h>
int main()
{
	char arr[9] = { '\0' };
	int i = 0;
	int temp;

	while (i < 8)
	{
		temp = getchar();
		if (temp != ' ') {
			arr[i] = temp;
			++i;
		}
	}
	
	if (strcmp(arr, "12345678") == 0)
		printf("ascending");
	else if (strcmp(arr, "87654321") == 0)
		printf("descending");
	else
		printf("mixed");
}