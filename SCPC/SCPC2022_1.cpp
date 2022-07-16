/*
SCPC 1번문제 개미
각각의 위치좌표와 짐을 갖고 있는 개미들이 짐의 크기 순서대로 오름차순 정렬 할 때 개미들의 이동거리 최소값 합 구하기 
처음에는 tc내 2중포문으로 인해 시간초과가 나서 만점을 받지 못 했음
빅오를 줄일 방법을 생각하다가 개미를 구조체로 구현해서 하나씩 비교하면 빅오 n으로
코드를 완성할 수 있다고 생각이 되어 다음과 같이 구현하였음
개미의 위치와 짐이 1~10^9 범위기에 int가 아닌 long long 으로 모든 정수리터럴을 바꿔주었음 
결과는 100/100 점 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long Answer;

struct Ant
	{
		public:
			long long x;  //개미의 위치좌표 
		    long long val;//개미의 짐 
		
	};
bool compare(const Ant &a1, const Ant &a2)	//개미 구조체들을 정렬할 때 쓰일 함수 
{음 
	if(a1.val == a2.val) return  a1.x < a2.x;	//짐 무게가 같다면 좌표가 빠른 순서대로 정렬 
	return a1.val < a2.val;						//짐 무게가 다르다면 무게순서대로 
}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	
	long long T, test_case;
	
	scanf("%lld",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		long long n;
		scanf("%lld",&n);
		Ant* p = new Ant[n];
		long long* loc = new long long[n];
		for(long long i = 0 ; i < n ; i++)	//원본 위치를 저장해 줄 배열과 개미구조체 배열의 위치 초기화 
		{
			long long ipt;
			scanf("%lld",&ipt);
			p[i].x = ipt;
			loc[i] = ipt;
		}
		for(long long i = 0 ; i < n ; i++)	//개미구조체 배열의 짐 초기화 
		{
			long long ipt;
			scanf("%lld",&ipt);
			p[i].val = ipt;
		}
		sort(p,p+n,compare); //만들어둔 compare함수로 오름차순 정렬 

		for(long long i = 0 ; i < n ; i++)
		{
			if(loc[i] - p[i].x < 0)	//원래 정렬되어 있던 위치배열과 비교해서 개미가 정렬될 시 이동될 거리 합해주기 
			{
				Answer += (( loc[i] - p[i].x ) * (-1));	//절대값 고려 
			}
			else
				Answer += ( loc[i] - p[i].x );
		}
		printf("Case #%d\n",test_case+1);
		printf("%lld\n",Answer);
	}

	return 0;
}
