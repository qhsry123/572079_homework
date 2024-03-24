#include <stdio.h>
#include <time.h>



long power_rec(long double x,int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power_rec(x * x, n / 2);
	else return x * power_rec(x * x, (n - 1) / 2);
	

}

long power_iter(long double x, int n) {
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = x * result;
	return(result);
}

int main() {


	double duration;
	double duration_1;


	clock_t start = clock();

	double result_rec = power_rec(10,10);
	
	clock_t stop = clock();

	
	
	
	clock_t start_1 = clock();
	
	double result_iter = power_iter(10,10);
	
	clock_t stop_1 = clock();



	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	duration_1 = (double)(stop_1 - start_1) / CLOCKS_PER_SEC;

	printf("Power Recursive Result : %f\n  Time: %f \n", result_rec, duration);
	printf("Power Interactive Result : %f\n Time: %f \n", result_iter, duration_1);



}
