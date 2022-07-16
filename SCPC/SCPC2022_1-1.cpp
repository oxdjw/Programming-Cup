/*
SCPC 1번문제 개미 (초안) 
처음에는 해당 소스코드와 같이 정렬 전 위치 배열 before, 정렬 후 위치 배열 after, 정렬된 위치 확인 배열 isChecked, 무게 배열 val을 이용하여
정렬 시킨 후 일일이 비교하여 주었음 => 빅오 n^2로 계속 시간제한 1.5를 넘기고 Answer 변수도 산수 오버플로가 나서 부분점수만 받았음
시간초과 문제를 해결하기 위해 SCPC2022_1.cpp 코드와 같이 수정하여 만점 받았음 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;	//산술 오버플로 발생 

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;

	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int n;
		scanf("%d",&n);
		vector<int> before;
		vector<int> after;
		vector<int> val;
		vector<int> isChecked(n);
		for (register int i = 0; i < n; i++)
		{
			int ipt;
			scanf("%d",&ipt);
			val.push_back(ipt);
		}
		for (register int i = 0; i < n; i++)
		{
			int ipt;
			scanf("%d",&ipt);
			before.push_back(ipt);
			after.push_back(ipt);
		}

		sort(after.begin(), after.end());

		for (register int i = 0; i < n; i++)
		{
			if (before.at(i) != after.at(i))	//정렬 전 후 위치 인덱스 비교해서 이동해야할 개미가 있으면 if문 진입 
			{
				for (register int j = 0; j < n; j++)	//2중포문으로 시간이 상당히 많이 소요됨. 
				{
					if (before.at(j) == after.at(j) || isChecked[j])	// 하지만 정렬 전 인덱스가 이동해야할 정렬 후 인덱스가 교체될 필요가 없거나, 이미 교체되었으면 교체X 
					{
						isChecked[j] = 1;
						continue;
					}
					if (before.at(i) == after.at(j))	//이동해야할 인덱스이면 
					{
						isChecked[j] = 1;	//정렬확인배열에 체크해주고 
						if ((val.at(i) - val.at(j)) > 0)
							Answer += (val.at(i) - val.at(j));
						else
							Answer += ((val.at(i) - val.at(j)) * (-1));	//절대값 고려 
						break;
					}
				}
			}
		}
		printf("Case #%d\n%d\n",test_case+1,Answer);
	}

	return 0;
}
