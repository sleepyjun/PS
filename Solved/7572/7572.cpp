#include <cstdio>

char beast[] = {'I','J','K','L','A','B',
				'C','D','E','F','G','H'};
char code[] = {'6', '7', '8', '9' ,'0',
			   '1', '2', '3', '4', '5'};
int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%c%c\n", beast[n%12], code[n%10]);
}