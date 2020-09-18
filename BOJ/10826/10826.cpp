#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define CtoD(x) ((x)-('0'))

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string lower = "0";
	string bigger = "1";
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		
		reverse(lower.begin(), lower.end());
		reverse(bigger.begin(), bigger.end());
		string temp;
		int up = 0;
		int bLen = bigger.length();
		int sLen = lower.length();
		for(int j = 0; j < sLen; ++j)
		{
			int res = CtoD(lower[j]) + CtoD(bigger[j]) + up;
			temp += to_string(res%10);
			if(res > 9) up = 1;
			else up = 0;
		}
		for(int j = sLen; j < bLen; ++j)
		{
			int res = CtoD(bigger[j]) + up;
			temp += to_string(res%10);
			if(res > 9) up = 1;
			else up = 0;
		}
		if(up) temp += to_string(up);
		reverse(temp.begin(), temp.end());
		reverse(lower.begin(), lower.end());
		reverse(bigger.begin(), bigger.end());
		
		swap(lower,bigger);
		swap(bigger,temp);
	}
	
	cout << lower << endl;
}