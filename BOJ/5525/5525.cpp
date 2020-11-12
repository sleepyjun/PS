// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
int fail[1000001];

void func(std::string& str, int n)
{
    for(int i = 1; i < n; ++i)
        str += "OI";
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
    int res = 0;
    std::string src="IOI", dest; cin >> dest;
    func(src, n);

    
    for(int i = 1, j = 0; i < src.length(); ++i)
    {
        while(j > 0 && src[i] != src[j]) j = fail[j-1];
        if(src[i] == src[j]) fail[i] = ++j;
    }
    for(int i = 0, j = 0; i < dest.length(); ++i)
    {
        while(j > 0 && dest[i] != src[j]) j= fail[j-1];
        if(dest[i] == src[j]) 
        {
            if(j == src.length()-1)
            {
                res++;
                j=fail[j];
            }else j++;
        }
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp