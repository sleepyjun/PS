/*상근이의 할머니는 아래 그림과 같이 오래된 다이얼 전화기를 사용한다.



전화를 걸고 싶은 번호가 있다면, 
숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다.
다른 숫자를 누르려면 다이얼이 원래 위치로 돌아가기를 기다려야 한다.

숫자 1을 걸려면 총 2초가 필요하다. 
1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 
한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다.
즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다.예를 들어, 
UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 
이 전화를 걸기 위해서 필요한 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다.단어는 2글자~15글자로 이루어져 있다.

출력
첫째 줄에 다이얼을 걸기 위해서 필요한 시간을 출력한다.

예제 입력
UNUCIC
예제 출력
36*/

//ABC = 2
//DEF = 3
//GHI = 4
//JKL = 5
//MNO = 6
//PQRS = 7
//TUV = 8
//WXYZ = 9

#include<stdio.h>
#include<string.h>

int main()
{
	char Num[16];
	int total = 0;

	scanf("%s", Num);

	total += strlen(Num);

	for (int i = 0; i < strlen(Num); ++i)
	{
		if (Num[i] >= 'A' && Num[i] <= 'C')
			total += 2;
		else if (Num[i] >= 'D' && Num[i] <= 'F')
			total += 3;
		else if (Num[i] >= 'G' && Num[i] <= 'I')
			total += 4;
		else if (Num[i] >= 'J' && Num[i] <= 'L')
			total += 5;
		else if (Num[i] >= 'M' && Num[i] <= 'O')
			total += 6;
		else if (Num[i] >= 'P' && Num[i] <= 'S')
			total += 7;
		else if (Num[i] >= 'T' && Num[i] <= 'V')
			total += 8;
		else if (Num[i] >= 'W' && Num[i] <= 'Z')
			total += 9;
	}
	printf("%d", total);
}


/*int main()
{
	int temp[] = { 2,3,4,5,6,7,8,9 };
	int total = 0;
	char num[16];

	scanf("%s", num);
	total += strlen(num);

	for (int i = 0; i < strlen(num); ++i)
		total += temp[(num[i] - 'A') / 3];

	printf("%d", total);
}*/