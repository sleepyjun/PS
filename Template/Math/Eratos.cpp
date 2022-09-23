void Eratos(int n)
{
    /*  만일 n이 1보다 작거나 같으면 함수 종료 */
    if (n <= 1) return;

    /*	2부터 n까지 n-1개를 저장할 수 있는 배열 할당
		배열 참조 번호와 소수와 일치하도록 배열의 크기는
		n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)	*/
	bool* PrimeArray = new bool[n + 1];

	/*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
	for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	/*	에라토스테네스의 체에 맞게 소수를 구함
		만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
	}

	// 이후의 작업 ...
}

unsigned long long EulersPhi(unsigned long long n)
{
	unsigned long long res = n;
	for(unsigned long long i = 2; i*i <= n; ++i)
	{
		if(n%i == 0)
		{
			res /= i;
			res *= (i-1);
		}
		while(n%i == 0) n /= i;
		//소인수 하나에 대해서 한번만 수행하면되므로 남은 특정 소인수는 다 나눠줌
	}
	if(n != 1) //n이 1이아니라면 마지막으로 남은 소인수가 있단 의미므로 그 소인수에 대해 수행
	{
		res /= n;
		res *= (n-1);
	}
	return res;
}