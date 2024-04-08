#include <stdio.h>
#define MAX_TERMS 101
#include <stdlib.h>

struct term {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {4.0,3},{3.0,2},{2.0,1},{1.0,0},
						{3.0, 2},{2.0,1},{8.0,0} };

int avail = 7;



void print_poly(int s, int e);
void poly_add2(int As, int Ae, int Bs, int Be, int* Csp, int* Cep);

void print_poly(int s, int e) {

	for (int i = s; i < e; i++) {
		printf(" % 3.1fx^%d +", terms[i].coef, terms[i].expon);
	}
	printf(" % 3.1fx^%d \n", terms[e].coef, terms[e].expon);
}



void attach(float coef, int expon, int s) {
	int i;
	int j;

	if (avail >= MAX_TERMS) {
		printf("Max terms over.");
		exit(1);
	}
	avail--;

	i = avail;

	for (j = i; j >= s; j--)
	{
		if (terms[j].expon == expon)
		{
			terms[j].coef += coef;
			avail++;
			return;
		}


	}
	avail++;
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
};
void poly_add2(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {


	float coefficient;
	int exponent;
	int i, j;
	int s;

	*Csp = avail;

	for (i = As; i <= Ae; i++)
	{
		for (j = Bs; j <= Be; j++)
		{
			coefficient = terms[i].coef * terms[j].coef;   //°è¼öÀÇ °ö
			exponent = terms[i].expon + terms[j].expon;  // Áö¼öÀÇ ÇÕ
			s = Be + 1;                        // sÀÇ À§Ä¡ ÁöÁ¤
			attach(coefficient, exponent, s);          //°ö¼ÀÇ× Ã·°¡   
		}
	}

	*Cep = avail - 1;



}



int main(int argc, char* argv[]) {
	int Cs, Ce;
	print_poly(0, 3);
	print_poly(4, 6);

	poly_add2(0, 3, 4, 6, &Cs, &Ce);
	printf("--------------------------------------------------------------------------------------------------------------\n");
	print_poly(Cs, Ce);
}