/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1<=N<=1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����.
�� ���� ���밪�� 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է�
5
5
2
3
4
1

���� ���
1
2
3
4
5
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, temp;
	int * arr;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 1; j < N - i; ++j)
			if (arr[j-1] > arr[j])
			{
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
	}
	for (int i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}