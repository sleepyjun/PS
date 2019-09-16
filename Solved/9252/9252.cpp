#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LCS[1001][1001];
string output;	
string a, b;

void bt(int m, int n)
{
	if(m==0 || n==0) return;
	if(LCS[m][n] > LCS[m-1][n-1] && LCS[m][n] > LCS[m][n-1]
	  && LCS[m][n] > LCS[m-1][n])
	{
		output += b[n-1];
		bt(m-1, n-1);
	}
	else if(LCS[m][n] > LCS[m-1][n] && LCS[m][n] == LCS[m][n-1])
		bt(m, n-1);
	else
		bt(m-1, n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	
	for(int i = 1; i <= a.length(); ++i)
	{
		for(int j = 1; j <= b.length(); ++j)
		{
			if(a[i-1] == b[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
		}
	}
	
	int ans = LCS[a.length()][b.length()];
	cout << ans << endl;
	bt(a.length(), b.length());
	reverse(output.begin(), output.end());
	cout << output << endl;
}