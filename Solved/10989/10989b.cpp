#include<stdio.h>
#include<stdlib.h>


int main()
{
	int max = -1,i;
	long N;
	int *arr,*temp;
	int *cnt;
	scanf("%ld", &N);

	arr = (int *)malloc(sizeof(int)*N);
	temp = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
		max = max < arr[i] ? arr[i] : max;//���� ū�� ã��
	}
	max++;//����ū���� �����ϱ����� max�� �ϳ��ø�
	cnt = (int *)calloc(max, sizeof(int));//�迭����
	
	for (i = 0; i < N; ++i)
		cnt[arr[i]]++;//������Ŵ

	for (i = 1; i < max; ++i)
		cnt[i] += cnt[i - 1];//����

	

	int *ans = (int*)malloc(sizeof(int)*max);

	for (int i = 0; i<N; i++) {
		int k = arr[i];
		ans[cnt[k] - 1] = k;
		cnt[k]--;
	}

	for (int i = 0; i<N; i++) {
		printf("%d\n", ans[i]);
	}
	
	free(arr); free(temp); free(cnt); free(ans);
}

//��Ÿ�� ���� ����
