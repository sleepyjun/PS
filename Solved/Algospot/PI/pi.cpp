#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using std::cin; using std::cout;
const int MAX = 987654321;
int dp[10001];
std::string str;

int analysis(int start, int len)
{
	std::string sstr = str.substr(start, len);
	bool flag = true;
	for(int i = 1; i < len && flag; ++i)
	{
		if(sstr[i] != sstr[i-1]) flag = false;
	}
	if(flag) return 1; flag = true;
	for(int i = 1; i < len && flag; ++i)
	{
		if(sstr[i] - sstr[i-1] != sstr[1] - sstr[0])
			flag = false;
	}
	if(flag && std::abs(sstr[1]-sstr[0]) == 1) return 2; 
	if(flag) return 5;
	flag = true;
	
	for(int i = 0; i < len && flag; ++i)
		if(sstr[i] != sstr[i%2]) flag = false;
	if(flag) return 4;
	return 10;
}
int func(int idx=0)
{
	if(idx == str.size()) return 0;
	int& ret = dp[idx];
	if(ret != -1) return ret;
	ret = MAX;
	for(int i = 3; i <= 5; ++i)
	{
		if(idx+i <= str.size())
			ret = std::min(ret, (func(idx+i) + analysis(idx, i)));
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		cin >> str;
		std::fill(dp, dp+10001, -1);
		cout << func() << '\n';
	}
}