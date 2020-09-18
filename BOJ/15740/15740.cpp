#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define CtoD(x) ((x)-('0'))

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string A, B;
	string result;
	
	cin >> A >> B;
	
	bool mA = (A[0] == '-');
	bool mB = (B[0] == '-');
	
	A.erase(remove(A.begin(), A.end(), '-'), A.end());
	B.erase(remove(B.begin(), B.end(), '-'), B.end());

	//Make String A always big
	if(A.length() < B.length())
	{
		swap(A, B);
		swap(mA, mB);
	}
	else if(A.length() == B.length())
	{
		int flag = 0; //0 mean A is big
		
		for(int i = 0; i < A.length(); ++i)
		{
			if(A[i] > B[i]) break;
			if(A[i] < B[i])
			{
				flag = 1; break;
			}
		}
		if(flag)
		{
			swap(A, B);
			swap(mA, mB);
		}
	}
	
	/********** Calculation **********/
	//reverse strings to calc easy
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	if(mA == mB) //First add & minus check
	{
		int up = 0;
		int bLen = A.length();
		int sLen = B.length();
		for(int i = 0; i < sLen; ++i)
		{
			int res = CtoD(A[i]) + CtoD(B[i]) + up;
			result += to_string(res%10);
			if(res > 9) up = 1;
			else up = 0;
		}
		for(int i = sLen; i < bLen; ++i)
		{
			int res = CtoD(A[i]) + up;	
			result += to_string(res%10);
			if(res > 9) up = 1;
			else up = 0;
		}
		if(up) result += to_string(up);
		
		reverse(result.begin(), result.end());
		int pos = 0;
		for(int i = 0; i < result.length(); ++i, ++pos)
			if(result[i] != '0') break;
		result.erase(0,pos);
		
		if(result.empty()) result += to_string(0);
		else if(mA == 1)
			result.insert(0, 1, '-');
		cout << result << '\n';
	}
	else //sub & minus check
	{
		int down = 0;
		int bLen = A.length();
		int sLen = B.length();
		for(int i = 0; i < sLen; ++i)
		{
			int chk = CtoD(A[i]) - CtoD(B[i]) - down;
			int res = 10+chk;
			result += to_string(res%10);
			if(chk < 0) down = 1;
			else down = 0;
		}
		for(int i = sLen; i < bLen; ++i)
		{
			int chk = CtoD(A[i]) - down;
			int res = 10 + chk;
			result += to_string(res%10);
			if(chk < 0) down = 1;
			else down = 0;
		}

		reverse(result.begin(), result.end());
		int pos = 0;
		for(int i = 0; i < result.length(); ++i, ++pos)
			if(result[i] != '0') break;
		result.erase(0,pos);
		
		if(result.empty()) result += to_string(0);
		else if(mA == 1)
			result.insert(0, 1, '-');
		
		cout << result << '\n';
	}
}