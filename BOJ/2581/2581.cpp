//https://www.acmicpc.net/problem/2581
#include <iostream>
using namespace std;
#include<cmath>
#define COM(X,Y) ((X) = ((X)<(Y)) ? (X) : (Y))
int arr[10001];

int main()
{
    int M,N;
    int sum = 0;
    int temp = 99999;

    cin>>M>>N;
    arr[1] = 0;
    for(int i=2;i<=10000;++i)
        arr[i] = i;

    for(int i=2;i<sqrt(N);++i)
    {
        if(arr[i] == 0)
            continue;
        for(int j = i+i;j<=N;j+=i)
            arr[j] = 0;
    }
    for(int i = M; i <= N; ++i)
    {
        if(arr[i] == 0)
            continue;
        else
        {
            COM(temp,arr[i]);
            sum += arr[i];
        }
    }
    if(sum == 0)
        cout << -1;
    else
        cout << sum <<endl << temp;
}
