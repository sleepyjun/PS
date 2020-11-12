// https://www.acmicpc.net/problem/12851
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <set>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[100001];
bool position(int n)
{
    if(n < 0 || n > 100000) return false;
    if(visited[n] == true) return false;
    return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k; cin >> n >> k;
    if(n==k)
    {
        cout << "0\n1\n";
        return 0;
    }
    int res = 0, step = 0;
    std::queue<int> map;
    map.push(n); visited[n] = true;
    while(!map.empty())
    {
        std::set<int> s;
        int qSize = map.size();
        for(int i = 0; i < qSize; ++i)
        {
            int curr = map.front(); map.pop();
            int n = curr+1;
            if(true == position(n))
            {
                map.push(n);
                if(n != k) s.insert(n);
                else res++;
            }n = curr-1;
            if(true == position(n))
            {
                map.push(n);
                if(n != k) s.insert(n);
                else res++;
            }n = curr*2;
            if(true == position(n))
            {
                map.push(n);
                if(n != k) s.insert(n);
                else res++;
            }
        }
        step++;
        if(res != 0) break;
        for(int visit : s)
        {
            visited[visit] = true;
        }s.clear();
    }

    cout << step << '\n' << res << '\n';
}//g++ -o a -std=c++11 *.cpp