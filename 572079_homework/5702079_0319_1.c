#include <stdio.h>
#include <time.h>



long factorial_rec(int n) {
	if (n <= 1) return(1);
		else return (n * factorial_rec(n - 1));


}

long factorial_iter(int n) {
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result = result * i;
		return(result);

	

}

int main(){

	
	double duration;
	double duration_1;

	
	clock_t start = clock();
	long result_rec = factorial_rec(20);
	clock_t stop = clock();
	
	clock_t start_1 = clock();
	long result_iter = factorial_iter(20);
	clock_t stop_1 = clock();
	
	

	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	duration_1 = (double)(stop_1 - start_1) / CLOCKS_PER_SEC;
	
	printf("Factorial Recursive Result : %ld\n  Time: %f \n", result_rec, duration);
	printf("Factorial Interactive Result : %ld\n Time: %f \n", result_iter, duration_1);



}