// https://www.acmicpc.net/problem/16637
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int num[20];
char op[20];
int numIdx, opIdx;
int res = -INF;

int calc(int a, int b, int oIdx)
{
	if(oIdx == -1) return a + b;

	switch (op[oIdx])
	{
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '*':
		return a*b;
	}
	return 0;
}
void run(int nIdx = 0, int oIdx = -1, int sum=0)
{
	if(nIdx >= numIdx)
	{
		res = std::max(res, sum);
		return;
	}

	int temp = calc(sum, num[nIdx], oIdx);
	run(nIdx+1, oIdx+1, temp);

	if(nIdx+2 <= numIdx)
	{
		temp = calc(num[nIdx], num[nIdx+1], oIdx+1);
		temp = calc(sum, temp, oIdx);
		run(nIdx+2, oIdx+2, temp);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	numIdx = n/2+1;
	opIdx = n/2;

	for(int i = 0; i < n; ++i)
	{
		if(i%2 == 0) // number
			cin >> num[i/2];
		else // operator
			cin >> op[i/2];
	}

	run();
	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp