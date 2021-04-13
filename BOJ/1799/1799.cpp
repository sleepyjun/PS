// https://www.acmicpc.net/problem/1799
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
int map[11][11];
int res;

bool check(int cy, int cx)
{
    for(int y = 1; y <= n; ++y)
    {
        for(int x = 1; x <= n; ++x)
        {
            if(map[y][x] != 2 || (y==cy && x==cx)) continue;
            if(map[y][x] == 2 &&
                abs(y-cy) == abs(x-cx)) return false;
        }
    }
    return true;
}
void func(int cy, int cx, int cnt=0)
{
    if(cy > n)
    {
        res = std::max(res, cnt);
        return;
    }
    if(cx > n)
    {
        if(cx%2 == 1) func(cy+1, 2, cnt);
        else func(cy+1, 1, cnt);
        return;
    }
	if(map[cy][cx] == 0)
	{
		func(cy, cx+2, cnt);
		return;
	}

    if(true == check(cy,cx))
    {
        map[cy][cx] = 2;
        func(cy, cx+2, cnt+1);
    }

    map[cy][cx] = 1;
    func(cy, cx+2, cnt);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
    for(int y = 1; y <= n; ++y)
        for(int x = 1; x <= n; ++x)
            cin >> map[y][x];
    
	int ans = 0;
    res = 0; func(1,1); ans += res;
    res = 0; func(1,2); ans += res;

	cout << ans << '\n';
}//g++ -o a -std=c++11 *.cpp