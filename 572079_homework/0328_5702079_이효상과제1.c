#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;


void print_polynomial(polynomial p);
polynomial poly_mult(polynomial A, polynomial B);

int main() {
	polynomial a = { 3,{4.0, 3.0, 2.0, 1.0} };
	polynomial b = { 2,{3.0, 2.0, 8.0} };

	polynomial c;

	print_polynomial(a);
	print_polynomial(b);

	c = poly_mult(a, b);
	printf("----------------------------------------------------------------------------\n");
	print_polynomial(c);
}

polynomial poly_mult(polynomial A, polynomial B) {
	polynomial C;


	int degree_a = A.degree, degree_b = B.degree;

	C.degree = A.degree + B.degree;

	for (int i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;

	for (int j = 0; j < degree_a + 1; j++) {
		for (int k = 0; k < degree_b + 1; k++) {
			C.coef[k + j] += A.coef[j] * B.coef[k];

		}
	}




	return C;
}



void print_polynomial(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d +", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);


}
