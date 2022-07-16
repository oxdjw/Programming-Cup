/*
SCPC 1������ ����
������ ��ġ��ǥ�� ���� ���� �ִ� ���̵��� ���� ũ�� ������� �������� ���� �� �� ���̵��� �̵��Ÿ� �ּҰ� �� ���ϱ� 
ó������ tc�� 2���������� ���� �ð��ʰ��� ���� ������ ���� �� ����
����� ���� ����� �����ϴٰ� ���̸� ����ü�� �����ؼ� �ϳ��� ���ϸ� ��� n����
�ڵ带 �ϼ��� �� �ִٰ� ������ �Ǿ� ������ ���� �����Ͽ���
������ ��ġ�� ���� 1~10^9 �����⿡ int�� �ƴ� long long ���� ��� �������ͷ��� �ٲ��־��� 
����� 100/100 �� 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long Answer;

struct Ant
	{
		public:
			long long x;  //������ ��ġ��ǥ 
		    long long val;//������ �� 
		
	};
bool compare(const Ant &a1, const Ant &a2)	//���� ����ü���� ������ �� ���� �Լ� 
{�� 
	if(a1.val == a2.val) return  a1.x < a2.x;	//�� ���԰� ���ٸ� ��ǥ�� ���� ������� ���� 
	return a1.val < a2.val;						//�� ���԰� �ٸ��ٸ� ���Լ������ 
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
		for(long long i = 0 ; i < n ; i++)	//���� ��ġ�� ������ �� �迭�� ���̱���ü �迭�� ��ġ �ʱ�ȭ 
		{
			long long ipt;
			scanf("%lld",&ipt);
			p[i].x = ipt;
			loc[i] = ipt;
		}
		for(long long i = 0 ; i < n ; i++)	//���̱���ü �迭�� �� �ʱ�ȭ 
		{
			long long ipt;
			scanf("%lld",&ipt);
			p[i].val = ipt;
		}
		sort(p,p+n,compare); //������ compare�Լ��� �������� ���� 

		for(long long i = 0 ; i < n ; i++)
		{
			if(loc[i] - p[i].x < 0)	//���� ���ĵǾ� �ִ� ��ġ�迭�� ���ؼ� ���̰� ���ĵ� �� �̵��� �Ÿ� �����ֱ� 
			{
				Answer += (( loc[i] - p[i].x ) * (-1));	//���밪 ��� 
			}
			else
				Answer += ( loc[i] - p[i].x );
		}
		printf("Case #%d\n",test_case+1);
		printf("%lld\n",Answer);
	}

	return 0;
}
