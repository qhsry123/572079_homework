#include <stdio.h>
#include <time.h>


int main(void) {

	double duration;
	

	int result = 0;//결과값 0으로 잡기
	int a = 0;
	
	clock_t start = clock();//알고리즘 시작시간 저장
		
	for (int i = 2; i <= 100; i++)//1은 소수가 아니므로 2부터 100까지 소수인지 확인
		{
			for (a = 2; a < i; a++)//2부터 i-1까지의 수로 i를 나누었을때 나머지가 0인지 판별
			{
				if (i % a == 0)break;

			}
			if (a == i)//2부터 i-1까지의 수로 i를 나누었을때 나머지가 0이 아니고 i와 같다면 결과값에 더하기
				result += a;

		}
		clock_t stop = clock();//알고리즘 종료시간 저장
	printf("소수의 합은 %d \n", result);//소수의 합 출력

	
	duration = (double)(stop - start)/ CLOCKS_PER_SEC;//종료시간에서 시작시간을빼 구동한 시간을 구한후 CLOCKS_PER_SEC를 이용해 초단위로 변경
	printf("알고리즘 수행 시간은 %f초입니다\n", duration);
		//clock()함수가 ms초까지만 측정가능, 따라서 프로그램을 구동시키면 CPU성능에따라 수행시간이 0.000000초로 나오는 경우를 확인했습니다. 
		//1부터 100까지의 소수합이아닌 1부터 10000이상 정도로 값을 바꿀경우에는 정상적으로 시간이 출력된걸 확인했습니다.

}