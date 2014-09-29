#include <stdio.h>
#include <time.h>

#define N 45

long fibonacci(int);
long fib3(int, long*);
int main(void)
{
	int i;
	long l;
	clock_t begin, end;
	double time_spent;
	begin = clock();
	for(i = 0; i < N; i++)
	{
		l = fibonacci(i);
		printf("%4d %20ld\n", i, l);	
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f sec\n", time_spent);	
	return 0;
}
long fibonacci(int n){
	if(n == 0){
		return 0;
	}else if(n == 1){
		return 1;	
	}else{
		long *x;
		//y is n - 1'th fibonacci number
		long y = fib3(n - 1, x);
		//x is n - 2'th fibonacci number. Add fib(n- 1) + fib(n - 2 = fib(n)	
		return *x + y;
	}
}
long fib3(int n, long *x){
	if(n == 0){
		return 0;
	}else if(n == 1){
		*x = (long) 0;
		return 1;
	}else{
		long y =  fib3(n - 1, x);
		//now, x = n -2 fibonacci number
		long tot = y + (long) *x;
		//so, x is now n - 1 fibonacci number.
		*x = (long) y;
		return tot;
	}
}
