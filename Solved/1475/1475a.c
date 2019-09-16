#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[10] = {0,};
    int N;
    int max, temp;

    scanf("%d",&N);
    if(N!=0)
    {


    while(N > 0)
    {
        ++num[N%10];
        N /= 10;
    }
    temp = num[6]+num[9];
    max = temp%2 ? (temp/2)+1 : temp/2;
    for(int i = 0; i < 10; ++i)
    {
        if(i == 9 || i == 6)
            continue;
        max = max < num[i] ? num[i] : max;
    }
    printf("%d",max);
    }
    else
        printf("1");
    return 0;
}
