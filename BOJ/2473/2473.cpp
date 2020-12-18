// https://www.acmicpc.net/problem/2473
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const long long INF = std::numeric_limits<long long>::max();

long long arr[5001];
long long _abs(long long a)
{
    if(a < 0) return a*-1;
    return a;
}
long long func(int s, int i, int e)
{
    return _abs(arr[s]+arr[i]+arr[e]);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    long long res[3], sum=INF;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    std::sort(arr,arr+n);

    for(int i = 0; i < n; ++i)
    {
        int s = 0, e = n-1;
        while(1)
        {
            if(s==e) break;
            long long x = func(s,i,e);
            if(sum > x)
            {
                if(s != i && i != e)
                {
                    sum = x;
                    res[0] = arr[s];
                    res[1] = arr[i];
                    res[2] = arr[e];
                }
            }
            if(func(s+1,i,e) > func(s,i,e-1)) e--;
            else s++;
        }
    }
    std::sort(res, res+3);
    for(int i = 0; i < 3; ++i)
        cout << res[i] << ' ';
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp