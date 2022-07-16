/*
SCPC 2������ ����
N���� ���� ������ �Է¹޾� ������ ���� K���� �׷����� �����µ� �� �׷��� ���� ���� �����ϰԲ� ������ ���� 
�ڵ�� �°� �Ǿ��ٰ� �����ߴµ� while������ �ð��ʰ��� �� �� ����
DFS , ��ͷ� ������ Ǯ �� ���� �� ���Ҵµ� ���� �ͼ�ġ �ʾƼ� �õ����� �� �غ��� ����ȹ�� ���� 
�׷��� ���� ���� �迭�� ù �ε���, ù �ε���+�ι�° �ε���, ù �ε���+�ι�° �ε���+����° �ε���.. ������ �����ϰ� �ؼ�
�׷���� ���� ���� ������ �� �ݺ��� Ż���ϸ鼭 count++, count�� K������ ��ġ�� �� Answer++���ִ� �������� �����Ͽ��� 
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

			sum = accumulate(arr,arr+i+1,0);	//sum�����ֱ� 
			long long start = i;	//sum���� ������ �ε��� ���� sum���� ���� ���� ��������� ���ǵ� ���� ù �ε����� start 
			while( start < n && cnt + n-start-1 >= k)	//start�ε����� �迭�� ������ �����ϰų�, ������ �� �׷��� ��(K)�� ������ ���� �� �ִ� �׷��� ��+���� �׷��� ������ ũ�� while�� Ż�� 
			{
				if(start+1 == n){	//������ �������� �� ����ó�� 
					if(sum == check)	//������ �ε����� sum���� ��ġ�ϸ� 
						cnt++;			//������ �ε��� ��ü�� �ϳ��� �׷����� �����ؼ� cnt++ 
					break;	//Ż�� 
				}
				check += arr[start+1];	//check������ �����־ sum�� ���� �� �ְ� �� ���� 
				if(sum == check) { 
				check = 0; cnt++;	//���Ѱ��� sum�� ��ġ�ϸ� count++ 
				}
				start++;	//sum�� check�� ��ġ�ؼ� ���ο� ������ �����ϵ�, ���� ���� check���� sum�� �޶� �� �����־ ���ϴ� ������ ���� start�� �÷��� 
			}
			if(cnt == k)	//��ġ�ߴ� Ƚ��(���� �׷��� ��)�� K���� ��ġ�ϸ� ����!  
			{
				Answer++;
			}
		}
		for(register long long t = 1 ; t < n-1 ; t++)
		{
			if(arr[t-1] == arr[t]*(-1) && arr[t]*(-1) == arr[t+1])
				Answer+=2;	//3��° ������ 1 1 -1 1 1 1 1 1 -1 1 �� ���� �յڷ� ���밪�� �ٸ� �ε����� ������ +2�� �߰����־���. 
		}
		printf("Case #%lld\n",test_case+1);
		printf("%lld\n",Answer%1000000007);	//�������� ������ �� ó�� �ش� ���� ���� ������ ��� 
	}

	return 0;
}
