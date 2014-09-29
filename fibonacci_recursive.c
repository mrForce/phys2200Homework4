#include <stdio.h>
#include <time.h>

#define N 45

long fibonacci(int);
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
		return fibonacci(n-1) + fibonacci(n - 2);
	}

}
