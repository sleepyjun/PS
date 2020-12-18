// https://www.acmicpc.net/problem/2143
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <map>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::map<int,int> cnt;
std::multiset<int> A,B;
int a[1001], b[1001];
int t,n,m;
void init() 
{
    for(int i = 1; i <= n; ++i)
    {
        int sum = a[i];
        A.insert(sum);
        for(int j = i+1; j <= n; ++j)
        {
            sum += a[j];
            A.insert(sum);
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        int sum = b[i];
        B.insert(sum);
        for(int j = i+1; j <= m; ++j)
        {
            sum += b[j];
            B.insert(sum);
        }
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    init();
    long long res = 0;
    for(int _a : A)
    {
        int x = t-_a;
        if(cnt[x] != 0)
        {
            res += cnt[x];
            continue;
        }
        auto it = B.find(x);
        if(it == B.end()) continue;
        cnt[x] = B.count(x);
        res += cnt[x];
    }
    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp