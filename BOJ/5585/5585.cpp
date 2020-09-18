// https://www.acmicpc.net/problem/5585
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int N = 6;
int coin[N] = {500,100,50,10,5,1};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int in,cnt=0,x=0; cin >> in;
	in = 1000-in;
	for(int i = 0; i < N; ++i)
		if(in >= coin[i])
		{
			cnt += in/coin[i];
			in %= coin[i];
		}
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;