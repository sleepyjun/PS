// https://www.acmicpc.net/problem/12850
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const ull MOD = 1000000007LL;
ull BASE[8][8] = 
{
    {0,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {0,1,0,1,0,0,1,1},
    {0,0,1,0,1,0,1,0},
    {0,0,0,1,0,1,0,0},
    {0,0,0,0,1,0,1,0},
    {0,0,1,1,0,1,0,1},
    {1,1,1,0,0,0,1,0},
};

int func(int d)
{
    ull res[8][8];
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            if(i==j) res[i][j] = 1;
            else res[i][j] = 0;

    while(d)
    {
        ull temp[8][8];
        if(d&1)
        {
            std::copy(&res[0][0], &res[7][8], &temp[0][0]);
            for(int i = 0; i < 8; ++i)
            {
                for(int j = 0; j < 8; ++j)
                {
                    res[i][j] = 0;
                    for(int k = 0; k < 8; ++k)
                    {
                        res[i][j] = (res[i][j] + (temp[i][k] * BASE[k][j]))%MOD;
                    }
                }
            }
        }
        std::copy(&BASE[0][0], &BASE[7][8], &temp[0][0]);
        for(int i = 0; i < 8; ++i)
        {
                for(int j = 0; j < 8; ++j)
                {
                    BASE[i][j] = 0;
                    for(int k = 0; k < 8; ++k)
                    {
                        BASE[i][j] = (BASE[i][j] + (temp[i][k] * temp[k][j]))%MOD;
                    }
                }
        }
        d >>= 1;
    }

    return res[0][0];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int d; cin >> d;
    cout << func(d) << '\n';
}//g++ -o a -std=c++11 *.cpp