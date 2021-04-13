// https://www.acmicpc.net/problem/1509
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::string str;
int dp[2501];
int isIt[2501][2501];

int check(int s, int e)
{
    int &ret = isIt[s][e];
    if(ret != -1) return ret;
    if(s==e) return ret=1;
    if(str[s] != str[e]) return ret=0;
    else
    {
        if(s+1 == e) return ret=1;
        return ret = check(s+1,e-1);
    }
    
}
int func(int idx)
{
    if(idx == str.length()) return 0;
    int &ret = dp[idx];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = idx; i < str.length(); ++i)
        if(1 == check(idx,i)) ret = std::min(ret, 1+func(i+1));

    return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
    std::fill(dp,dp+2501,-1);
    std::fill(&isIt[0][0], &isIt[2500][2501], -1);
    cout << func(0) << '\n';
}//g++ -o a -std=c++11 *.cpp