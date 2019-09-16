/*
문제
1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다. 
예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다. 
하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.

골드바흐의 추측은 유명한 정수론의 미해결 문제로, 
2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다. 
이러한 숫자를 골드바흐 숫자라고 한다. 
또, 짝수를 두 소수의 합으로 나타내는 표현을 그 숫자의 골드바흐 파티션이라고 한다. 
예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 
10000보다 작은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

2보다 큰 짝수 n이 주어졌을 때, 
n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오. 
만약 가능한 n의 골드바흐 파티션이 여러가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다. (4 ≤ n ≤ 10,000)

출력
각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다. 
출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

예제 입력  복사
3
8
10
16
예제 출력  복사
3 5
5 5
5 11
*/
#include<stdio.h>

int isitprime(int X,int prime[],int N)
{
	for (int i = 0; i < N; ++i)
	{
		if (X%prime[i] == 0)
			return 0;
	}
	prime[N] = X;
	return 1;
}
int main()
{
	int T,N=2,X;
	int cnt;
	int prime[10000];
	int A, B,a,b;
	int S;
	int sum;
	scanf("%d", &T);

	//10000까지 소수 찾기
	prime[0] = 2; prime[1] = 3;
	for (int i = 5; i < 20000; i += 2)
	{
		if (isitprime(i, prime, N))
			N++;
	}
	//끝

	for (int i = 0; i < T; ++i)
	{
		cnt = 0; A = -1; B = -1;
		sum = 0;
		scanf("%d", &X);

		if (X % 2 == 0)
		{
			for (int j = 0; j < 5000; ++j)
			{
				if (X < prime[j])
				{
					break;
				}
				cnt++;
			}
			S = 0; --cnt;
			while(A<=B)
			{

				A = prime[S];
				B = prime[cnt];
				sum = A + B;
				if (X == sum) { a = A; b = B; S++; }
				else if (X < sum)
				{
					cnt--;
				}
				else if (X > sum)
				{
					S++;
				}
				
			}
			if (a > b)
			{
				int temp = a; a = b; b = temp;
			}
			printf("%d %d\n", a,b);
		}
	}
}