// https://www.acmicpc.net/problem/18119
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

enum {DELETE=1, ADD};
int string[10000];
int base[10000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        std::string str; cin >> str;
        for(char ch : str)
        {
            string[i] |= (1<<(ch-'a'));
        }
    }
    std::copy(string, string+10000, base);
    
    while(m--)
    {
        int cond;
        char ch; cin >> cond >> ch;
        if(cond == DELETE)
            for(int i = 0; i < n; ++i)
                string[i] &= ~(1<<(ch-'a'));
        else if(cond == ADD)
            for(int i = 0; i < n; ++i)
                if(base[i] & (1<<(ch-'a')))
                    string[i] |= (1<<(ch-'a'));
        
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(base[i] == string[i]) res++;
        cout << res << '\n';
    }
    
}//g++ -o a -std=c++11 *.cpp