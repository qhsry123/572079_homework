#include <stdio.h>
#include <time.h>


int main(void) {

	int result = 0;//결과값 0으로 잡기
	int a = 0;

	

	for (int i = 2; i <= 100; i++)//1은 소수가 아니므로 1부터가 아닌 2부터 시작
	{
		for (a = 2; a < i; a++)//2부터 i-1까지의 수로 i를 나누었을때 나머지가 0인지 판별, 0이면 소수가 아니라고 판단
		{
			if (i % a == 0)break;

		}
		if (a == i)
			result += a;//2부터 i-1까지의 수로 i를 나누었을때 나누어떨어지지 않았으면 결과값에 더하기

	}
	
	printf("소수의 합은 %d \n", result);//소수의 합 출력
	ddfa



}