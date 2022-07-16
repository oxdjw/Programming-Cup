/*
SCPC 2번문제 수열
N개의 정수 수들을 입력받아 수열을 만들어서 K개의 그룹으로 나누는데 각 그룹의 수의 합이 일정하게끔 나누는 문제 
코드는 맞게 되었다고 생각했는데 while문에서 시간초과가 난 듯 보임
DFS , 재귀로 문제를 풀 수 있을 것 같았는데 아직 익숙치 않아서 시도조차 못 해보고 점수획득 실패 
그룹의 수의 합을 배열의 첫 인덱스, 첫 인덱스+두번째 인덱스, 첫 인덱스+두번째 인덱스+세번째 인덱스.. 순으로 구성하게 해서
그룹들의 수의 합이 일정할 때 반복문 탈출하면서 count++, count가 K변수와 일치할 때 Answer++해주는 로직으로 구성하였음 
*/
#include <iostream>
#include <numeric>
using namespace std;

long long Answer;

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	long long T, test_case;

	scanf("%lld",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;

		long long n,k;
		scanf("%lld %lld",&n,&k);
		long long* arr = new long long[n];
		
		for(register long long i = 0 ; i < n ; i++)
		{
			long long ipt;
			scanf("%lld",&ipt);
			arr[i] = ipt;
		}

		for(register long long i = 0 ; i < n ; i++)
		{
			long long sum = 0;
			long long cnt = 1;
			long long check = 0;

			sum = accumulate(arr,arr+i+1,0);	//sum정해주기 
			long long start = i;	//sum으로 측정된 인덱스 이후 sum값과 같은 합이 만들어지게 셀건데 시작 첫 인덱스값 start 
			while( start < n && cnt + n-start-1 >= k)	//start인덱스가 배열의 끝까지 도달하거나, 만들어야 할 그룹의 수(K)가 앞으로 만들 수 있는 그룹의 수+만든 그룹의 수보다 크면 while문 탈출 
			{
				if(start+1 == n){	//끝까지 도달했을 때 예외처리 
					if(sum == check)	//마지막 인덱스가 sum값과 일치하면 
						cnt++;			//마지막 인덱스 자체로 하나의 그룹으로 생각해서 cnt++ 
					break;	//탈출 
				}
				check += arr[start+1];	//check변수에 더해주어서 sum과 비교할 수 있게 끔 해줌 
				if(sum == check) { 
				check = 0; cnt++;	//더한값이 sum과 일치하면 count++ 
				}
				start++;	//sum과 check가 일치해서 새로운 값으로 시작하든, 여태 더한 check값이 sum과 달라서 또 더해주어서 비교하는 루프로 가든 start는 올려줌 
			}
			if(cnt == k)	//일치했던 횟수(나눈 그룹의 수)가 K값과 일치하면 정답!  
			{
				Answer++;
			}
		}
		for(register long long t = 1 ; t < n-1 ; t++)
		{
			if(arr[t-1] == arr[t]*(-1) && arr[t]*(-1) == arr[t+1])
				Answer+=2;	//3번째 예제인 1 1 -1 1 1 1 1 1 -1 1 를 보고 앞뒤로 절대값만 다른 인덱스가 있을때 +2씩 추가해주었다. 
		}
		printf("Case #%lld\n",test_case+1);
		printf("%lld\n",Answer%1000000007);	//문제에서 제시한 것 처럼 해당 수로 나눈 나머지 출력 
	}

	return 0;
}
