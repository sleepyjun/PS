/*문제
무한히 큰 배열에 다음과 같이 분수들을 적혀있다.
0 2 5 9 
0 1 3 6
1/1	1/2	1/3	1/4	1/5	…
2/1	2/2	2/3	2/4	…	…
3/1	3/2	3/3	…	…	…
4/1	4/2	…	…	…	…
5/1	…	…	…	…	…
…	…	…	…	…	…
이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 X(1≤X≤10,000,000)가 주어진다.

출력
첫째 줄에 분수를 출력한다.

예제 입력
14
예제 출력
2/4
*/
//홀수일땐 내려가고 짝수일때는 올라가는빗금

#include<stdio.h>
int main()
{
	int x, y; //  X 
	int N;   //  ㅡ
			  //   Y
	int a = 0, b = 0, cnt = 2;
	scanf("%d", &N);
	N--;
	for (int i = 0; i < N; ++i)
	{
		if (N >= a && N <= b)
			break;
		a += (i + 1);
		b += (i + 2);
		cnt++;
	}
	
	N = N - a;
	
	if (cnt % 2)//홀수
	{
		x = 1;
		y = (cnt - 1);
		printf("%d/%d", x + N, y - N);
	}
	else//짝수
	{
		x = cnt - 1;
		y = 1;
		printf("%d/%d", x - N, y + N);
	}
}