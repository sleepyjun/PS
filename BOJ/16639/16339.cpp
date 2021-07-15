// https://www.acmicpc.net/problem/16639
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int _INF = std::numeric_limits<int>::min();

int num[20];
char op[20];

long long maxCache[20][20];
long long minCache[20][20];

long long calc(long long a, long long b, char op)
{
	switch(op)
	{
		case '+':
		return a+b;
		case '-':
		return a-b;
		default:
		return a*b;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&maxCache[0][0], &maxCache[19][20], _INF);
	std::fill(&minCache[0][0], &minCache[19][20], INF);

	int n; cin >> n;
	int numIdx = n/2+1;
	int opIdx = n/2;

	for(int i = 0; i < n; ++i)
	{
		if(i%2 == 0) // number
		{
			cin >> num[i/2];
			maxCache[i/2][i/2] = minCache[i/2][i/2] = num[i/2];
		}
		else // operator
			cin >> op[i/2];
	}

	for(int k = 1; k < numIdx; ++k)
	{
		for(int idx = 0; idx+k < numIdx; ++idx)
		{
			for(int i = 1, j = k; i <= k; ++i, --j)
			{
				long long arr[4] = {
					calc(minCache[idx][idx+k-j], minCache[idx+i][idx+k], op[idx+k-j]),
					calc(minCache[idx][idx+k-j], maxCache[idx+i][idx+k], op[idx+k-j]),
					calc(maxCache[idx][idx+k-j], minCache[idx+i][idx+k], op[idx+k-j]),
					calc(maxCache[idx][idx+k-j], maxCache[idx+i][idx+k], op[idx+k-j])
				};
				std::sort(arr, arr+4);
				minCache[idx][idx+k] = std::min(minCache[idx][idx+k], arr[0]);
				maxCache[idx][idx+k] = std::max(maxCache[idx][idx+k], arr[3]);
				//cout << idx << ' ' <<  idx+k-j << '\t';
				//cout << idx+i << ' ' << idx+k <<'\n';
			}
		}
	}

	cout << maxCache[0][numIdx-1] << '\n';
}//g++ -o a -std=c++17 *.cpp