#include <iostream>

using namespace std;
long long arr[90];

long long fibo(int N)
{
    if(N == 1)
        return 1;
    else if(N == 0)
        return 0;
    else if(arr[N] != 0)
        return arr[N];
    else
    {
        return arr[N] = fibo(N-1) + fibo(N-2);
    }
}
int main()
{
    long long N;

    cin >> N;
    cout << fibo(N);
}
