#include <cstdio>

#include <cmath>

int main()

{

   unsigned long long sum;

   int n;

   scanf("%d", &n);

   sum = pow(pow(2,n)+1,2);

   printf("%llu\n", sum);

}