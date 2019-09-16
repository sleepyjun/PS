#include<stdio.h>
#include<string.h>

int main()
{
	char c;//ch[1000001];
	int i=0 , j;
	int cnt = 0;
	//앞에 띄어쓰기 뒤에 띄어쓰기 중간에 띄어쓰기 여러개
	
	while ((c = getchar()) != EOF && c != '\n')
	{
		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			i = 1;

		else if (c == ' ')//중간공백 고려
		{
			if (i)
			{
				i = 0;
				++cnt;
			}
		}
	}
	if (i)
		++cnt;
	printf("%d", cnt);
}