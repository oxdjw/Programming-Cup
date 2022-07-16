/*
SCPC 1������ ���� (�ʾ�) 
ó������ �ش� �ҽ��ڵ�� ���� ���� �� ��ġ �迭 before, ���� �� ��ġ �迭 after, ���ĵ� ��ġ Ȯ�� �迭 isChecked, ���� �迭 val�� �̿��Ͽ�
���� ��Ų �� ������ ���Ͽ� �־��� => ��� n^2�� ��� �ð����� 1.5�� �ѱ�� Answer ������ ��� �����÷ΰ� ���� �κ������� �޾���
�ð��ʰ� ������ �ذ��ϱ� ���� SCPC2022_1.cpp �ڵ�� ���� �����Ͽ� ���� �޾��� 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;	//��� �����÷� �߻� 

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
			if (before.at(i) != after.at(i))	//���� �� �� ��ġ �ε��� ���ؼ� �̵��ؾ��� ���̰� ������ if�� ���� 
			{
				for (register int j = 0; j < n; j++)	//2���������� �ð��� ����� ���� �ҿ��. 
				{
					if (before.at(j) == after.at(j) || isChecked[j])	// ������ ���� �� �ε����� �̵��ؾ��� ���� �� �ε����� ��ü�� �ʿ䰡 ���ų�, �̹� ��ü�Ǿ����� ��üX 
					{
						isChecked[j] = 1;
						continue;
					}
					if (before.at(i) == after.at(j))	//�̵��ؾ��� �ε����̸� 
					{
						isChecked[j] = 1;	//����Ȯ�ι迭�� üũ���ְ� 
						if ((val.at(i) - val.at(j)) > 0)
							Answer += (val.at(i) - val.at(j));
						else
							Answer += ((val.at(i) - val.at(j)) * (-1));	//���밪 ��� 
						break;
					}
				}
			}
		}
		printf("Case #%d\n%d\n",test_case+1,Answer);
	}

	return 0;
}
