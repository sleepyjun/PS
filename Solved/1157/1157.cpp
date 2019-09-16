/*문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.주어지는 단어의 길이는 1, 000, 000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ? 를 출력한다.

예제 입력  복사
Mississipi
예제 출력  복사
?
*/
#include<stdio.h>
#include<string.h>

void Result(int arr[26])
{
	int max=0;
	int sw;
	int a;

	for (int i = 0; i < 26; ++i)
	{
		
		if (max < arr[i])
		{
			sw = 0;
			max = arr[i];
			a = i;
		}
		else if (max && (max == arr[i]))
			sw = 1;
	}
	if (sw)
		printf("?");
	else
		printf("%c", a+'A');
}

int main()
{
	int arr[26] = { 0 };
	char ch[1000001] = { '\0' };
	int i;

	scanf("%s", ch);
	for (i = 0; i < strlen(ch); ++i)
	{
		if (ch[i] >= 'a' && ch[i] <= 'z')
		{
			arr[ch[i] - 'a']++;
		}
		else if (ch[i] >= 'A' && ch[i] <= 'Z')
		{
			arr[ch[i] - 'A']++;
		}
	}
	Result(arr);
}