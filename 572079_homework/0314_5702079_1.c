#include <stdio.h>
#include <time.h>


int main(void) {


	clock_t start = clock();
	double duration;
	

	int result = 0;
	int a = 0;
	
		for (int i = 2; i <= 100; i++)
		{
			for (a = 2; a < i; a++) {
				if (i % a == 0)break;

			}
			if (a == i)
				result += a;

		}
		clock_t stop = clock();
	printf("�Ҽ��� ���� %d \n", result);

	
	duration = (double)(stop - start/ CLOCKS_PER_SEC);
	printf("�˰��� ���� �ð��� %f���Դϴ�\n", duration);

}