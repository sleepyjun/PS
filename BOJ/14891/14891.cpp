// https://www.acmicpc.net/problem/15662
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int FRONT = (7);
const int BACK = (0);
const int LEFT = (1);
const int RIGHT = (5);

int arr[1001];
bool turn[1001];

void ccw(int &n) // counter clock
{
	int f = (n & (1 << FRONT));
	n &= (~(1 << FRONT));
	n <<= 1;
	if(f != 0) n |= (1 << BACK);
}
void cw(int &n) // clock
{
	int b = (n & (1 << BACK));
	n &= (~(1 << BACK));
	n >>= 1;
	if(b != 0) n |= (1 << FRONT);
}
void func(int f, int &n)
{
	if(f == -1) ccw(n);
	else if(f == 1) cw(n);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; n = 4;

	for(int i = 0; i < n; ++i) 
	// N == 0 S == 1
	{
		std::string str; cin >> str;
		for(char ch: str)
		{
			if(ch == '1')
				arr[i] |= 1;
			arr[i] <<= 1;
		}
		arr[i] >>= 1;
	}

	int t; cin >> t;
	while(t--)
	{
		std::fill(turn, turn+1001, false);
		int i, d; cin >> i >> d;
		int rev = (d==1 ? -1 : 1);
		--i;
		turn[i] = true;
		//! prev
		for(int prev = i-1; prev >= 0; --prev)
		{
			int cLeft = (arr[prev+1] & (1 << LEFT));
			int pRight = (arr[prev] & (1 << RIGHT));
			if((cLeft != 0 && pRight != 0) ||
				(cLeft == 0 && pRight == 0)) break;
			turn[prev] = true;
		}
		//! next
		for(int next = i+1; next < n; ++next)
		{
			int cRight = (arr[next-1] & (1 << RIGHT));
			int nLeft = (arr[next] & (1 << LEFT));

			if((cRight != 0 && nLeft != 0) ||
				(cRight == 0 && nLeft == 0)) break;
			turn[next] = true;
		}

		for(int idx = 0; idx < n; ++idx)
		{
			if(turn[idx] == true)
			{
				if(i%2 == idx%2)
				{
					func(d, arr[idx]);
				}
				else
				{
					func(rev, arr[idx]);
				}
			}
		}
	}
	
	int point = 1;
	int sum = 0;
	for(int i = 0; i < n; ++i, point*=2)
	{
		int res = (arr[i] & (1 << FRONT));
		if(res != 0) sum += point;
	}

	cout << sum << '\n';
}//g++ -o a -std=c++17 *.cpp