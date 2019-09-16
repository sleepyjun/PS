#include <iostream>

using namespace std;

int main()
{
    long long N, K;
    long long result = 1;
    long long divide = 1;
    cin >> N >> K;
    for(int i = 1; i <= K; ++i)
    {
        result *= (N--);
        divide *= i;
    }
    cout << result/divide;
}
