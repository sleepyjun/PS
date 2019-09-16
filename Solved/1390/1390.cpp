#include <cstdio>

const int C = 9901;

 

int arr[100001][3];

 

int main()

{

    int N;

    

    scanf("%d", &N);

    arr[1][0] = arr[1][1] = arr[1][2] = 1;

    

    for(int i = 2; i <= N; ++i)

    {

        arr[i][0] = (arr[i-1][0] + arr[i-1][1] + arr[i-1][2]) % C;

        

        arr[i][1] = (arr[i-1][0] + arr[i-1][2]) % C;

        

        arr[i][2] = (arr[i-1][0] + arr[i-1][1]) % C;

    }

    

    printf("%d\n", (arr[N][0] + arr[N][1] + arr[N][2]) % C);

}

