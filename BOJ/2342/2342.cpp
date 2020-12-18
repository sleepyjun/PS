// https://www.acmicpc.net/problem/2342
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 987654321;

int dp[100005][5][5];
int seqence[100005];
int n=1;
int power(int prev, int next)
{   
    if(prev==0) return 2;
    if(prev==next) return 1;
    if((prev==1 && next==3) ||
        (prev==2 && next==4) ||
        (prev==3 && next==1) ||
        (prev==4 && next==2)) return 4;
    return 3;
}
int func(int seq, int l, int r)
{
    if(l==r && seq!=0) return INF;
    if(seq == n-1) return 0;

    int &ret = dp[seq][l][r];
    if(ret != -1) return ret;
    
    ret = std::min(func(seq+1,seqence[seq+1], r) + power(l, seqence[seq+1]),
        func(seq+1, l, seqence[seq+1]) + power(r, seqence[seq+1]));
    return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&dp[0][0][0], &dp[100004][4][5], -1);
    while(1)
    {
        int x; cin >> x;
        if(x==0) break;
        seqence[n++] = x;
    }
    cout << func(0,0,0) << '\n';
}//g++ -o a -std=c++11 *.cpp