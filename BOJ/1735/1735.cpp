// https://www.acmicpc.net/problem/1735
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int func(int a, int b) //a > b
{
	while(b)
	{
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a,b,c,d;
	cin >> a >> b;
	cin >> c >> d;
	int temp = func(b,d);
	
	int down = b*d/temp;
	int up = (down/b*a)+(down/d*c);
	
	temp = func(up,down);
	cout << up/temp << ' ' << down/temp << '\n';
	
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;